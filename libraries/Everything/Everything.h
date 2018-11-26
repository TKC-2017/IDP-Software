//
//  Everything.h
//  
//
//  Created by Anna Vuolo on 26/11/2018.
//

#ifndef Everything_h
#define Everything_h


#endif /* Everything_h */


//MOTOR

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor_left = AFMS.getMotor(2), *myMotor_right = AFMS.getMotor(1),
*myMotor_front1 = AFMS.getMotor(3), *myMotor_front2 = AFMS.getMotor(4);


void setup_m() {
    AFMS.begin();
}

/*
 //MOTOR TEST
 
 void loop() {
 collector();
 forward(00);
 delay(1000);
 stops();
 delay(1000);
 }
 */


void backward(int speed) {
    myMotor_left->setSpeed(speed);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(speed);
    myMotor_right->run(FORWARD);
}

void forward(int speed) {
    myMotor_left->setSpeed(speed);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(speed);
    myMotor_right->run(BACKWARD);
}

/*
 void left(int angle) {
 // using compass to turn
 float new_heading = heading() - angle ;
 while (heading() > new_heading) {
 myMotor_left->setSpeed(100);
 myMotor_left->run(FORWARD);
 myMotor_right->setSpeed(100);
 myMotor_right->run(BACKWARD);
 }
 }
 
 void right(int angle) {
 // using compass to turn
 float new_heading = heading() - angle ;
 while (heading() > new_heading) {
 myMotor_left->setSpeed(100);
 myMotor_left->run(BACKWARD);
 myMotor_right->setSpeed(100);
 myMotor_right->run(FORWARD);
 }
 }
 */

void stops() {
    myMotor_left->setSpeed(0);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(0);
    myMotor_right->run(BACKWARD);
}

void collector() {
    myMotor_front1->setSpeed(100);
    myMotor_front1->run(FORWARD);
    myMotor_front2->setSpeed(100);
    myMotor_front2->run(FORWARD);
}

void right_wo_compass() {
    myMotor_left->setSpeed(100);
    myMotor_left->run(FORWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(BACKWARD);
    delay(2400);
    stops();
}

void left_wo_compass() {
    myMotor_left->setSpeed(100);
    myMotor_left->run(BACKWARD);
    myMotor_right->setSpeed(100);
    myMotor_right->run(FORWARD);
    delay(2400);
    stops();
}

void avoid(int faraway) {
    // avoidance route, with delay = faraway (in ms) to determine how far from mine to go
    backward(100);
    delay(1000);
    stops();
    // either use delays or range sensors to get back on default path
    right_wo_compass();
    forward(100);
    delay(faraway);
    stops();
    left_wo_compass();
    forward(100);
    delay(3000);
    stops();
    left_wo_compass();
    forward(100);
    delay(faraway);
    stops();
    right_wo_compass();
}



// ULTRASOUND

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);






int trigPins[] = {13,11};    // Trigger
int echoPins[] = {12,10};    // Echo


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
    cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    
    // Print distance in cm
    return cm;
    
    
    //Serial.print("cm");
    //Serial.println();
    
}
/*
 void loop(){
 delay(1000);
 Serial.print(distance(0));
 Serial.println();
 delay(1000);
 /*Serial.print(distance(1));
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

void setup_us(){
    //Serial Port begin
    Serial.begin (9600);
    //setup_compass();
    setup_ultrasound();
    
}

/*
 void loop(void){
 delay(500);
 //Serial.println(heading());
 Serial.print(distance(0));
 */



// COORDINATE

int * robot_position(int spiral) {
    // coordinate of robot, front centre of LDRs
    static int coord[2];
    int arena_length, arena_width, cw, cl, x, y;
    
    arena_width = 200;
    arena_length = 200;
    cl = 30; // chassis length
    cw = 15; // chassis half width
    
    // spiral ranges from 1 to 8
    // swap 0 and 1 maybe, currently sensor 0 is set as back sensor, 1 as right sensor
    // will need to add/subtract a bit to get coord of centre of chassis
    
    if (spiral % 4 == 1) {
        // facing east
        x = distance(0) + cl;
        y = distance(1) + cw;
    }
    
    if (spiral % 4 == 2) {
        //facing north
        x = arena_length - distance(1) - cw;
        y = distance(0) + cl;
    }
    
    if (spiral % 4 == 3) {
        // facing west
        x = arena_length - distance(0) - cl;
        y = arena_width - distance(1) - cw;
    }
    
    if (spiral % 4 == 0) {
        // facing south
        x = distance(1) + cw;
        y = arena_width - distance(0) - cl;
    }
    
    coord[0] = x;
    coord[1] = y;
    
    /*
     int xvalue, yvalue;
     int * coord;
     
     coord = &xvalue;
     *coord = x;
     coord = &yvalue;
     *coord = y;
     */
    return coord;
    
    
}


// MINE_DETECT

// functions which return colour under each LDR

int LDR0() {
    // when mine detected, stops, forwards in small steps, stops, returns number based on colour
    
    int LDR0 = analogRead(A8);
    while (LDR0 > 300 ) {
        return 0;
    }
    if (LDR0 < 300) {
        stops();
        delay(3000);
        int readings[5];
        int min_reading = LDR0;
        //obtain min value to identify colour accurately
        for (int t = 1; t < 5; t = t + 1) {
            forward(10);
            delay(400);
            readings[t] = LDR0;
            if (readings[t] < min_reading) {
                min_reading = readings[t];
            }
        }
        stops();
        
        // return colour based on min reading
        if (min_reading < 300 && min_reading > 150) {
            return 2; //red
        }
        if (min_reading < 150) {
            return 1; //yellow
        }
        else {
            return 3; //uncertain
        }
    }
}


