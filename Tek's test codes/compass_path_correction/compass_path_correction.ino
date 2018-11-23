#include <Motor.h>
#include <Ultrasound_compass.h>


void setup() {
  setup_us();
  setup_m();

  int north = heading(); // set initial heading as fake north
  int current_heading = heading() - north; // find heading relative to fake north
  int intended_heading = 0;
  int error_heading = current_heading - intended heading;
  Serial.print("Start heading: ");
  Serial.println(current_heading);
  forward(100);
}

void loop() { // compass path correction
  current_heading = heading() - north;
  error_heading = current_heading - intended_heading;
  while (current_heading > intended_heading){
    if (error_heading < 180){
    myMotor_left->setSpeed(0);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(FORWARD);
    }
  }
  while (current_heading > intended_heading){
    if (error_heading > 180){
    myMotor_left->setSpeed(100);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(0);
    myMotor_right->run(FORWARD);
    }
  }
  forward(100)
}
