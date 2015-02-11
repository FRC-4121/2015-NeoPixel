#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
  strip.show();
}

void loop() {
  fadeLoop(strip.Color(255, 85,0), strip.Color(255, 25, 0), 100);
  pulse(strip.Color(255, 25, 0), 50, 500);
}

void fadeLoop(uint32_t color1, uint32_t color2, uint8_t wait){ // Fades between two colors
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color1);
    strip.show();
    delay(wait);
    strip.setPixelColor(i, color2);
    delay(wait);
    strip.show();
  }
}

void pulse(uint32_t color, uint8_t minB, uint8_t wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
