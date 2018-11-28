#include <Motor.h>
#include <Wire.h>

#define ADDRESS 0x21

void setup(){
  Wire.begin();
  Serial.begin(9600);
  myMotor_left->setSpeed(100);
  myMotor_left->run(BACKWARD);
  myMotor_right->setSpeed(100);
  myMotor_right->run(FORWARD);
  while(!Serial);
  calibrate();
}

void loop(){
  //left_wo_compass();
  //delay(20000);
  //stops();
  //delay(100000000);
}

void calibrate(){
  Serial.println("Calibration Mode");
  delay(1000);  //1 second before starting
  Serial.println("Start");

  Wire.beginTransmission(ADDRESS);
  Wire.write(0x43);
  Wire.endTransmission();
  for(int i=0;i<15;i++){        //15 seconds
   Serial.println(i);
   delay(1000);
   Wire.write;
  }
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x45);
  Wire.endTransmission();
  Serial.println("done");

}
