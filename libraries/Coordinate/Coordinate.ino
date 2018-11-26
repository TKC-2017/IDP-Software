#include <Ultrasound_compass.h>


int * robot_position(int spiral) {
  // coordinate of robot, front centre of LDRs
  static int coord[2];
  int arena_length, arena_width, cw, cl, x, y;
  
  arena_width = 200;
  arena_length = 200;
  cl = 30; // chassis length
  cw = 15; // chassis width

  // spiral ranges from 1 to 8
  // swap 0 and 1 maybe, currently sensor 0 is set as back sensor, 1 as right sensor
  // will need to add/subtract a bit to get coord of centre of chassis
  
  if (spiral % 4 == 1) {
    // facing east
    x = distance(0) + cl;
    y = distance(1) + cw;
  }
  
  if (spiral % 4 == 2) {
    //facing north 
    x = arena_length - distance(1) - cw;
    y = distance(0) + cl;
  }
  
  if (spiral % 4 == 3) {
    // facing west
    x = arena_length - distance(0) - cl;
    y = arena_width - distance(1) - cw;
  }
  
  if (spiral % 4 == 0) {
    // facing south
    x = distance(1) + cw;
    y = arena_width - distance(0) - cl;
  }

  coord[0] = x;
  coord[1] = y;
  
  /*
  int xvalue, yvalue;
  int * coord;
  
  coord = &xvalue;
  *coord = x;
  coord = &yvalue;
  *coord = y;
  */
  return coord;
  
 
}
