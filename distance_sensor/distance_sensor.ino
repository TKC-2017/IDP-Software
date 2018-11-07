#include <Adafruit_LSM303.h>
#include <Adafruit_LSM303_U.h>

#include <Wire.h>

#include <Adafruit_Sensor.h>


/*
compass requires https://github.com/adafruit/Adafruit_Sensor, https://github.com/adafruit/Adafruit_LSM303DLHC
librarys to work.
 */


 /*
int trigPins[] = {9,11};    // Trigger
int echoPins[] = {8,10};    // Echo


long duration, cm;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPins[0], OUTPUT);
  pinMode(echoPins[0], INPUT);
  pinMode(trigPins[1], OUTPUT);
  pinMode(echoPins[1], INPUT);
}
 
float distance(int sensor) {
  // sensor is 1 or 0
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  int trigPin = trigPins[sensor];
  int echoPin = echoPins[sensor];

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 291;     // Divide by 29.1 or multiply by 0.0343

  // Print distance in cm
  return Serial.print(cm);
  
  
  //Serial.print("cm");
  //Serial.println();
  
}

void loop(){
  delay(1000);
  Serial.print(distance(0));
  Serial.println();
  delay(1000);
  Serial.print(distance(1));
  Serial.print("\n");
  
  Serial.println();
  
}

*/
void setup(void) 
9.{
10.  Serial.begin(9600);
11.  Serial.println("Magnetometer Test"); Serial.println("");
12.  
13.  /* Initialise the sensor */
14.  if(!mag.begin())
15.  {
16.    /* There was a problem detecting the LSM303 ... check your connections */
17.    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
18.    while(1);
19.  }
20.}




void loop(){
  /* Get a new sensor event */ 
sensors_event_t event; 
mag.getEvent(&event);
 
float Pi = 3.14159;
 
// Calculate the angle of the vector y,x
float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
 
// Normalize to 0-360
if (heading < 0)
{
   heading = 360 + heading;
}
Serial.print("Compass Heading: ");
Serial.println(heading);
delay(500);
}

}
