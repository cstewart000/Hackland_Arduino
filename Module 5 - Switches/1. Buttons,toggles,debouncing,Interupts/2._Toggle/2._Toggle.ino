/*

  Modified from Arduino example sketch


  http://www.arduino.cc/en/Tutorial/Debounce
*/



#define button1Pin 2
#define button2Pin 3
#define led1Pin 4
#define led2Pin 5
#define ledResultPin 6


// Variables will change:
bool led1State = false;         // the current state of the output pin
bool button1State;             // the current reading from the input pin
bool lastButton1State;   // the previous reading from the input pin

void setup() {
  pinMode(led1Pin, INPUT);
  pinMode(button1Pin, OUTPUT);

  //Serial.begin(9600);
  //Serial.println("monitoring button 1's state!");

}

void loop() {
  // read the state of the switch into a local variable:
  bool button1State = digitalRead(button1Pin);

  //print button state to console.
  //Serial.print("button 1's state: ");
  //Serial.print(button1State, DEC);
  //Serial.print("\t led state: ");
  //Serial.println(led1State, DEC);

  // Toggle the LED if the button was pressed
  if (button1State == true && lastButton1State == false ) {

    led1State = !led1State; //TOGGLE ASSIGNMENT!!!

  }
  // save the reading
  lastButton1State = button1State;
  digitalWrite(led1Pin, led1State);
}
