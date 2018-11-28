//#include <Motor.h>
#include <Ultrasound_compass_Nov23.h>

void setup() {
  // put your setup code here, to run once:
  setup_us();
  //setup_m();
}

  void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(heading());
  delay(200);
}
