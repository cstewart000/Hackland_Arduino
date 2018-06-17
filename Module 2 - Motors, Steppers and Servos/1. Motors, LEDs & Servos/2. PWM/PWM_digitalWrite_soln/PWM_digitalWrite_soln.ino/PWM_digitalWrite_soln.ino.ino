/*
 * PWM Digital write explorer
  Written: C. Stewart
  08/06/2018
  cstewart000@gmail.com

  
*/

#define LED_PIN 9
#define POTENTIOMETER_PIN A0

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
 
}

void loop() {

  //TODO: task1 => call digitalWrite(pin, value) Turn the LED on . DO the same with the motor . Do the same with the servo


  //TODO: task2 => call analogWrite(pin, value) make the LED half as bright as normal ie: value = 256/2 = 128! DO the same with the motor. Do the same with the servo
  

  //TODO: task3 => use an analogRead() function to read the voltage from the potentiometer, use the map() function to map the values from the pot to change the speed of the motor, intensity of the LED and position of the servo.    


}
