/*
  Blink_soln_better

  cstewart000@gmail.com
  28/05/2018

  from arduino example code.
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  //TODO: Make the light pulse twice fast then long pause then short pause then one pulse  
  pulse(500,500);
  pulse(500,2000);
  pulse(500,500);
}

void pulse(int timeOn, int timeOff){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(timeOn);
  digitalWrite(LED_BUILTIN,LOW);
  delay(timeOff);
}

