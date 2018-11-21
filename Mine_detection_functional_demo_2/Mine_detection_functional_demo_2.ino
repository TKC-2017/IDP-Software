#include <Ultrasound_compass.h>
#include <Motor.h>
//#include <algorithm>
//#include <vector>
//using namespace std;


// functions which return colour under each LDR 

void LDR0() {
  int LDR0 = analogRead(A8);
  while (LDR0 > 'black' ) {
    return 'black';
  }
  if (LDR0 < 300) {
    stops();
    delay(1000);
    int readings[5];
    int min_reading = readings[0];
    //obtain min value to identify colour accurately 
    for (int t = 0; t < 5; t = t + 1) {
      forward(50);
      readings[t] = LDR0;
      if (readings[t] < min_reading) {
        min_reading = readings[t];
      }
    }
    stops();
    
    //double min_reading = *min_element(readings.begin(), readings.end());
    
    // return colour based on min reading
    if (min_reading < 300 && min_reading > 150) {
      return 'red';
    }
    if (min_reading < 150) {
      return 'yellow';
    }
    else {
      return 'uncertain';
    }
  }
}

    
void LDR1() {
  int LDR1 = analogRead(A9);
  while (LDR1 > 150 ) {
    return 'black';
  }
  if (LDR1 < 'black') {
    stops();
    delay(1000);
    int readings[5];
    int min_reading = readings[0];
    //obtain min value to identify colour accurately 
    for (int t = 0; t < 5; t = t + 1) {
      forward(50);
      readings[t] = LDR0;
      if (readings[t] < min_reading) {
        min_reading = readings[t];
      }
    }
    stops();
    
    //double min_reading = *min_element(readings.begin(), readings.end());
    
    // return colour based on min reading
    if (min_reading < 150 && min_reading > 80) {
      return 'red';
    }
    if (min_reading < 80) {
      return 'yellow';
    }
    else {
      return 'uncertain';
    }
  }
}    


void LDR2() {
  int LDR2 = analogRead(A10);
  while (LDR2 > 200 ) {
    return 'black';
  }
  if (LDR2 < 'black') {
    stops();
    delay(1000);
    int readings[5];
    int min_reading = readings[0];
    //obtain min value to identify colour accurately 
    for (int t = 0; t < 5; t = t + 1) {
      forward(50);
      readings[t] = LDR0;
      if (readings[t] < min_reading) {
        min_reading = readings[t];
      }
    }
    stops();
    
    //double min_reading = *min_element(readings.begin(), readings.end());
    
    // return colour based on min reading
    if (min_reading < 200 && min_reading > 100) {
      return 'red';
    }
    if (min_reading < 100) {
      return 'yellow';
    }
    else {
      return 'uncertain';
    }
  }
} 

   
void loop() {
  while (LDR0() == 'black' && LDR1() == 'black' && LDR2 == 'black') {
    forward(100);
  }
  stops();
  Serial.print("LDR0: ")
  Serial.print(LDR0())
  Serial.println()
  Serial.print("LDR1: ")
  Serial.print(LDR1())
  Serial.println()
  Serial.print("LDR2: ")
  Serial.print(LDR2())
  Serial.println()
  
    
   }
  }
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
