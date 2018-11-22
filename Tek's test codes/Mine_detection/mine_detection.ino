


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_left = AFMS.getMotor(1), *myMotor_right = AFMS.getMotor(2), 
*myMotor_front1 = AFMS.getMotor(3), *myMotor_front2 = AFMS.getMotor(4);



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(2, OUTPUT); //yellow
  pinMode(3, OUTPUT); //red
}

// the loop routine runs over and over again forever:
void loop(){
  //mine_detection(float front_distance) {
  // read the input on analog pin A8 to A13:
  int LDR0 = analogRead(A8);
  int LDR1 = analogRead(A9);
  int LDR2 = analogRead(A10);
  int LDR3 = analogRead(A11);
  int LDR4 = analogRead(A12);
  int LDR5 = analogRead(A13);
  // print out the value you read:
  // int LDR_values[6] = {LDR0, LDR1, LDR2, LDR3, LDR4, LDR5};
  //Serial.println(LDR_values);

  int p0 = 0; // 0 = black, +1 = red, -1 = yellow
  int p1 = 0;
  int p2 = 0;
  int p3 = 0;
  int p4 = 0;
  int p5 = 0;

  Serial.print(LDR0); Serial.print(", ");
  Serial.print(LDR1); Serial.print(", ");
  Serial.print(LDR2); Serial.print(", ");
  Serial.print(LDR3); Serial.print(", ");
  Serial.print(LDR4); Serial.print(", ");
  Serial.println(LDR5);



  if (LDR0 < 100) {
    p0 = 1;
    digitalWrite(3, HIGH);
  } //red 185
  // LDR0 logic; calibrate light reading ranges
  int B0 = 300;
  int R0 = 150;
  int Y0 = 50;

  if (LDR0 > B0 && LDR0 < 500) {p0 = 0;} //black 196
  else {if (LDR0 > R0 && LDR0 < B0) {p0 = 1;}} //red 108
  else {if (LDR0 > Y0 && LDR0 < R0) {p0 = -1;}} //yellow 59
 
  // LDR1 logic; calibrate light reading ranges
  int B1 = 150
  int R1 = 80
  int Y1 = 30
  if (LDR0 > B1 && LDR0 < 500) {p1 = 0;} //black 196
  else {if (LDR0 > R1 && LDR0 < B1) {p1 = 1;}} //red 108
  else {if (LDR0 > Y1 && LDR0 < R1) {p1 = -1;}} //yellow 59

  // LDR2 logic; calibrate light reading ranges
  int B2 = 200
  int R2 = 100
  int Y2 = 30
  if (LDR2 > B2 && LDR2 < 500) {p2 = 0;} //black 267
  else if (LDR2 > R2 && LDR2 < B2) {p2 = 1;} //red 156
  else if (LDR2 > Y2 && LDR2 < R2) {p2 = -1;} //yellow 77

  

  delay(100);        // delay in between reads for stability

}
