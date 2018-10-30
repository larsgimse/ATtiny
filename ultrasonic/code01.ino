#include "Ultrasonic.h"
#include <Adafruit_NeoPixel.h>
#define PIN 1
#define NUM_PIXEL  11
long randNumber;
long randNumber2;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXEL, PIN, NEO_GRBW + NEO_KHZ800);

int LED1 = 0;  // LED1 Pin
int TRIG = 2; // Trigger Pin
int ECHO = 3; // Echo Pin
int Range; // The range of the object from the HC-SR04 Ultarsonic Module
int Dist; // The Distance value
int red[3]    = { 255, 0, 0 };
int yellow[3]    = { 255, 255, 0 };
int green[3]    = { 0, 255, 0 };
int blue[3]    = { 0, 0, 255 };
int purple[3]    = { 80, 0, 80 };
int aqua[3]    = { 0, 255, 255 };
int pink[3]    = { 255, 153, 255 };
int off[3]    = { 0, 0, 0 };

Ultrasonic ultrasonic(TRIG,ECHO); // Create and initialize the Ultrasonic object.

void setup() {
  pinMode(LED1, OUTPUT);
  Dist = 50;
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(30);
}

void setcolor(int color[3]) {
  for( int i = 0; i<NUM_PIXEL; i++){
    strip.setPixelColor(i, strip.Color(color[0], color[1], color[2]));
    strip.show();
    }
  }

void loop() {
  Range = ultrasonic.Ranging(CM); // Range is calculated in Centimeters. 
  //Range = ultrasonic.Ranging(INC); // Range is calculated in Inches.
 
  if (Range < Dist) { 
    digitalWrite(LED1, HIGH);
    setcolor(red);
  } else if (Range > Dist) { 
    digitalWrite(LED1, LOW);
    setcolor(green);
  }

}
