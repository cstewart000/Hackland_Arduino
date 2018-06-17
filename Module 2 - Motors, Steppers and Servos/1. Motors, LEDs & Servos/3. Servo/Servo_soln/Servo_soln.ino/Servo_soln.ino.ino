/*

  Written: C. Stewart 16/06/2018

  Based on:
  Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

#define SERVO_PIN 6
#define POTENTIOMETER_PIN A0

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position between 0 and 180 - value is degrees.

void setup() {
  myservo.attach(SERVO_PIN);  // attaches the servo
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {

  //myservo.write(pos);// tell servo to go to position in variable 'pos'

  //TODO 1: make servo alternate between 0 and 180 degrees with 1 second pause.
  /*
    myservo.write(0);
    delay(2000);
    myservo.write(180);
    delay(2000);
  */

  /*
  //TODO 2: make servo sweep from 0 to 180 and back to 0 (use a for loop)
  for (int i = 0 ; i <= 180; i++) {
    myservo.write(i);
    delay(50);
  }
  for (int j = 180 ; j >= 0; j--) {
    myservo.write(j);
    delay(50);
  }

  */

  
    //TODO 3: Read the A0 potentiometer and adjust the servo position based on that.
    int analogInputRead = analogRead(POTENTIOMETER_PIN);
    int pwmValue = map(analogInputRead, 0,1023,0,180);
    myservo.write(pwmValue);

  
}

