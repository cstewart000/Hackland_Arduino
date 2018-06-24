/*
 * PWM Digital write explorer
  Written: C. Stewart
  08/06/2018
  cstewart000@gmail.com

  
*/

#define LED_PIN 9
#define POTENTIOMETER_PIN A0
#define BLUE_LED_PIN 8
#define RED_LED_PIN 7

int potRead = 0;

void setup() {
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  //pinMode(SERVO_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
 
}

void loop() {
  int ledValue;
  
  //TODO: task1 => call digitalWrite(pin, value) Turn the LED on . DO the same with the motor . Do the same with the servo
  //digitalWrite(LED_PIN, LOW);
  //delay(1000);
  //digitalWrite(LED_PIN, HIGH);
  //delay(1000);

  //TODO: task2 => call analogWrite(pin, value) make the LED half as bright as normal ie: value = 256/2 = 128! DO the same with the motor. Do the same with the servo
  //analogWrite(LED_PIN, 30);

  //TODO: task3 => use an analogRead() function to read the voltage from the potentiometer, use the map() function to map the values from the pot to change the speed of the motor, intensity of the LED and position of the servo.    
  potRead = analogRead(POTENTIOMETER_PIN);

  ledValue = potRead / 4;
  // if ledvalue is too low, the LED flickers
  if (ledValue < 10){
    ledValue = 10;
  }

  // turn off all the LEDs each loop
  analogWrite(LED_PIN, 0);
  analogWrite(BLUE_LED_PIN, 0);
  analogWrite(RED_LED_PIN, 0);

  if (ledValue < 80) {
    analogWrite(LED_PIN, 255);
  }
  else if (ledValue < 160) {
    analogWrite(BLUE_LED_PIN, 255);
  }
  else {
    analogWrite(RED_LED_PIN, 255);
  }
  

  //analogWrite(LED_PIN, 255);
  //analogWrite(BLUE_LED_PIN, 255);
}
