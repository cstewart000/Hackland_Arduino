/*
   Drawbot position function

   Inverse Kinematics -
   Function for the angle (length) of members to determine the position of an effector

   A drawbot (a.k.a. polargraph) is robot that uses a pen as an effector tethered by two stepper motors from two distant postions
   the drawbot traverses its working area by shortening and or lengthening the tethers of from the steppers.
   Video: https://www.youtube.com/watch?v=usqarqGnFog

*/

// TODO - Task 1: Write a function that changes the length cable from a stepper motor. ie void changeLength(int millimeters)
// TODO - Task 2: write a function that takes a boolean and writes two different positions (actual values to be determined later) for a servo. ie void marker(boolean draw)
// TODO - Task 3: write a function that takes an (x,y) co-ordinate where (0,0) is the top left corner of the drawing canvas and converts to an equivalent (L1, L2) where L1 is the length of tether 1 and L2 is the length of teather 2
// TODO - Task 4: overload the function from task 2 to take a second boolean parameter that changes the length of the stepper by an absolute or relative ammount.
//        def: relative the length of the tether changes BY the value of the argument passed.
//        def: absolute the length of the tether changes TO the value of the argument passed.
//        e.g.: void changeLength(int millimeters, boolean absoulte)
// TODO - next week!

#define DEBUG 1

#define WINCH_SPACING 1000
#define X_LIM_MIN 165
#define X_LIM_MAX 834
#define Y_LIM_MIN 223
#define Y_LIM_MAX 618

String input = "";
boolean stringComplete = false;

const String X_QUALIFIER = "X:";
const String Y_QUALIFIER = "Y:";

float xCoord = 0;
float yCoord = 0;

float len1 = 0;
float len2 = 0;

void parseString();
boolean translateCoordinatesABStoPolar();
void establishContact();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  input.reserve(10);
  establishContact();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // get incoming byte and cast to char
    char inChar = (char)Serial.read();
    input = input + inChar;

    if (inChar == ';') {
      stringComplete = true;
    }

    //Completed instruction
    if (stringComplete) {
      if (DEBUG) {
        Serial.println(input);
        Serial.println(stringComplete);
      }

      parseString();
      stringComplete = false;
      input = "";
      translateCoordinatesABStoPolar();
    }
  }
}

boolean translateCoordinatesABStoPolar() {
  float len1;
  float len2;

  //Exit condition
  if (xCoord < X_LIM_MIN || xCoord > X_LIM_MAX || yCoord < Y_LIM_MIN || yCoord > Y_LIM_MAX) {

  if (DEBUG) {
    Serial.println("Co-ordinates out of range");
  }
    return false;
  }

  len1 = sqrt(xCoord * xCoord + yCoord * yCoord); //^ 0.5
  len2 = sqrt((WINCH_SPACING - xCoord) * (WINCH_SPACING - xCoord) + yCoord * yCoord);// ^ 0.5

  if (DEBUG) {
    Serial.print(len1);
    Serial.print("\t");
    Serial.println(len2);
  }
  return true;
}

void parseString() {
  int xIndex = input.indexOf(X_QUALIFIER);
  int yIndex = input.indexOf(Y_QUALIFIER, yIndex);

  String xString = input.substring(xIndex + 2, yIndex);
  xString.trim();
  String yString = input.substring(yIndex + 2);

  yString.trim();

  xCoord = xString.toFloat();
  yCoord = yString.toFloat();

  if (DEBUG) {
    Serial.print(xCoord);
    Serial.print("\t");
    Serial.println(yCoord);
  }
}

void establishContact() {
  if (Serial.available() <= 0) {
    Serial.println("serial connection established");   // send an initial string
    delay(300);
  }
}

