// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void mine_detection(float front_distance) {
  // read the input on analog pin A8 to A13:
  int LDR1 = analogRead(A8);
  int LDR2 = analogRead(A9);
  int LDR3 = analogRead(A10);
  int LDR4 = analogRead(A11);
  int LDR5 = analogRead(A12);
  int LDR6 = analogRead(A13);
  // print out the value you read:
  // Serial.println(sensorValue);
  int LDR_values [6] = {LDR1, LDR2, LDR3, LDR4, LDR5, LDR6};
  delay(1);        // delay in between reads for stability
}
