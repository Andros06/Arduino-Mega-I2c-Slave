#include <Arduino.h>
#include <Wire.h>

// Include the required Wire library for I2C<br>#include <Wire.h>
int x = 0;

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  Serial.println(x);
}

void setup() {
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  Serial.begin(9600);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}

void loop() {
  Wire.onReceive(receiveEvent);
}