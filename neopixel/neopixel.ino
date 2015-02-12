#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
  startUp();
  strip.show();
}

void loop() {
  fadeLoop(255, 80, 0, 255, 150, 0, 10, 10); // Fades between two oranges
  // pulse(strip.Color(255, 25, 0), 50, 500);
}

void startUp(){ // Flashes green to show it works
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
	for(int i=0; i< 5; i++){ // Sets color
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

void pulse(uint32_t color, uint8_t minB, uint8_t wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

uint32_t Fade(byte FadePos){
	if(FadePos < 150){
		return(FadePos * 2.5);
	} else if(150 < FadePos < 200 ) {
		return(FadePos * 1.5);
	} else if(200 < FadePos < 255) {
		return(FadePos / 1.5);
	} else {
		return(85);
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
