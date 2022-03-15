#include <FastLED.h>

#define LED_PIN     35
#define NUM_LEDS    266

CRGB leds[NUM_LEDS];

int four[] = {72, 79, 110, 117, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 155, 186, 193, 224, 41, 212, 205, 174, 167};
int three[] = {41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 72, 79, 110, 117, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 155, 186, 193};
int two[] = {41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 60, 91, 98, 129, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 155, 186, 193};

const int reciever = 47;
int val;
int c = 0;
int z = 0;
/**
 * Mia=
 */
void setup() {
  Serial.begin(9600);
  pinMode(reciever, INPUT_PULLUP);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }
}

void loop() {  
  val = digitalRead(reciever);

  if (val == 1 && z >= 10) {
      leds[c] = CRGB(0, 0, 255);
      FastLED.show();
      c++;
  } else {
    z++;
  }
  if (val == 1) {
    z = 0;  
  }

  if (c == NUM_LEDS) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
      delay(10);
    }
    
    c = 0;
    delay(1000);
    //4
    for (int i = 0; i < 26; i++) {
      leds[four[i]] = CRGB(0, 0, 255);
      FastLED.show();
    }
    delay(500);
    for (int i = 0; i < 26; i++) {
      leds[four[i]] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //3
    for (int i = 0; i < 46; i++) {
      leds[three[i]] = CRGB(0, 0, 255);
      FastLED.show();
    }
    delay(500);
    for (int i = 0; i < 46; i++) {
      leds[three[i]] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //4
    for (int i = 0; i < 26; i++) {
      leds[four[i]] = CRGB(0, 0, 255);
      FastLED.show();
    }
    delay(500);
    for (int i = 0; i < 26; i++) {
      leds[four[i]] = CRGB(0, 0, 0);
      FastLED.show();
    }
    //2
    for (int i = 0; i < 46; i++) {
      leds[two[i]] = CRGB(0, 0, 255);
      FastLED.show();
    }
    delay(500);
    for (int i = 0; i < 46; i++) {
      leds[two[i]] = CRGB(0, 0, 0);
      FastLED.show();
    }

    /*
    while (true) {
      leds[(int) random(265)] = CRGB(0, 0, (int) random(255));
      FastLED.show();
    }
    */
  }
}
