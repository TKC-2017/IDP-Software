#include <Motor.h>
#include <Ultrasound_compass.h>



void setup() {
  setup_us();
  setup_m();

  //Serial.print("Start heading: ");
  //Serial.println(current_heading);
}


/*int going = 1;
int north = heading(); // set initial heading as fake north
int current_heading = (heading() - north); // find heading relative to fake north
int Kp = 0.2;*/

void compass_corrected_forward(int spiral){
  int going = 1;
  int a_east = 220;
  int a_north = 280;
  int a_west = 335;
  int a_south = 118;

  int east = a_east - a_north + 360;
  int north = 0;
  int west = a_west - a_north;
  int south = a_south - a_north + 260;
  
  int current_heading = heading()-a_north; // find heading relative to fake north
  int intended_heading = current_heading;
  int error_heading = (current_heading - intended_heading);
  
  int Kp = 0.5;
  
  if (spiral % 4 == 1) {
    // facing east
    intended_heading = east;
  }
  
  else if (spiral % 4 == 2) {
    //facing north 
    intended_heading = north;
  }
  
  else if (spiral % 4 == 3) {
    // facing west
    intended_heading = west;
  }
  
  else if (spiral % 4 == 0) {
    // facing south
    intended_heading = south;
  }

  while (going = 1) {
      error_heading = (current_heading - intended_heading);
      current_heading = heading()-north;
      if(current_heading < 0) {
        current_heading += 360;
      }
      
      if(current_heading > 360) {
        current_heading -= 360;
      }
        
      error_heading = current_heading - intended_heading;
      
      if(error_heading > 180) {
        error_heading -= 360;
      }
      
      if (abs(error_heading) > 10) {
        Kp = 1;
      }
      else {
        Kp = 0.2;
      }
      
      Serial.print(current_heading);
      Serial.print(" - ");
      Serial.println(abs(error_heading));
      
      myMotor_left->setSpeed(100-error_heading * Kp);
      myMotor_left->run(BACKWARD);
      myMotor_right->setSpeed(100+error_heading * Kp);
      myMotor_right->run(BACKWARD);
  }
  }

/*void loop() { // compass path correction
  int going = 1;
  int north = heading(); // set initial heading as fake north
  int current_heading = (heading() - north); // find heading relative to fake north
  int intended_heading = 0;
  int error_heading = (current_heading - intended_heading);

  Serial.println(current_heading);

  int Kp = 0.2;
  collector();
  forward(100);
  delay(1000);
  
  while (going = 1) {
    current_heading = heading() - north;
    error_heading = current_heading - intended_heading;
    Serial.println(error_heading);
    if (current_heading > intended_heading){
     
      if (error_heading < 180){
      myMotor_left->setSpeed(100-error_heading * Kp);
      myMotor_left->run(FORWARD);
      myMotor_right->setSpeed(100);
      myMotor_right->run(FORWARD);
      }
      else if(error_heading > 180){
      myMotor_left->setSpeed(100);
      myMotor_left->run(FORWARD);
      myMotor_right->setSpeed(100-error_heading * Kp);
      myMotor_right->run(FORWARD);
      }
    }
    forward(100);
    }
}*/

/*
void loop() { // compass path correction
  int going = 1;
  int north = heading(); // set initial heading as fake north
  int current_heading = 0; // find heading relative to fake north
  int intended_heading = 0;
  int error_heading = (current_heading - intended_heading);

  Serial.println(current_heading);

  int Kp = 1;
  collector();
  forward(100);
  delay(1000);
  
  
  while (going = 1) {
    current_heading = heading()-north;
    if(current_heading < 0) {
      current_heading += 360;
    }
    
    if(current_heading > 360) {
      current_heading -= 360;
    }
      
    error_heading = current_heading - intended_heading;
    
    if(error_heading > 180) {
      error_heading -= 360;
    }
    
    if (abs(error_heading) > 10) {
      Kp = 1;
    }
    else {
      Kp = 0.2;
    }
    
    Serial.print(current_heading);
    Serial.print(" - ");
    Serial.println(abs(error_heading));
    
    myMotor_left->setSpeed(100-error_heading * Kp);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(100+error_heading * Kp);
    myMotor_right->run(BACKWARD);
    }

    
}
*/


/*
 *     if (error_heading < 0){
    myMotor_left->setSpeed(100-(abs(error_heading) * Kp));
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(FORWARD);
    }
    else if(error_heading > 0)
        else {backward(100);
    }{*/
