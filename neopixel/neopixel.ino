#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
  startUp();
}

void loop() {
  fadeLoop(255, 80, 0, 255, 150, 0, 10, 10); 										// Fades between two oranges
  chaseLoop(strip.color(255,0,0), strip.color(0,0,255), 100); 	// Has a single pixel changing color down the line.
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

void fadeLoop(uint8_t Rstart, uint8_t Gstart, uint8_t Bstart, uint8_t Rend, uint8_t Gend, uint8_t Bend, uint8_t n, uint8_t wait){
	// Fades between two colors. Args: Begining RGB vals, Ending RGB vals, steps, and delay time.
	uint8_t i, c;
	for(int c=0; c< 5; c++){ // loop count
		for(int i = 0; i < n; i++){ // larger values of 'n' will give a smoother/slower transition.
		  Rnew = Rstart + (Rend - Rstart) * i / n;
		  Gnew = Gstart + (Gend - Gstart) * i / n;
		  Bnew = Bstart + (Bend - Bstart) * i / n;
			strip.setPixelColor(i, Rnew, Gnew, Bnew);
			strip.show();
			delay(wait);
		}
	}
}

void chaseLoop(uint32_t color1, uint32_t color2, uint8_t wait){
	uint8_t i, c;
	for(int c=0; c < 5; c++){ // Loop count
		for(int i=0; i < strip.numPixels(); i++){
			strip.setPixelColor(i, color1); // Sets the pixel color to the background
			strip.show();
			delay(1);
			strip.setPixelColor(i, color2); // Sets the chase pixel color.
			strip.setPixelColor((i - 1), (color2 / 2));
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
