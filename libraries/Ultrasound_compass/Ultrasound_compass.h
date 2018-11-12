
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);





 
int trigPins[] = {9,11};    // Trigger
int echoPins[] = {8,10};    // Echo


long duration, cm;
 
void setup_ultrasound() {
  //Define inputs and outputs
  pinMode(trigPins[0], OUTPUT);
  pinMode(echoPins[0], INPUT);
  pinMode(trigPins[1], OUTPUT);
  pinMode(echoPins[1], INPUT);

  Serial.print("2x Ultrasounds starting");
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
/*
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

void displaySensorDetails(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}



void setup_compass(void) 
{
  Serial.println("HMC5883 Compass Starting");
  
  /* Initialise compass*/
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  // displaySensorDetails();
 
}



float heading(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
 
  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when th e magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Declination = -19 minutes
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  
  float declinationAngle = -19*PI/180/60;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
 // Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  
 // delay(500);

  return headingDegrees;
}

/*
void setup(){
    //Serial Port begin
  Serial.begin (9600);
  setup_compass();
  setup_ultrasound();

}

void loop(void){
  delay(500);
  Serial.println(heading());
  
}

 */
