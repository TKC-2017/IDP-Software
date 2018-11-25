#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor_left = AFMS.getMotor(2), *myMotor_right = AFMS.getMotor(1), 
*myMotor_front1 = AFMS.getMotor(3), *myMotor_front2 = AFMS.getMotor(4);


void setup_m() {
  AFMS.begin();
}

/*
//MOTOR TEST

void loop() { 
  collector();
  forward(00);
  delay(1000);
  stops();
  delay(1000);
}
*/


void backward(int speed) {
  myMotor_left->setSpeed(speed);
  myMotor_left->run(FORWARD);
  myMotor_right->setSpeed(speed);
  myMotor_right->run(FORWARD);
}

void forward(int speed) {
  myMotor_left->setSpeed(speed);
  myMotor_left->run(BACKWARD);
  myMotor_right->setSpeed(speed);
  myMotor_right->run(BACKWARD);
}

/*
void left(int angle) {
  // using compass to turn
  float new_heading = heading() - angle ;
  while (heading() > new_heading) {
    myMotor_left->setSpeed(100);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(BACKWARD);
  }
}

void right(int angle) {
  // using compass to turn
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

void right_wo_compass() {
  myMotor_left->setSpeed(100);
  myMotor_left->run(FORWARD); 
  myMotor_right->setSpeed(100);
  myMotor_right->run(BACKWARD);
  delay(2400);
  stops();
}

void left_wo_compass() {
  myMotor_left->setSpeed(100);
  myMotor_left->run(BACKWARD);
  myMotor_right->setSpeed(100);
  myMotor_right->run(FORWARD);
  delay(2400);
  stops();
}

void avoid(int faraway) {
  // avoidance route, with delay = faraway (in ms) to determine how far from mine to go
  backward(100);
  delay(1000);
  stops();
  // either use delays or range sensors to get back on default path
  right_wo_compass();
  forward(100);
  delay(faraway);
  stops();
  left_wo_compass();
  forward(100);
  delay(3000);
  stops();
  left_wo_compass();
  forward(100);
  delay(faraway);
  stops();
  right_wo_compass();
}
