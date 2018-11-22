#include <Ultrasound_compass.h>
#include <Motor.h>
#include <Mine_detect.h>

void setup() {
  // put your setup code here, to run once:
  setup_m();
  setup_us();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
}



void loop() {
  
  // set initial distance to wall range
  float range = 20;
  float arena_length = 180;
  int going = 1;
  int spiral = 1;
  
  while (spiral < 8) {
    // adjust max number of spirals needed
    //while (heading() < 160 && heading() > 200) {
    // robot is not facing south, also if on default path

      while (going == 1) {
      
      while (detect() == 0) {
        //while no mines have been detected
        int go = 0;
        // reset go to 0, cancel override
        while (spiral % 4 != 0) {
          while (arena_length - distance(0) > range) {
            // sensor 1 or 0
            forward(100);
          }
          // when close to wall, stops, turns
          stops();
          left_wo_compass();
          //left(90);
          spiral += 1;
          // adjust coordinates based on sensor positions on robot
        }
        
        // once spiral is a multiple of 4, break loop, increase range for next inner loop of spiral
        range += 25;
        while (arena_length - distance(0) > range) {
          forward(100);
        }
        stops();        
        //left(90); 
        left_wo_compass();
        spiral += 1;
      }
      
      // when detect returns list of numbers based on colours of mines detected
      if (max(max(detect[0], detect[1]), detect[2]) == 1) {
        // if max reading is yellow mine
        // might need to add mine count
        forward(100);
      }
      if (max(max(detect[0], detect[1]), detect[2]) == 2) {
        // if max reading is red mine
        // need to add checking for coords of other mines
        // int go = 1
        // set go = 1 to override mine detection to prevent robot getting stuck in loop when reversing over mine
        backward(100);
        delay(1000);
        // either use delays or range sensors to get back on default path
        right_wo_compass();
        forward(100);
        delay(1000);
        stops();
        left_wo_compass();
        forward(100);
        delay(3000);
        stops();
        left_wo_compass();
        forward(100);
        delay(1000);
        stops();
        right_wo_compass();
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
