
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 16

bool dir = true; //true is up :)
int STEP_DELAY = 10;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // put your main code here, to run repeatedly:

  //TODO: Make the neopixels flash hacklands colours for one second each
  for (int j = 0; j <= 255; j++) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(232, 192, 24));
    }
    pixels.setBrightness(j);
    pixels.show();
    delay(STEP_DELAY);
  }

  for (int j = 255; j >= 0; j--) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(232, 192, 24));
    }
    pixels.setBrightness(j);
    pixels.show();
    delay(STEP_DELAY);
  }

  for (int j = 0; j <= 255; j++) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(38, 133, 170));
    }
    pixels.setBrightness(j);
    pixels.show();
    delay(STEP_DELAY);
  }

  for (int j = 255; j >= 0; j--) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(38, 133, 170));
    }
    pixels.setBrightness(j);
    pixels.show();
    delay(STEP_DELAY);
  }
}


