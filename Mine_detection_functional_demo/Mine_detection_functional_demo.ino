#include <Ultrasound_compass.h>
#include <Motor.h>

// function which returns which LDR sensors are triggered
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
