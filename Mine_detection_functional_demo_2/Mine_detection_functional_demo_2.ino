#include <Ultrasound_compass.h>
#include <Motor.h>
//#include <algorithm>
//#include <vector>
//using namespace std;

void setup() {

  setup_m();
  setup_us();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

// functions which return colour under each LDR 

int LDR0() {
  int LDR0 = analogRead(A8);
  while (LDR0 > 300 ) {
    return 0;
  }
  if (LDR0 < 300) {
    stops();
    delay(1000);
    int readings[10];
    int min_reading = readings[0];
    //obtain min value to identify colour accurately 
    for (int t = 0; t < 10; t = t + 1) {
      forward(10);
      delay(400);
      readings[t] = LDR0;
      if (readings[t] < min_reading) {
        min_reading = readings[t];
      }
    }
    stops();
    
    //double min_reading = *min_element(readings.begin(), readings.end());
    
    // return colour based on min reading
    if (min_reading < 300 && min_reading > 150) {
      return 1;
    }
    if (min_reading < 150) {
      return 2;
    }
    else {
      return 3;
    }
  }
}

    
int LDR1() {
  int LDR1 = analogRead(A9);
  while (LDR1 > 150 ) {
    return 0;
  }
  if (LDR1 < 150) {
    stops();
    delay(1000);
    int readings[10];
    int min_reading = readings[0];
    //obtain min value to identify colour accurately 
    for (int t = 0; t < 10; t = t + 1) {
      forward(50);
      readings[t] = LDR1;
      if (readings[t] < min_reading) {
        min_reading = readings[t];
      }
    }
    stops();
    
    //double min_reading = *min_element(readings.begin(), readings.end());
    
    // return colour based on min reading
    if (min_reading < 150 && min_reading > 80) {
      return 1;
    }
    if (min_reading < 80) {
      return 2;
    }
    else {
      return 3;
    }
  }
}    


int LDR2() {
  int LDR2 = analogRead(A10);
  while (LDR2 > 200 ) {
    return 0;
  }
  if (LDR2 < 200) {
    stops();
    delay(1000);
    int readings[10];
    int min_reading = readings[0];
    //obtain min value to identify colour accurately 
    for (int t = 0; t < 10; t = t + 1) {
      forward(50);
      readings[t] = LDR2;
      if (readings[t] < min_reading) {
        min_reading = readings[t];
      }
    }
    stops();
    
    //double min_reading = *min_element(readings.begin(), readings.end());
    
    // return colour based on min reading
    if (min_reading < 200 && min_reading > 100) {
      return 1;
    }
    if (min_reading < 100) {
      return 2;
    }
    else {
      return 3;
    }
  }
} 

   
void loop() {
  stops();
  delay(100000000);
 
  while (LDR0() == 0) {
  //&& (LDR1() == 0)) && LDR2 == 0) {
    forward(100);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  int a = LDR0();
  int b = 0; // LDR1()
  int c = 0; // LDR2()
  
  
  stops();
  Serial.println();
  Serial.print("0 = black, 1 = red, 2 = yellow, 3 = uncertain");
  Serial.println();
  Serial.print("LDR0: ");
  Serial.print(a);
  Serial.println();
  /*
  Serial.print("LDR1: ");
  Serial.print(b);
  Serial.println();
  Serial.print("LDR2: ");
  Serial.print(c);
  Serial.println();
  */
  //int ldrs[3]={LDR0 , LDR1, LDR2};
  if (max(max(a, b), c) == 2) {
    digitalWrite(2, HIGH);
    Serial.println("yellow LED");
  }
  if (max(max(a, b), c) == 1) {
    digitalWrite(3, HIGH);
    Serial.println("red LED");
  }
  delay(1000);
  

  
   
 }
 



/*
void LDR() {
  
  int LDR0 = analogRead(A8), LDR1 = analogRead(A9), LDR2 = analogRead(A10);
  int colour0, colour1, colour2;
  vecotr<int> LDR_list ;
  
  if (LDR0 < 'lowest ldr for detection') {
    colour0 = "black"
  }
  else {
    if (LDR0 > 'black' && LDR0 < 'yellow' ) {
      colour0 = "red"
    }
    else {
      if (LDR0 > 'yellow' ) {
        colour0 = "yellow"
      }
      else {
        colour0 = "uncertain"
      }
    }
  }
  // repeat for colour1 and colour2

  
  LDR_list.push_back(colour0)
  LDR_list.push_back(colour1)
  LDR_list.push_back(colour2)
  
  // returns list of colours e.g. [black, red, black]
  // (then need to determine location of mines based on if neighbouring LDRs return same colour)
  return LDR_list
  }

 

 LDR_list.push_back(0)
   
   }
}

void loop() {
  
  // set up LDR analog inputs
  int LDR0 = analogRead(A8), LDR1 = analogRead(A9), LDR2 = analogRead(A10);

  // if all inputs read black
  if (LDR0 < 'lowest ldr for detection' && LDR1 < 'lowest ldr for detection' && LDR2 < 'lowest ldr for detection') {
    forward(100);
  }

  else {
    stops();

    //
    if (LDR0 < 'lowest ldr for detection' && LDR1 < 'lowest ldr for detection' && LDR2 < 'lowest ldr for detection') {
    forward(100);
    
    
  }
  
  // print out the value you read:
  Serial.print("LDR0: ");
  Serial.println(sensorValue0);
  
  // read the input on analog pin A9:
  
  // print out the value you read:
  Serial.print("LDR1: ");
  Serial.println(sensorValue1);
  // read the input on analog pin A10:
 
  // print out the value you read:
  Serial.print("LDR2: ");
  Serial.println(sensorValue2);
  delay(500);        // delay in between reads for stability


}

*/
