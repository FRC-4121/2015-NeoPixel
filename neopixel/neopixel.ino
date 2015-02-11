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
  fadeLoop(strip.Color(255, 85,0), strip.Color(0, 255, 0), 10);
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

void fadeLoop(uint32_t color1, uint32_t color2, uint8_t wait){ // Fades between two colors
	uint8_t i, c;
	for(int c=0; c< 255 * 5; c++){
  	for(int i=0; i<strip.numPixels(); i++){ // Sets color
	    strip.setPixelColor(i, color1);
	    strip.setBrightness(Fade(c));
	    strip.show();
	    delay(wait);
  	}
	 	delay(10);
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

uint32_t Fade(byte FadePos){
	if(FadePos < 150){
		return(FadePos * 25);
	} else if(150 < FadePos < 200 ) {
		return(FadePos * 15);
	} else if(200 < FadePos < 255) {
		return(FadePos / 15);
	} else {
		return(25);
	}
}