/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_left = AFMS.getMotor(1), *myMotor_right = AFMS.getMotor(2), 
*myMotor_front1 = AFMS.getMotor(3), *myMotor_front2 = AFMS.getMotor(4);


/*
  // front motors running continuosly
  myMotor_front1->setSpeed(100);
  myMotor_front1->run(FORWARD);
  myMotor_front2->setSpeed(100);
  myMotor_front2->run(FORWARD);

  myMotor_left->setSpeed(100);
  myMotor_left->run(FORWARD);
  myMotor_right->setSpeed(100);
  myMotor_right->run(FORWARD);
*/


/*
//MOTOR TEST

void loop() { 
  collector();
  forward(0);
  delay(1000);
  stops();
  delay(1000);
}

*/

void forward(int speed) {
  myMotor_left->setSpeed(speed);
  myMotor_left->run(FORWARD);
  myMotor_right->setSpeed(speed);
  myMotor_right->run(FORWARD);
}

void backward(int speed) {
  myMotor_left->setSpeed(speed);
  myMotor_left->run(BACKWARD);
  myMotor_right->setSpeed(speed);
  myMotor_right->run(BACKWARD);
}

/*
void left(int angle) {
  float new_heading = heading() - angle ;
  while (heading() > new_heading) {
    myMotor_left->setSpeed(100);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(BACKWARD);
  }
}

void right(int angle) {
  float new_heading = heading() - angle ;
  while (heading() > new_heading) {
    myMotor_left->setSpeed(100);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(FORWARD);
  }
}
*/

void stops() {
  myMotor_left->setSpeed(0);
  myMotor_left->run(FORWARD);
  myMotor_right->setSpeed(0);
  myMotor_right->run(BACKWARD);
}

void collector() {
  myMotor_front1->setSpeed(100);
  myMotor_front1->run(FORWARD);
  myMotor_front2->setSpeed(100);
  myMotor_front2->run(FORWARD);
  
}

void left_wo_compass() {
    myMotor_left->setSpeed(100);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(BACKWARD);
    delay(2400);
    stops();

}

void right_wo_compass() {
    myMotor_left->setSpeed(100);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(FORWARD);
    delay(2400);
    stops();

}



/////////////////////

const int trigPin = 8;
const int echoPin = 9;
// defines variables
long duration;
int distance;
void setup() {
  AFMS.begin();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  forward(100);
  collector();
}
void loop() {
  // Clears the trigPin

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if (distance > (240-20)) {
    right_wo_compass();
  }
  else {
    forward(666);
  }


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
  delay(500);        // delay in between reads for stability


}
