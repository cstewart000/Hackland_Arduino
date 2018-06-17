/*
 * 
 */

// TODO - Task 1: Write a function that changes the length cable from a stepper motor. ie void changeLength(int millimeters)
// TODO - Task 2: overload the function from task 2 to take a second boolean parameter that changes the length of the stepper by an absolute or relative ammount.

#include <Arduino.h>
#include "A4988.h"

// using a 200-step motor (most common)
#define MOTOR_STEPS 200
// configure the pins connected
#define DIR 4
#define STEP 3
#define MS1 10
#define MS2 11
#define MS3 12

int rpm = 15;
A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);

void setup() {
    // Set target motor RPM to 1RPM and microstepping to 1 (full step mode)
    stepper.begin(rpm, 1);
}

void loop() {
    // Tell motor to rotate 360 degrees. That's it.
    stepper.rotate(360);
    //stepper.move(long steps)
    //stepper.stop();
    
    
}
