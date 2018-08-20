/*
    Modified from Arduino example sketch
  .

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/


#define button1Pin 2
#define button2Pin 3
#define led1Pin 13
#define led2Pin 5
#define ledResultPin 6

// Variables will change:
bool led1State = false;         // the current state of the output pin
bool button1State;             // the current reading from the input pin
bool lastButton1State;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(button1Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(button1Pin), onButton1Change, FALLING);

  Serial.begin(9600);
  Serial.println("monitoring button 1's state!");

}

void loop() {
  // read the state of the switch into a local variable:
  bool button1State = digitalRead(button1Pin);


  digitalWrite(led1Pin, led1State);
  // save the reading
  lastButton1State = button1State;

  //print button state to console.
  Serial.print("button 1's state: ");
  Serial.print(button1State, DEC);
  Serial.print("\t led state: ");
  Serial.print(led1State, DEC);
  Serial.print("\t time since last press: ");
  Serial.print(lastDebounceTime, DEC);
  Serial.print("\t led state: ");
  Serial.println(millis(), DEC);

  someStupidlyLongFunction();

}

void someStupidlyLongFunction() {

  delay(100);

}

void onButton1Change() {

  Serial.println((millis() - lastDebounceTime));
  Serial.println("interrupted!");
  if ((millis() - lastDebounceTime) > debounceDelay) {
    led1State = !led1State; //TOGGLE ASSIGNMENT!!!
    Serial.println("Toggle! ");

  }

  lastDebounceTime = millis();

}

