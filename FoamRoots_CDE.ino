#include "FastLED.h"

#define NUM_LEDS_C 228
#define NUM_LEDS_D 255
#define NUM_LEDS_E 72

#define DATA_PIN_C 2
#define CLOCK_PIN_C 3
#define DATA_PIN_D 4
#define CLOCK_PIN_D 5
#define DATA_PIN_E 6
#define CLOCK_PIN_E 7

byte hue = 0;


CRGB leds_C[NUM_LEDS_C];
CRGB leds_D[NUM_LEDS_D];
CRGB leds_E[NUM_LEDS_E];


void setup() { 
//Serial.begin(9600);
  
	LEDS.addLeds<APA102,DATA_PIN_C,CLOCK_PIN_C,BGR>(leds_C,NUM_LEDS_C);
	LEDS.addLeds<APA102,DATA_PIN_D,CLOCK_PIN_D,BGR>(leds_D,NUM_LEDS_D);
	LEDS.addLeds<APA102,DATA_PIN_E,CLOCK_PIN_E,BGR>(leds_E,NUM_LEDS_E);


	LEDS.setBrightness(255);
}



void loop() { 
  
Clock();
rainbow_hole();
FastLED.show(); 
root_Motion();
EVERY_N_MILLIS(70){fadeall();}
}

void Clock(){
  uint8_t secondHand = (millis() / 750) % 21;                 // Change '60' to a different value to change length of the loop.
  static uint8_t lastSecond = 99;                                // Static variable, means it's only defined once. This is our 'debounce' variable.
  if (lastSecond != secondHand) {                               // Debounce to make sure we're not repeating an assignment.
    lastSecond = secondHand;
//Serial.println(secondHand);
    switch(secondHand) {

      case 0:  break;
      case 1:  break;
      case 2:  break;
      case 3:  fill_solid( &(leds_C[NUM_LEDS_C-102]), 102, CHSV( 64, 255, 255) ); break;
      case 4:  fill_solid( &(leds_D[NUM_LEDS_D-102]), 102, CHSV( 0, 255, 255) ); break;
      case 5:  break;
      case 6:  break;
      case 7:  break;
      case 8:  break;
      case 9:  break;
      case 10: fill_solid( &(leds_C[NUM_LEDS_C-102]), 102, CHSV( 64, 255, 255) ); fill_solid( &(leds_D[NUM_LEDS_D-102]), 102, CHSV( 0, 255, 255) ); break;
      case 11: break;
      case 12: break;
      case 13: break;
      case 14: break;
      case 15: break;
      case 16: fill_solid( &(leds_C[NUM_LEDS_C-102]), 102, CHSV( 64, 255, 255) ); fill_solid( &(leds_D[NUM_LEDS_D-102]), 102, CHSV( 0, 255, 255) ); break;
      case 17: break;
      case 18: break;
      case 19: break;
      case 20: break;      
    }
  }
}

void rainbow_hole(){
fill_rainbow(leds_E, NUM_LEDS_E, hue, 1 );
hue++;

}

void root_Motion(){
for (int i=0; i<NUM_LEDS_C-1; i++){
leds_C[i]=leds_C[i+1];
}
for (int i=0; i<NUM_LEDS_D-1; i++){
leds_D[i]=leds_D[i+1];
}
}



void fadeall() { 
for(int i = 0; i < NUM_LEDS_C; i++) { leds_C[i].nscale8(240); } 
for(int i = 0; i < NUM_LEDS_D; i++) { leds_D[i].nscale8(240); }



}
