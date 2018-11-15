#include <Motor.h>
#include <Ultrasound_compass.h>


void setup() {
  // put your setup code here, to run once:
 
  AFMS.begin();
  
  //Serial Port begin
  Serial.begin (9600);
  setup_ultrasound();


}


void loop() {
  /*
  collector();
  // set initial distance to wall range
  double range = 20;
  
  int spiral = 1;
  while (spiral < 9) {

    while (spiral % 4 != 0) {
      
      while (distance(0) > range) {
        // sensor 1 or 0
        forward(200); 
       
      }
      
      // when sensor is close to wall, break loop, turn,, repeat loop
      stops();
      left_wo_compass();
      spiral += 1;
     
    }
    
    // once spiral is a multiple of 4, break loop, increase range for next inner loop of spiral
    range += 25;
      
    while (distance(0) > range) {
      forward(200);
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

  
     
