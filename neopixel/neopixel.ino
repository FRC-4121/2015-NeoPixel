#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
  startUp();
}

void loop() {
  // fadeLoop(10); 																							// Fades between two oranges
  chaseLoop(strip.Color(0,0,0), strip.Color(255,80,0), 10); 	// Has a single pixel changing color down the line.
  // rainbowCycle(50);
}

void startUp(){ // Flashes green to show it's on
	uint8_t i;
	for(int i=0; i<strip.numPixels(); i++){
		strip.setPixelColor(i, 0, 255, 0);
		strip.show();
		delay(1);
	}
	delay(500);
	for(int i=0; i<strip.numPixels(); i++){
		strip.setPixelColor(i, 0, 0, 0);
		strip.show();
		delay(1);
	}
}

void fadeLoop(uint8_t wait) {
	uint8_t i, j, c;
	//for(int c = 0; c < 5; c++){
		for(int j = 80; j < 256; j++) {
		  for(int i=0; i<strip.numPixels(); i++) {
		    strip.setPixelColor(i, strip.Color(255 , j, 0));
		    strip.show();
		    delay(wait);
		  }
		}
		for(int j = 255; j > 0; j--) {
		  for(int i=0; i<strip.numPixels(); i++) {
		    strip.setPixelColor(i, strip.Color(255, j, 0));
		    strip.show();
		    delay(wait);
		  }
		}
	//}
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void chaseLoop(uint32_t color1, uint32_t color2, uint8_t wait){
	uint8_t i, c;
	for(int c=0; c < 10; c++){ // Loop count
		for(int i=0; i < strip.numPixels(); i++){
			strip.setPixelColor(i, color1); // Sets the chase pixel color.
			strip.setPixelColor(i + 1, color1);
			strip.setPixelColor(i + 2, color1);
			strip.setPixelColor(i - 1, color2); // Sets the pixel color to the background
			strip.setPixelColor(i - 2, color2);
			strip.show();
			delay(wait);
		}
	}
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
