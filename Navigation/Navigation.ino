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
  pinMode(0,INPUT);
}



void loop() {
  /*
  // push button for start
  while (digitalRead(0) == LOW) {
    Serial.print(digitalRead(0));
    stops();
  }
  */
  stops();
  delay(3000);
  
  // set initial distance to wall range
  float range = 75;
  float arena_length = 240;
  int spiral = 1;
  int redmines[100];
  int red_counter = 0;
  int a_east = heading();
  

  if (spiral == 1) {
   
        // move out of start box
        forward(100);
        delay(1000);
        stops();
        left_wo_compass();
        forward(100);
        delay(2500);
        stops();
        right_wo_compass();
        collector();
    }

    while (spiral < 16) {
    // adjust max number of spirals
        
        
        while (spiral % 4 != 0) {
          if ((arena_length - distance(0)) > range) {
            // sensor 1 or 0
            //forward(200);                                       //calibrate
            compass_corrected_forward(spiral, a_east);
            Serial.print(detect());
            if (detect() == 1) { 
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
              if (distance(0) > 160) {
                avoid2(3500);
              }
              else {
                avoid(3500); // avoidance route, moves away from mine for 3000 ms
              }
              // need to check for red mines in area to the right, then adjust the distance at which
              // the robot will move to avoid the current mine
            }
             
          }
          else {
            delay(200); // make sure it's actually reached the end, due to jumps in us
            if ((arena_length - distance(0)) < range) {
              stops();
              left_wo_compass();
              //left(90);
              spiral += 1;
            }
          }
          // when close to wall, stops, turns
          
          
        }
        // once spiral is a multiple of 4, break loop, increase range for next inner loop of spiral
        range = range + 25;
        if ((arena_length - distance(0)) > range) {
          //forward(100);                                       //calibrate
          compass_corrected_forward(spiral, a_east);
          
          if (detect() == 1) {
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
            if (distance(0) > 160) {
                avoid2(3500);
              }
            else {
              avoid(3500); // avoidance route, moves away from mine for 3000 ms
            }
            // need to check for red mines in area to the right, then adjust the distance at which
            // the robot will move to avoid the current mine
          } 
         
        }
        else {
            delay(200); // make sure it's actually reached the end, due to jumps in ultrasound
            if ((arena_length - distance(0)) < range) {
              stops();
              left_wo_compass();
              //left(90);
              spiral += 1;
            }
        }
    }
  
    //end sequence
    // find orientation of robot at end of spiral path

    stops();

    // adjust orientation so faces south
    
    if (spiral % 4 == 1) { // facing east
      right_wo_compass();
      right_wo_compass();
    }
    if (spiral % 4 == 2) { // facing north
      left_wo_compass();
    }
    if (spiral % 4 == 0) { // facing south
      right_wo_compass();
    }

    forward(200);                                       //calibrate
    delay(15000);
    stops();
    backward(100);
    delay(5000);
    right_wo_compass();
    
    while (distance(0) > 15) {
      backward(70);  
    }
    stops();
   
delay(1000000000);    
}
     

    
    /*
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
    
  
