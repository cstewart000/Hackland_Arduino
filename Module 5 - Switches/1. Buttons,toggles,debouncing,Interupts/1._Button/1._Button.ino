/*
  Button

  Edited from the arduino example sketches
  
  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

#define button1Pin 2
#define button2Pin 3
#define led1Pin 4
#define led2Pin 5
#define ledResultPin 6


// variables will change:
bool buttonState = false;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledResultPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(button1Pin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == true) {
    // turn LED on:
    digitalWrite(led1Pin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led1Pin, LOW);
  }
}
