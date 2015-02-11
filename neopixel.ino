#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#define PIN            6
#define NUMPIXELS      60

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  fadeLoop(pixel.color(255, 85,0), pixel.color(255, 25, 0), 100);
  pulse(pixel.color(255, 25, 0), pixel.setBrightness(50), 500);
}

void fadeLoop(uint32_t color1, uint32_t color2, uint8_t wait){ // Fades between two colors
  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, color1);
    pixels.show();
    delay(wait);
    pixels.setPixelColor(i, color2);
    delay(wait)
    pixels.show();
  }
}

void pusle(uint32_t color, uint8_t minB, wait){
  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(wait);
  }
}