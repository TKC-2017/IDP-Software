void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // set initial distance to wall range
  range = 20
  
  while (//not at end condition, robot not at centre) {
  
    if ("mine_detetced" = 0) {
    // follows default path
    // need to correct variable for mine detection
      if (heading < 160 and heading > 200) {
      // robot is not facing south, also if on default path
        if distance_to_wall > range {
          forward(100) }
        else {
          stops()
          left() }
      }
      else {
      // robot is facing south
       range += 25
       if distance_to_wall > range {
          forward(100) }
       else {
          stops()
          left() }
      }
    }
    
    else {
    // if mine detected
    // need to change variables / use sensor code
      if (mine = yellow) {
        stops()
        delay(3000)
        forwards(1000) }
      else {
        stops(3000)
        if ( check(current_position) = safe) {
          // create function that checks for red mines on outside of spiral 
          // at diamater from current position
          right()
          forward(100)
          delay(2000) // either use delay or range sensors for forward distance
          stops()
          left()
          forward(100)
          delay(2000) // as above
          stops()
          left()
          forward(100)
          delay(2000) // as above
          stops()
          right()
        }
      }
    }

  // end sequence
