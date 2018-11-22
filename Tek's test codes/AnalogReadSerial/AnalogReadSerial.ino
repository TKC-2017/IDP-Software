/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(A8);
  // print out the value you read:
  Serial.print("LDR0: ");
  Serial.println(sensorValue0);
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A9);
  // print out the value you read:
  Serial.print("LDR1: ");
  Serial.println(sensorValue1);
  // read the input on analog pin 0:
  int sensorValue2 = analogRead(A10);
  // print out the value you read:
  Serial.print("LDR2: ");
  Serial.println(sensorValue2);
  delay(1);        // delay in between reads for stability
}
