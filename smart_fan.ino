#include <dht.h>

#define tempsensor 2       

#define FAN 7
#define RED_LIGHT 6
#define BLUE_LIGHT 5

dht DHT;

void setup() {

  pinMode(FAN, OUTPUT); 

  pinMode(RED_LIGHT, OUTPUT);
  pinMode(BLUE_LIGHT, OUTPUT);
  digitalWrite(FAN, LOW);

  Serial.begin(9600);
  
}

void loop() {

  DHT.read11(tempsensor);

  float cel = DHT.temperature;
  float temperature = (cel * 9.0 / 5.0) + 32.0;

  
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("°F");

  if (temperature > 72) { // temperary threshold set 
    digitalWrite(FAN, HIGH); 
    digitalWrite(RED_LIGHT, LOW);  
    digitalWrite(BLUE_LIGHT, HIGH);   
    Serial.println("Fan ON");
  } else {
    digitalWrite(FAN, LOW); 
    digitalWrite(RED_LIGHT, HIGH);   
    digitalWrite(BLUE_LIGHT, LOW);  
    Serial.println("Fan OFF");
  }

  delay(2000); 
}
