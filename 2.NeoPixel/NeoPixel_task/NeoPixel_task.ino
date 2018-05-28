
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // put your main code here, to run repeatedly:

    //TODO: Make the neopixels flash hacklands colours for one second each
    
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show();
}
