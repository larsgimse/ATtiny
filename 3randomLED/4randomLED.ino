int leds[4] = {0,1,2,3};

void setup(){
  for (int jj; jj<sizeof(leds)/sizeof(int);jj++){
    pinMode(leds[jj],OUTPUT);
    delay(10);
  }
}

void loop(){
  digitalWrite(leds[random(0,sizeof(leds)/sizeof(int))],HIGH);
  delay(random(20,200));
  digitalWrite(leds[random(0,sizeof(leds)/sizeof(int))],LOW);
}
