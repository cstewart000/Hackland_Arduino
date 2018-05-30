
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 16
int DELAY = 100;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // put your main code here, to run repeatedly:

  //TODO: Task 1a - Turn on first ONLY pixel(LED to white)
  //TODO: Task 2a - Set one pixel to white moving down the strip
  //TODO: Task 3a - Make the neopixels flash hacklands colours for one second each
  //TODO: Task 4a - Make the neopixels fade in adn out with hacklands colours. ie go from zero brightness to full brightness of one colour then do the same for the other colour.

  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  for (int i = 0 ; i <= NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255)); // Moderately bright green color.
    pixels.show();
    delay(DELAY);
    pixels.clear();
    pixels.show();
  }
}
