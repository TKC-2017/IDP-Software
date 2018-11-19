#include <Motor.h>
#include <Ultrasound_compass.h>

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  Serial.begin (9600);
  setup_ultrasound();
}

void loop() {
  
  // put your main code here, to run repeatedly:
  float range = 10;
  if (distance(0) > range) {
    // sensor 1 or 0
    forward(100); 
  }
  else {
    stops();
  }
   
}
