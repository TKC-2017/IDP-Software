

// the loop routine runs over and over again forever:
void mine_detection(float front_distance) {
  // read the input on analog pin A8 to A13:
  int LDR0 = analogRead(A8);
  int LDR1 = analogRead(A9);
  int LDR2 = analogRead(A10);
  int LDR3 = analogRead(A11);
  int LDR4 = analogRead(A12);
  int LDR5 = analogRead(A13);
  // print out the value you read:
  int LDR_values[6] = {LDR0, LDR1, LDR2, LDR3, LDR4, LDR5};
  Serial.println(LDR_values[0]);
  delay(1);        // delay in between reads for stability
}
