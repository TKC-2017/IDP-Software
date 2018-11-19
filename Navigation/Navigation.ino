#include <Ultrasound_compass.h>
#include <Motor.h>


void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
}



void loop() {
  // put your main code here, to run repeatedly:
  
  // set initial distance to wall range
  float range = 20;
  float arena_length = 350;
  
  while (not at end condition, robot not at centre) {
  
    if int default_path = 0 {
    // follows default path
    // need to correct variable for mine detection
      
      int spiral = 1
      while (spiral < 8) {
      // adjust max number of spirals needed
      //while (heading() < 160 && heading() > 200) {
      // robot is not facing south, also if on default path

        while (spiral % 4 != 0) {
          if (arena_length - distance(0) > range) {
            // sensor 1 or 0
            forward(100); }
          else {
            stops();
            left(90);
            spiral += 1
            // adjust coordinates based on sensor positions on robot
           }
         }
       
      
        // robot is facing south
        range += 25;
        if (arena_length - distance(0) > range) {
          forward(100);
        }
        else {
           stops();        
           left(90); 
         }
      }
       
    }
  }
}

 /*
    else {
    // if mine detected
    // need to change variables / use sensor code
      if (mine = yellow) {
        stops();
        delay(3000);
        forwards(1000); }
      else {
        stops(3000);
        if ( check(current_position) = safe) {
          // create function that checks for red mines on outside of spiral 
          // at diamater from current position
          // write separately?
          right();
          forward(100);
          delay(2000); // either use delay or range sensors for forward distance
          stops();
          left();
          forward(100);
          delay(2000); // as above
          stops();
          left();
          forward(100);
          delay(2000); // as above
          stops();
          right();
        }
      }
    }

  // end sequence

  */
