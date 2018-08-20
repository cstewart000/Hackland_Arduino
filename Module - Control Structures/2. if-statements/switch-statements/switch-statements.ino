


#define led1Pin 2
#define button1Pin 3
#define led2Pin 4
#define button2Pin 5
#define s 6

int ledBlinkTime = 0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);


}

void loop() {
  switch (getButtonsCase()) {
    case 1:
      ledBlinkTime = 1000;
      break;
    case 2:
      ledBlinkTime = 500;
      break;
    case 2:
      ledBlinkTime = 250;
      break;
    case 3:
      ledBlinkTime = 125;
      break;
  }

  digitalWrite(ledResultPin, HIGH);
  delay(ledBlinkTime);
  digitalWrite(ledResultPin, HIGH);
  delay(ledBlinkTime);     
}

int getButtonsCase() {
  // put your main code here, to run repeatedly:
  bool button1State = digitalRead(button1Pin);
  bool button2State = digitalRead(button2Pin);

  digitalWrite(led1Pin, button1State);
  digitalWrite(led1Pin, button1State);

  //This is the the conditional statement. The result LED will show the evaluation.
  // try substituting '&&' with '||' (to or statement) and playing with the buttons
  // next put '!'(bang: NOT) infront of each of the arguments and play again.
  if (!button1State && !button2State) {
    return 1;
  } else if (button1State && !button2State) {
    return 2;
  } else if (!button1State && button2State) {
    return 3;
  } else if (button1State && button2State) {
    return 4;
  }

}
