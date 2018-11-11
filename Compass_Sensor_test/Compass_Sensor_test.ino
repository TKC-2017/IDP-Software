#include <Ultrasound_compass.h>
#include <Motor.h>
 // compiling error - check

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  // compass test - correct robot orientation to North
  if (heading < 180) {
    while (heading() < 180) {
      left(); 
    }
  }
  else {
    while (heading() > 180) {
      right(); 
    }
  }


  // ultrasound range test - stop when less than 20cm from wall, no mines in the way
  range = 20
  if (distance() > range) {
    forward(100); 
  }
  else {
    stops();
  }
      


}
