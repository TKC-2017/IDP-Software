#include <Ultrasound_compass.h>
#include <Motor.h>
 // compiling error - check
/* 
 
Arduino: 1.8.7 (Mac OS X), Board: "Arduino/Genuino Mega or Mega 2560, ATmega2560 (Mega 2560)"

In file included from /Users/annavuolo/Desktop/IDP-Software/Compass_Sensor_test/Compass_Sensor_test.ino:1:0:
/Users/annavuolo/Desktop/IDP-Software/libraries/Ultrasound_compass/Ultrasound_compass.h:16:32: fatal error: Adafruit_HMC5883_U.h: No such file or directory
compilation terminated.
exit status 1
Error compiling for board Arduino/Genuino Mega or Mega 2560.

This report would have more information with
"Show verbose output during compilation"
option enabled in File -> Preferences.

*/


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  // compass test - correct robot orientation to North
  if (heading() < 180) {
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
  float range = 20;
  if (distance(1) > range) {
    // sensor is 1 or 0
    forward(100); 
  }
  else {
    stops();
  }
      


}
