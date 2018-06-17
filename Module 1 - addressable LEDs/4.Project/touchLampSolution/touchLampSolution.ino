/*
    Arduino Capacitive Touch Mood Lamp

    A simple program for a Mood Lamp with a single imput, a capacitive touch surface,
    which detects different press types (ie short, long) to change the behaviour.
    The program uses the AdaFroit NeoPixel library to drive RGB LEDs.

    The circuit:

      - D6 : Connected to the signal line of the LED strip.
      - A0 : free wire attached to metalic surface for touch inpit.

      - Power where it should be :P

      Created: 24/12/2016
      By: Cameron Stewart, cstewart000@gmail.com
      https://github.com/cstewart000/ArduinoCapacitiveTouchMoodLamp

      Updates:
      14/06/2018 - Updated for the Hackland Arduino course changed to use ADC touch library over capacitive touch, made work, gen tidy

*/


// Libraries
#include <Adafruit_NeoPixel.h>
#include <ADCTouch.h>

// Debug mode - set to 1 for serial printouts
#define DEBUG_STATE 1
#define DEBUG_ADC 0

// Hardware definitions
#define TOUCH_PIN A0

#define STRIP_PIN 6
#define NUM_PIXELS 20

// Press min duration definition
#define SHORT_PRESS 0
#define LONG_PRESS 1000
#define ADC_THRESHOLD 200

// Number of different mood routines to be defined
#define NUM_MODES 2

// Initialisaiton of objects
int refADCreadings; //reference values to remove offset
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, STRIP_PIN, NEO_GRB + NEO_KHZ800);


// Global state variables
long buttonTimer = 0;
long time;
long buttonTime = 0;

boolean buttonState = false;
boolean buttonLastState = false;
boolean longPressActive = false;
boolean lampOn = false;

int mode = 1;

// Method declarations
boolean checkButtonState();
int pressType(int);
void lampStateManager(int);
void updateLamp();


void setup() {

  refADCreadings = ADCTouch.read(A0, 500);    //create reference values to

  if (DEBUG_STATE || DEBUG_ADC) {
    Serial.begin(9600);
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
  }
}

void loop() {

  // TODO: Check button state in interrupt to stop code blocking
  buttonState = checkButtonState();

  // New press
  if (buttonState && !buttonLastState) {
    buttonLastState = true;
    buttonTimer = 0;
    buttonTime = millis();
  } else if (!buttonState && buttonLastState) { //Release condition
    buttonLastState = false;
    buttonTimer = millis()-buttonTime;
    
    int pressOption = pressType(buttonTimer);
    
    lampStateManager(pressOption);

    //Update lamp based on the changed state variables
    updateLamp();

    // Debug logging
    if (DEBUG_STATE) {
      Serial.print("lamp state:");
      Serial.print(lampOn);
      
      Serial.print("\tlamp mode:");
      Serial.print(mode);
      
      Serial.print("\tbuttonTimer:");
      Serial.print(buttonTimer);
      
      Serial.print("\tbuttonTime:");
      Serial.print(buttonTime);
      
      Serial.println();
    }
  }
}


boolean checkButtonState() {

  int adcRead = ADCTouch.read(A0);
  adcRead -= refADCreadings;

  if (DEBUG_ADC) {
    Serial.println(adcRead);
  }

  if (adcRead > ADC_THRESHOLD) {
    return true;
  } else {
    return false;
  }
}

int pressType(int buttonTimer) {

  if (buttonTimer > LONG_PRESS) {
    return 1;
  } else if (buttonTimer > SHORT_PRESS) {
    return 2;

    // Add more branching options here for more other behaviours

    // TODO: Held press - scroll over the colour wheel.

    // TODO: Double tap - step forward

    // TODO: Triple tap - step back

  } else
    return 0;
}

void lampStateManager(int pressOption) {

  switch (pressOption) {

    //long press toggles on/off
    case 1:
      lampOn = !lampOn;
      break;

    // short press increments the mode
    case 2:
      mode++;
      break;
    default:

      break;

  }

}


void updateLamp() {

  if (!lampOn) {
    colourStripSet(strip.Color(0, 0, 0)); // off
  } else {

    switch (mode % NUM_MODES) {
      case 0:
        colourStripSet(strip.Color(222, 40, 179)); //
        break;

      case 1:
        colourStripSet(strip.Color(224, 169, 114)); //
        break;

      case 2:
        colourStripSet(strip.Color(random(255), random(255), random(255))); //
        break;

        // TODO: Add case statements for new behaviours
    }
    strip.show();
  }
}

// Sets strip to a new colour
void colourStripSet(uint32_t colour) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, colour);
  }
  strip.show();
}

