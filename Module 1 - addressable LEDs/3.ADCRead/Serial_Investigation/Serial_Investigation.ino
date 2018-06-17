/*
 * Serial Investigation
 * By: C. Stewart
 * 30/05/2018
*/

/*
 * TODO: 1. Run the code below. 
 * 2. Open the serial monitor on the right
 * 3. value is a 10-bit value: 2^10 = 1024, representing the voltage from 0 to 5v.
 * 4. Using a female-female jumper, connect A0 to: Vin, GND, Vref, 3V3
 */
int adcReading = 0;
float voltage = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:\
  
  adcReading = analogRead(A0);
  // wait a bit for the analog-to digital converter to stabilize after the last
  // reading:
  voltage = mapf(adcReading, 0, 1024, 0, 5);
  
  Serial.print(adcReading);
  Serial.print("\t voltage: ");
  Serial.print(voltage,DEC);
  Serial.println("v");
  delay(2);
}

float mapf(long x, long in_min, long in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

