//port 13
#define BLACK 0x0000

#include "FastLED.h"

#define STRIP_2 10 //ssd
#define STRIP_3 10 //ssd
#define STRIP_4 33 //gpu
#define STRIP_5 12 
#define STRIP_6 12 //fan
#define STRIP_7 12 //fan
#define STRIP_8 5
#define STRIP_9 5

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 255

CRGB leds_2[STRIP_2];
CRGB leds_3[STRIP_3];
CRGB leds_4[STRIP_4];
CRGB leds_5[STRIP_5];
CRGB leds_6[STRIP_6];
CRGB leds_7[STRIP_7];
CRGB leds_8[STRIP_8];
CRGB leds_9[STRIP_9];
        
void setup() {    
  FastLED.addLeds<LED_TYPE, 2,COLOR_ORDER>(leds_2, STRIP_2).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 3,COLOR_ORDER>(leds_3, STRIP_3).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 4,COLOR_ORDER>(leds_4, STRIP_4).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 5,COLOR_ORDER>(leds_5, STRIP_5).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 6,COLOR_ORDER>(leds_6, STRIP_6).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 7,COLOR_ORDER>(leds_7, STRIP_7).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 8,COLOR_ORDER>(leds_8, STRIP_8).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 9,COLOR_ORDER>(leds_9, STRIP_9).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);// global brightness
  Serial.begin(9600);
}

//******* Main program **************************************************
void loop() {   
  randomSeed(millis());
  //int wait=random(10,30);
  int wait= 5;
  //int dim=random(4,6);
  int dim=1;
  int max_cycles=8;
  //int cycles=random(1,max_cycles+1); 
  int cycles= 1; 

  //*** Working ***
  //rainbowCycle(wait, cycles, dim);
  //fade(wait, cycles, dim);
  single_color(); 
  //leds_off();
}

//********* Efects *******************************************************

void one_color(uint8_t r_2, uint8_t g_2, uint8_t b_2, uint8_t BRIGHTNESS_2, 
               uint8_t r_3, uint8_t g_3, uint8_t b_3, uint8_t BRIGHTNESS_3, 
               uint8_t r_4, uint8_t g_4, uint8_t b_4, uint8_t BRIGHTNESS_4, 
               uint8_t r_5, uint8_t g_5, uint8_t b_5, uint8_t BRIGHTNESS_5,
               uint8_t r_6, uint8_t g_6, uint8_t b_6, uint8_t BRIGHTNESS_6,
               uint8_t r_7, uint8_t g_7, uint8_t b_7, uint8_t BRIGHTNESS_7) {
  for (int i = 0; i < STRIP_2; ++i) { leds_2[i] = CRGB( r_2, g_2, b_2); }
  for (int i = 0; i < STRIP_3; ++i) { leds_3[i] = CRGB( r_3, g_3, b_3); }
  for (int i = 0; i < STRIP_4; ++i) { leds_4[i] = CRGB( r_4, g_4, b_4); }
  for (int i = 0; i < STRIP_5; ++i) { leds_5[i] = CRGB( r_5, g_5, b_5); }
  for (int i = 0; i < STRIP_6; ++i) { leds_6[i] = CRGB( r_6, g_6, b_6); }
  for (int i = 0; i < STRIP_7; ++i) { leds_7[i] = CRGB( r_7, g_7, b_7); }

  FastLED[0].showLeds(BRIGHTNESS_2);
  FastLED[1].showLeds(BRIGHTNESS_3);
  FastLED[2].showLeds(BRIGHTNESS_4);
  FastLED[3].showLeds(BRIGHTNESS_5);
  FastLED[4].showLeds(BRIGHTNESS_6);
  FastLED[5].showLeds(BRIGHTNESS_7);
}

void leds_off() {
  for (int i = 0; i < 60; ++i) {        
    leds_2[i] = BLACK; 
    leds_3[i] = BLACK; 
    leds_4[i] = BLACK; 
    leds_5[i] = BLACK; 
    leds_6[i] = BLACK; 
    leds_7[i] = BLACK; 
    FastLED.show();
  }
}


