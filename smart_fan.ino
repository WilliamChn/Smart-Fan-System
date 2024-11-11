#include <DHT.h>

// Define the pin and type of DHT sensor you are using
#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT11 sensor

#define FAN_PIN 7


// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  pinMode(FAN_PIN, OUTPUT); // Set the fan control pin as output
  digitalWrite(FAN_PIN, LOW); // Start with the fan off

  Serial.begin(9600);
  Serial.println("DHT11 Humidity & Temperature Sensor\n\n");
  dht.begin();  // Start the DHT sensor
}

void loop() {
  // Reading temperature and humidity data
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return; // Skip the rest of the loop if there's an error
  }

  // Display the temperature and humidity values
  Serial.print("Current humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature > 25) { // Example threshold temperature (adjust as needed)
    digitalWrite(FAN_PIN, HIGH); // Turn the fan ON
    Serial.println("Fan ON");
  } else {
    digitalWrite(FAN_PIN, LOW); // Turn the fan OFF
    Serial.println("Fan OFF");
  }

  delay(2000); // Wait 2 seconds before taking another reading
}