#include <Arduino.h>
#include <Wire.h>

// Lager variabler for x og y
int x = 0;
int y = 0;

// Klassifiserer en funksjon for meldings event
void receiveEvent(int bytes);
void requestEvent();

void setup() {
  // Starter I2C Bus som Slave på address 9
  Wire.begin(9); 

  // Starter Seriel med pc
  Serial.begin(9600);

  // Kopler meldings event ilag med wire.onreceive
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // Setter x verdi til verdi fra master melding
}

void requestEvent() {
  y = 2 * x;
  Wire.write(y);
}

void loop() {
  Serial.print("Fekk X verdi fra uno: ");
  Serial.println(x);

  Serial.print("Sender y verdi til uno: ");
  Serial.println(y);
  delay(500);
}