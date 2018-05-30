
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
    for(int i = 0; i<=NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(232,192,24));
    }
    pixels.show();
    delay(1000);

    for(int i = 0; i<=NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(38,133,170));
    }
    pixels.show();
    delay(1000);


    
}
