//#include <Coordinate.h>
//#include <Ultrasound_compass.h>
//#include <Motor.h>
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
  // put this is setup? and then get rid of while (going == 1)
  float range = 20;
  float arena_length = 180;
  int going = 1;
  int spiral = 1;
  //int redmines[] = {};
  
  while (going == 1) {
    
    //while (heading() < 160 && heading() > 200) { //robot is not facing south

    while (spiral < 8) {
    // adjust max number of spirals
      
      //while (detect() == 0) {
        //while no mines have been detected !!this might not work, instead used if detect == 2 later (see below)
        int go = 0;
        // reset go to 0, cancel override
        while (spiral % 4 != 0) {
          while (arena_length - distance(0) > range) {
            // sensor 1 or 0
            forward(100);
            /*
            if (detect() == 2) {
              //mine_coord = robot_position(spiral) +- a bit, depending on LDRs triggered
              //redmines.push_back(mine_coord);
              avoid(3000); // avoidance route, moves away from mine for 3000 ms
              // need to check for red mines in area to the right, then adjust the distance at which
              // the robot will move to avoid the current mine
            }
             */
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
          /*
          if (detect() == 2) {
            //mine_coord = robot_position(spiral) +- a bit, depending on LDRs triggered
            //redmines.push_back(mine_coord);
            avoid(3000);
          }
            */
        }
        stops();        
        //left(90); 
        left_wo_compass();
        spiral += 1;
      }
    }
  //}
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
