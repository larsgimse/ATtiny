//colors from http://www.99colors.net/hex-colors

#include <Adafruit_NeoPixel.h>
#define PIN 0
#define NUM_LEDS 3
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int random_20 = random(19);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}



void loop() {
  random_20 = random(19);
  switch (random_20) {
        case 0:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0x03, 0x3e); } break; //american rose
        case 1:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0xff, 0xff); } break; //white 
        case 2:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0x1e, 0x90, 0xff); } break; //dodger blue
        case 3:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0xc0, 0xcb); } break; //pink
        case 4:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0x00, 0xff, 0x00); } break; //green
        case 5:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0xbf, 0x00); } break; //amber
        case 6:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0x00, 0xff, 0xff); } break; //agua 
        case 7:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0x00, 0xbf, 0xff); } break; //capri
        case 8:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xdf, 0xff, 0x00); } break; //chartreuse
        case 9:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0x7f, 0x50); } break; //coral
        case 10:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xbf, 0x00, 0xff); } break; //electric purple
        case 11:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0x8c, 0x00); } break; //dark orange 
        case 12:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xbf, 0x00, 0xff); } break; //electric purple
        case 13:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0x28, 0x00); } break; //ferrari red
        case 14:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xad, 0xff, 0x2f); } break; //green yellow
        case 15:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0xff, 0xf0); } break; //ivory
        case 16:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0xf0, 0xf5); } break; //lavender blush 
        case 17:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0xff, 0xf7, 0x00); } break; //lemon
        case 18:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0x98, 0xff, 0x98); } break; //mint green
        case 19:
          for(int f=0; f<random(1,4)*10; f++) { FadeInOut(0x00, 0xff, 0x3c); } break; //green
    }
}

void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
      
  for(int k = 0; k < 256; k=k+1) { 
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
    delay(10);
  }
delay(6000);     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    showStrip();
    delay(60);
  }
}


void showStrip() {
   strip.show();

}

void setPixel(int Pixel, byte red, byte green, byte blue) {
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}