int LDR1() {
    // when mine detected, stops, forwards in small steps, stops, returns number based on colour
    
    int LDR1 = analogRead(A9);
    while (LDR1 > 150 ) {
        return 0;
    }
    if (LDR1 < 150) {
        stops();
        delay(3000);
        int readings[10];
        int min_reading = LDR1;
        //obtain min value to identify colour accurately
        for (int t = 1; t < 5; t = t + 1) {
            forward(10);
            delay(400);
            readings[t] = LDR1;
            if (readings[t] < min_reading) {
                min_reading = readings[t];
            }
        }
        stops();
        
        // return colour based on min reading
        if (min_reading < 150 && min_reading > 80) {
            return 2;
        }
        if (min_reading < 80) {
            return 1;
        }
        else {
            return 3;
        }
    }
}


int LDR2() {
    // when mine detected, stops, forwards in small steps, stops, returns number based on colour
    
    int LDR2 = analogRead(A10);
    while (LDR2 > 200 ) {
        return 0;
    }
    if (LDR2 < 200) {
        stops();
        delay(3000);
        int readings[10];
        int min_reading = LDR2;
        //obtain min value to identify colour accurately
        for (int t = 1; t < 5; t = t + 1) {
            forward(10);
            delay(400);
            readings[t] = LDR2;
            if (readings[t] < min_reading) {
                min_reading = readings[t];
            }
        }
        stops();
        
        // return colour based on min reading
        if (min_reading < 200 && min_reading > 100) {
            return 2;
        }
        if (min_reading < 100) {
            return 1;
        }
        else {
            return 3;
        }
    }
}


int LDR3() {
    // when mine detected, stops, forwards in small steps, stops, returns number based on colour
    
    int LDR3 = analogRead(A11);
    while (LDR3 > 250 ) {
        return 0;
    }
    if (LDR3 < 250) {
        stops();
        delay(3000);
        int readings[5];
        int min_reading = LDR3;
        //obtain min value to identify colour accurately
        for (int t = 1; t < 5; t = t + 1) {
            forward(10);
            delay(400);
            readings[t] = LDR3;
            if (readings[t] < min_reading) {
                min_reading = readings[t];
            }
        }
        stops();
        
        // return colour based on min reading
        if (min_reading < 250 && min_reading > 150) {
            return 2; //red
        }
        if (min_reading < 150) {
            return 1; //yellow
        }
        else {
            return 3; //uncertain
        }
    }
}


int LDR4() {
    // when mine detected, stops, forwards in small steps, stops, returns number based on colour
    
    int LDR4 = analogRead(A12);
    while (LDR4 > 300 ) {
        return 0;
    }
    if (LDR4 < 300) {
        stops();
        delay(3000);
        int readings[5];
        int min_reading = LDR4;
        //obtain min value to identify colour accurately
        for (int t = 1; t < 5; t = t + 1) {
            forward(10);
            delay(400);
            readings[t] = LDR4;
            if (readings[t] < min_reading) {
                min_reading = readings[t];
            }
        }
        stops();
        
        // return colour based on min reading
        if (min_reading < 300 && min_reading > 150) {
            return 2; //red
        }
        if (min_reading < 150) {
            return 1; //yellow
        }
        else {
            return 3; //uncertain
        }
    }
}


int LDR5() {
    // when mine detected, stops, forwards in small steps, stops, returns number based on colour
    
    int LDR5 = analogRead(A13);
    while (LDR5 > 200 ) {
        return 0;
    }
    if (LDR5 < 200) {
        stops();
        delay(3000);
        int readings[5];
        int min_reading = LDR5;
        //obtain min value to identify colour accurately
        for (int t = 1; t < 5; t = t + 1) {
            forward(10);
            delay(400);
            readings[t] = LDR5;
            if (readings[t] < min_reading) {
                min_reading = readings[t];
            }
        }
        stops();
        
        // return colour based on min reading
        if (min_reading < 200 && min_reading > 150) {
            return 2; //red
        }
        if (min_reading < 150) {
            return 1; //yellow
        }
        else {
            return 3; //uncertain
        }
    }
}




int detect() {
    // returns 0 if no mines detected, based on above functions, or list of integers for colours detected
    //0 = black, 1 = yellow, 2 = red, 3 = uncertain
    static int detected[6];
    
    if (LDR0() == 0) {
        //&& (LDR1() == 0) && (LDR2 == 0) && (LDR3 == 0) && (LDR4 == 0) && (LDR5 == 0) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        // returns 0 when no mines detected
        return 0;
    }
    else {
        int a = LDR0();
        int b = 0; //LDR1();
        int c = 0; //LDR2();
        int d = 0; //LDR3();
        int e = 0; //LDR4();
        int f = 0; //LDR5();
        
        /*
         int detected[3];
         detected[0] = a;
         detected[1] = b;
         detected[2] = c;
         */
        
        // find if max is 1 (yellow) or 2 (red)
        int maxx = 0;
        if (a > maxx) { maxx = a; }
        if (b > maxx) { maxx = b; }
        if (c > maxx) { maxx = c; }
        if (d > maxx) { maxx = d; }
        if (e > maxx) { maxx = e; }
        if (f > maxx) { maxx = f; }
        
        return maxx;
        
        /*
         if ((max(max(a, b), c) == 1)) {
         digitalWrite(2, HIGH);
         return 1;
         }
         if ((max(max(a, b), c) == 2)) {
         digitalWrite(3, HIGH);
         return 2;
         }
         */
        
        
    }
}

/*
 void loop() {
 if (LDR4() == 0) {
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 Serial.println("0");
 }
 if (LDR4() == 1) {
 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 Serial.println("yellow");
 }
 if (LDR4() == 2) {
 digitalWrite(3, HIGH);
 digitalWrite(2, LOW);
 Serial.println("red");
 }
 }
 */


