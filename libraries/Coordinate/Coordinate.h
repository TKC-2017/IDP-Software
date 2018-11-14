void setup() {
  // put your setup code here, to run once:

}

void robot_position(int spiral) {
  // coordinate of robot

  // position of robot
  float arena_length, arena_width,x, y;
  vector<float> coord
  arena_width = 200;
  arena_length = 200;

  // spiral ranges from 1 to 8
  // swap 0 and 1 maybe, currently sensor 0 is set as back sensor, 1 as right sensor
  // will need to add/subtract a bit to get coord of centre of chassis
  
  if (spiral % 4 == 1) {
    // facing east
    x = distance(0);
    y = distance(1);
  }
  
  else if (spiral % 4 == 2) {
    facing north 
    x = arena_length - distance(1);
    y = distance(0);
  }
  
  else if (spiral % 4 == 3) {
    // facing west
    x = arena_length - distance(0);
    y = arena_width - distance(1);
  }
  
  else if (spiral % 4 == 0) {
    // facing south
    x = distance(1);
    y = arena_width - distance(0);
  }

  coord.push_back(x);
  coord.push_back(y);
  
  return coord
  


  


 
}
