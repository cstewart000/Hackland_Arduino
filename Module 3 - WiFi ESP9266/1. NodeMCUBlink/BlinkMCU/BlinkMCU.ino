/*
  Blink ESP8266

  Turns an LED on for one second, then off for one second, repeatedly.


  Connecting to the node MCU ESP8266
  1.  File>Preferences, paste the following to addional boards manager URL
      http://arduino.esp8266.com/stable/package_esp8266com_index.json

  2.  Tools>Board: NodeMCU 1.0

  3.  Tools>Board>Board Manager, get: esp8266 by esp8266 community

  4.  Upload sketch, hold the reset button down on the ESP8266 
  
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