void rainbowCycle(int wait, int cycles, int dim) {
  for(int cycle=0; cycle < cycles; cycle++){
    byte dir=0;
    int k=255;
    
    for (int j=0; j < 256; j++,k--) { 
      if(k<0) {
        k=255;
      }
      
      for(int i=0; i<STRIP_2; i++) {
        CRGB ledColor = wheel(((i * 256 / STRIP_2) + (dir==0?j:k)) % 256,dim);        
        leds_2[i]=ledColor;        
      }
      for(int i=0; i<STRIP_3; i++) {
        CRGB ledColor = wheel(((i * 256 / STRIP_3) + (dir==0?j:k)) % 256,dim);        
        leds_3[i]=ledColor;        
      }
      for(int i=0; i<STRIP_4; i++) {
        CRGB ledColor = wheel(((i * 256 / STRIP_4) + (dir==0?j:k)) % 256,dim);        
        leds_4[i]=ledColor;        
      }
      for(int i=0; i<STRIP_5; i++) {
        CRGB ledColor = wheel(((i * 256 / STRIP_5) + (dir==0?j:k)) % 256,dim);        
        leds_5[i]=ledColor;        
      }
      for(int i=0; i<STRIP_6; i++) {
        CRGB ledColor = wheel(((i * 256 / STRIP_6) + (dir==0?j:k)) % 256,dim);        
        leds_6[i]=ledColor;        
      }
      for(int i=0; i<STRIP_7; i++) {
        CRGB ledColor = wheel(((i * 256 / STRIP_7) + (dir==0?j:k)) % 256,dim);        
        leds_7[i]=ledColor;        
      }
      
      FastLED.show();
      FastLED.delay(wait);
    }
  }
}

void fade(int wait, int cycles, int dim) {
  for(int cycle=0; cycle < cycles; cycle++){
    byte dir=0;
    int k=255;
    
    for (int j=0; j < 256; j++,k--) { 
      if(k<0) {
        k=255;
      }
      
      for(int i=0; i<12; i++) {
        CRGB ledColor = wheel(((i * 256 / 33) + (dir==0?j:k)) % 256,dim);       
        //Serial.println(ledColor);
        leds_2[i]=ledColor; 
        leds_3[i]=ledColor; 
        leds_4[i]=ledColor;    
        leds_5[i]=ledColor;     
        leds_6[i]=ledColor; 
        leds_7[i]=ledColor; 
      }
      
      FastLED.show();
      FastLED.delay(10);
    }
  }
}

//********* Help method ***********************************************
CRGB wheel(int WheelPos, int dim) {
  CRGB color;
  if (85 > WheelPos) {
   color.r=0;
   color.g=WheelPos * 3/dim;
   color.b=(255 - WheelPos * 3)/dim;;
  } 
  else if (170 > WheelPos) {
   color.r=WheelPos * 3/dim;
   color.g=(255 - WheelPos * 3)/dim;
   color.b=0;
  }
  else {
   color.r=(255 - WheelPos * 3)/dim;
   color.g=0;
   color.b=WheelPos * 3/dim;
  }
  return color;
}

void single_color(){
  uint8_t r_2 = 0;
  uint8_t g_2 = 0; 
  uint8_t b_2 = 255; 
  uint8_t BRIGHTNESS_2 = 255; 
  
  uint8_t r_3 = 0;
  uint8_t g_3 = 0;
  uint8_t b_3 = 255;
  uint8_t BRIGHTNESS_3 = 255; 
  
  uint8_t r_4 = 0;
  uint8_t g_4 = 0;
  uint8_t b_4 = 255;
  uint8_t BRIGHTNESS_4 = 255;
  
  uint8_t r_5 = 0;
  uint8_t g_5 = 0;
  uint8_t b_5 = 255;
  uint8_t BRIGHTNESS_5 = 255;
               
  uint8_t r_6 = 0;
  uint8_t g_6 = 0;
  uint8_t b_6 = 255;
  uint8_t BRIGHTNESS_6 = 50;

  uint8_t r_7 = 0;
  uint8_t g_7 = 0;
  uint8_t b_7 = 255;
  uint8_t BRIGHTNESS_7 = 50;

  one_color(r_2, g_2, b_2, BRIGHTNESS_2, 
            r_3, g_3, b_3, BRIGHTNESS_3,
            r_4, g_4, b_4, BRIGHTNESS_4,
            r_5, g_5, b_5, BRIGHTNESS_5,
            r_6, g_6, b_6, BRIGHTNESS_6,
            r_7, g_7, b_7, BRIGHTNESS_7);
}
