#include <Ultrasound_compass.h>
#include <Motor.h>

// function which returns which LDR sensors are triggered
void LDR() {
  
  int LDR0 = analogRead(A8), LDR1 = analogRead(A9), LDR2 = analogRead(A10);
  int colour0, colour1, colour2;
  //vector<int> LDR_list ;
  
  if (LDR0 > 300) {
    colour0 = "black";
  }
  else {
    if (LDR0 < 300 && LDR0 > 150 ) {
      colour0 = "red";
    }
    else {
      if (LDR0 < 150) {
        colour0 = "yellow";
      }
      else {
        colour0 = "uncertain";
      }
    }
  }
  // repeat for colour1 and colour2
  if (LDR1 > 150) {
    colour1 = "black";
  }
  else {
    if (LDR1 < 150 && LDR1 > 80) {
      colour1 = "red";
    }
    else {
      if (LDR1 < 80) {
        colour1 = "yellow";
      }
      else {
        colour1 = "uncertain";
      }
    }
  }

  
  if (LDR2 > 200) {
    colour2 = "black";
  }
  else {
    if (LDR2 < 200 && LDR0 > 100 ) {
      colour2 = "red";
    }
    else {
      if (LDR2 < 100) {
        colour2 = "yellow";
      }
      else {
        colour2 = "uncertain";
      }
    }
  }
  
  //LDR_list.push_back(colour0);
  //LDR_list.push_back(colour1);
  //LDR_list.push_back(colour2);

  LDR_list[0] = colour0;
  LDR_list[1] = colour1;
  LDR_list[2] = colour2;
  
  // returns list of colours e.g. [black, red, black]
  // (then need to determine location of mines based on if neighbouring LDRs return same colour)
  return LDR_list;
  }

}

void setup() {
  int count0 = 0;
  int count1 = 0;
  int count2 = 0;

  int LDR_list[3] = {0,0,0};

void loop() {
  
  LDR();
  delay(100);
  
  //for(int i=0; i<5; ++i){
  if (LDR_results[0] == "red") {
  stops();
  ++count0;
  forward(10);
  }

  if (LDR_results[0] == "yellow") {
  stops();
  --count0;
  forward(10);
  }

  if (count0 > 4) {
    stops();
    digitalWrite(3, HIGH);
  }

  if (count0 < -4 {
    stops();
    digitalWrite(2, HIGH);
  }
  
  /*// set up LDR analog inputs
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
  */

}
