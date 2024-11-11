#include <DHT.h>

// Define the pin and type of DHT sensor you are using
#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT11 sensor

#define FAN_PIN 7
#define RED_LED 6
#define BLUE_LED 5


// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  pinMode(FAN_PIN, OUTPUT); // Set the fan control pin as output
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(FAN_PIN, LOW); // Start with the fan off

  Serial.begin(9600);
  Serial.println("DHT11 Temperature Sensor\n\n");
  dht.begin();  // Start the DHT sensor
}

void loop() {
  float temperature = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return; 
  }

  // Display the temperature 
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature > 25) { // Example threshold temperature (adjust as needed)
    digitalWrite(FAN_PIN, HIGH); 
    digitalWrite(RED_LED, LOW);  
    digitalWrite(BLUE_LED, HIGH);   
    Serial.println("Fan ON");
  } else {
    digitalWrite(FAN_PIN, LOW); 
    digitalWrite(RED_LED, HIGH);   
    digitalWrite(BLUE_LED, LOW);  
    Serial.println("Fan OFF");
  }

  delay(2000); 
}