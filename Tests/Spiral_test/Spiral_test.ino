#include <Ultrasound_compass.h>

void light() {
  // function for blinking LED
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void nolight() {
  // function for LED off
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void fastlight() {
  // function for fast blinking LED
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for half a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for half a second
}

void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  //Serial Port begin
  Serial.begin (9600);
  setup_ultrasound();

}


void loop() {
  // simulate robot moving in spiral, demonstrating robot knows when to turn
  
  // set initial distance to wall range
  double range = 2;
  
  int spiral = 1;
  while (spiral < 9) {

    while (spiral % 4 != 0) {
      
      while (distance(0) > range) {
        // sensor 1 or 0
        light(); 
        /*
        Serial.print("large range");
        Serial.print(range);
        Serial.print(distance(0));
        Serial.println();
        */
      }
      
      // when sensor is close to wall, break loop, light fast, turn manually, repeat loop
      fastlight();
      delay(4000);
      spiral += 1;
      /*
      Serial.print("close");  
      Serial.print(range);
      Serial.print(distance(0));
      Serial.println(); }
      */
    }
    
    // once spiral is a multiple of 4, break loop, increase range for next inner loop of spiral
    range += 25;
      
    while (distance(0) > range) {
      light();
    }
    // when sensor close to wall, break loop, light fast, turn manually, repeat loop from top
    fastlight();
    delay(4000);
    spiral += 1;
    }

  // when spiral reaches 8, LED blinks off to demonstrate end
  nolight();
  delay(4000);
}

  
     
