#include <Adafruit_NeoPixel.h>
#define PIN 0
#define NUM_PIXEL  10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXEL, PIN, NEO_GRB + NEO_KHZ800);

int red[3]    = { 255, 0, 0 };
int yellow[3]    = { 255, 255, 0 };
int green[3]    = { 0, 255, 0 };
int blue[3]    = { 0, 0, 255 };
int purple[3]    = { 80, 0, 80 };
int aqua[3]    = { 0, 255, 255 };
int pink[3]    = { 255, 153, 255 };
int off[3]    = { 0, 0, 0 };

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(10);
}

void farge(int color[3]) {
  for( int i = 0; i<NUM_PIXEL; i++){
    strip.setPixelColor(i, strip.Color(color[0], color[1], color[2]));
    strip.show();
    }
  }

void settlys(int nr, int color[3]) {
  strip.setPixelColor(nr, strip.Color(color[0], color[1], color[2]));
  strip.show();
  }

void oyne(int loop, int fart, int color[3]) {
  uint16_t i;
  for (int i=0; i < loop; i++){
    strip.setPixelColor(0, strip.Color(color[0], color[1], color[2]));
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, strip.Color(color[0], color[1], color[2]));
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
    delay(fart);
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, strip.Color(color[0], color[1], color[2]));
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, strip.Color(color[0], color[1], color[2]));
    strip.show();
    delay(fart);
  }
}

void loop() {
  
  trafikk();
  rainbowCycle(20);
  oyne(2, 500, red);
  oyne(1, 400, blue);
  oyne(3, 150, green);

}

void trafikk() {
  settlys(3,red);
  settlys(2,off);
  settlys(1,off);
  settlys(0,green);
  delay(1500);
  settlys(2,yellow);
  delay(700);
  settlys(3,off);
  settlys(2,off);
  settlys(1,green);
  settlys(0,red);
  delay(2000);
  settlys(3,off);
  settlys(2,yellow);
  settlys(1,off);
  delay(1000);
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

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
