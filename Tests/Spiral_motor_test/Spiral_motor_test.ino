#include <Motor.h>
#include <Ultrasound_compass.h>


void setup() {
  
  setup_us();
  setup_m();
  


}


void loop() {
  
  stops();
  /*
  delay(000000);
  //collector();
  // set initial distance to wall range
  int range = 20;
  
  int spiral = 1;
  while (spiral < 9) {
  Serial.print(distance(0));
    while (spiral % 4 != 0) {
      
      while (180-distance(0) > range ) {
        // sensor 1 or 0
        forward(100); 
       
      }
      
      // when sensor is close to wall, break loop, turn,, repeat loop
      stops();
      left_wo_compass();
      spiral += 1;
     
    }
    
    // once spiral is a multiple of 4, break loop, increase range for next inner loop of spiral
    range += 25;
      
    while (180-distance(0) > range ) {
      forward(100);
    }
    // when sensor close to wall, break loop, turn, repeat loop from top
    stops();
    left_wo_compass();
    spiral += 1;
    }

  // when spiral reaches 8, stop
  stops();
  delay(1000000);
  */
}

  
     
