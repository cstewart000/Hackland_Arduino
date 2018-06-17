/*
 * From ADC_touch example sketch
 * Tasks:
 * 1. run the sketch, observe the data coming through
 * 2. think of a way to detect a: single press, double press, long press.
 * HWK: Use this to controll the LED state or NEOPIXELS!
 */

#include <ADCTouch.h>
 
int ref0;      //reference values to remove offset
 
void setup()
{
    // No pins to setup, pins can still be used regularly, although it will affect readings
 
    Serial.begin(9600);
 
    ref0 = ADCTouch.read(A0, 500);    //create reference values to
}
 
void loop()
{
    int value0 = ADCTouch.read(A0);   //no second parameter
 
    value0 -= ref0;       //remove offset
 
    Serial.print(value0 > 40);    //return pressed or not pressed
    Serial.print("\t");
    Serial.print(value0);             //return value
    Serial.println("\t");
    delay(100);
}
