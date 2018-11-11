#ifndef Motor_h
#define Motor_h

#ifndef ARDUINO
#include <stdint.h>
#elif ARDUINO >= 100
#include "Arduino.h"
#include "Print.h"
#else
#include "WProgram.h"
#endif


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_left = AFMS.getMotor(1), *myMotor_right = AFMS.getMotor(2), 
*myMotor_front1 = AFMS.getMotor(3), *myMotor_front2 = AFMS.getMotor(4);

 void setup() {
  // put your setup code here, to run once:

AFMS.begin();
  // front motors running continuosly
  myMotor_front1->setSpeed(0);
  myMotor_front1->run(FORWARD);
  myMotor_front2->setSpeed(0);
  myMotor_front2->run(FORWARD);

  myMotor_left->setSpeed(0);
  myMotor_left->run(FORWARD);
  myMotor_right->setSpeed(0);
  myMotor_right->run(FORWARD);


}

void loop() {
  // put your main code here, to run repeatedly:
collector();
forward(0);
delay(1000);
stops();
delay(1000);

}

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

void left() {
  new_heading = heading - 90 ;
  while (heading > new_heading) {
    myMotor_left->setSpeed(100);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(BACKWARD);
}}

void right() {
  new_heading = heading + 90 ;
  while (heading < new_heading) {
    myMotor_left->setSpeed(100);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(FORWARD);
}}

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
