//#include <Coordinate.h>
//#include <Ultrasound_compass.h>
//#include <Motor.h>
//#include <Mine_detect.h>

#include <Everything.h>

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
  int redmines[100];
  int red_counter = 0;
  
  while (going == 1) {

    while (spiral < 8) {
    // adjust max number of spirals
    
        while (spiral % 4 != 0) {
          while ((arena_length - distance(0)) > range) {
            // sensor 1 or 0
            forward(100);
            
            if (detect() == 2) { 
              int *p;
              p = robot_position(spiral);
              int mine_coord[2];
              mine_coord[0] = *p ;
              mine_coord[1] = *(p+1) ; // +- a bit, depending on LDRs triggered
              redmines[red_counter] = mine_coord;
              Serial.print(mine_coord[0]);
              Serial.print(", ");
              Serial.print(mine_coord[1]);
              Serial.println();
              red_counter += 1;
              avoid(3000); // avoidance route, moves away from mine for 3000 ms
              // need to check for red mines in area to the right, then adjust the distance at which
              // the robot will move to avoid the current mine
            }
             
          }
          // when close to wall, stops, turns
          stops();
          left_wo_compass();
          //left(90);
          spiral += 1;
          
        }
        // once spiral is a multiple of 4, break loop, increase range for next inner loop of spiral
        range += 25;
        while ((arena_length - distance(0)) > range) {
          forward(100);
          
          if (detect() == 2) {
            // store cordinate of red mine
            int *p;
            p = robot_position(spiral);
            int mine_coord[2];
            mine_coord[0] = *p ;
            mine_coord[1] = *(p+1) ; // +- a bit, depending on LDRs triggered
            redmines[red_counter] = mine_coord;
            Serial.print(mine_coord[0]);
            Serial.print(", ");
            Serial.print(mine_coord[1]);
            Serial.println();
            red_counter += 1;
            avoid(3000); // avoidance route, moves away from mine for 3000 ms
            // need to check for red mines in area to the right, then adjust the distance at which
            // the robot will move to avoid the current mine
          }   
        }
        stops();        
        //left(90); 
        left_wo_compass();
        spiral += 1;
      }
/*
    //end sequence
    // find orientation of robot at end of spiral path
    
    rp = robot_position();
    // iterate through list of redmines from y=0 to y=rp[1] and from x=rp[0]-30 to x=rp[0]
    
    for (i=0; i<30; i+=1) {
      
      if (redmines[i][1] < rp[1]) { 
        // if red mines exist below y coord, check if within x coord
        if ((redmines[i][0] > (rp[0]-30)) && (redmines[i][0] < rp[0])) { 
          // if red mines in area below robot, need to check alternate route
          //check for y coord area above robot
          if (redmines[i][1] > rp[1]) {
            if ((redmines[i][0] > (rp[0]-30)) && (redmines[i][0] < rp[0])) {
              // if red mines in area above robot, check alternate route
              // check for x coord area to right of robot
              if (redmines[i][0] > rp[0]) {
                if (redmines[i][1] 
              }
            }
          }
        }
        else {
          // safe to take this route, down and left
          right_wo_compass();
          forward(100);
          if ((arena_length - distance(0)) < 40) {
            stops();
            right_wo_compass();
            forward();
            if ((arena_length - distance(0)) < 40) {
              stops();
              right_wo_compass();
            }
          }
        }
      }
      else {
        // red mines don't exist below y coord
        if ((redmines[i][0] > (rp[0]-30)) && (redmines[i][0] < rp[0])) {
          // red mines exist within x coord range
        }
      }
    }
    for (int i = 0; i < rp[1] ; i += 1) {
      if 
      
    }
    area = // 
    // check four routes for red mines
    // 

    */
    }
}
