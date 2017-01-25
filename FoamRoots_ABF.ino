#include "FastLED.h"

#define NUM_LEDS_A 161
#define NUM_LEDS_B 176
#define NUM_LEDS_F 72

#define DATA_PIN_A 12
#define CLOCK_PIN_A 13
#define DATA_PIN_B 10
#define CLOCK_PIN_B 11
#define DATA_PIN_F 8
#define CLOCK_PIN_F 9

byte hue = 0;


CRGB leds_A[NUM_LEDS_A];
CRGB leds_B[NUM_LEDS_B];
CRGB leds_F[NUM_LEDS_F];


void setup() { 
//Serial.begin(9600);
  
	LEDS.addLeds<APA102,DATA_PIN_A,CLOCK_PIN_A,BGR>(leds_A,NUM_LEDS_A);
	LEDS.addLeds<APA102,DATA_PIN_B,CLOCK_PIN_B,BGR>(leds_B,NUM_LEDS_B);
	LEDS.addLeds<APA102,DATA_PIN_F,CLOCK_PIN_F,BGR>(leds_F,NUM_LEDS_F);
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
      case 1:  fill_solid( &(leds_A[NUM_LEDS_A-102]), 102, CHSV( 28, 255, 255) ); break;
      case 2:  fill_solid( &(leds_B[NUM_LEDS_B-102]), 102, CHSV( 224, 255, 255) ); break;
      case 3:  break;
      case 4:  break;
      case 5:  break;
      case 6:  break;
      case 7:  break;
      case 8:  break;
      case 9:  break;
      case 10: fill_solid( &(leds_A[NUM_LEDS_A-102]), 102, CHSV( 28, 255, 255) ); fill_solid( &(leds_B[NUM_LEDS_B-102]), 102, CHSV( 224, 255, 255) ); break;
      case 11: break;
      case 12: break;
      case 13: break;
      case 14: break;
      case 15: break;
      case 16: fill_solid( &(leds_A[NUM_LEDS_A-102]), 102, CHSV( 28, 255, 255) ); fill_solid( &(leds_B[NUM_LEDS_B-102]), 102, CHSV( 224, 255, 255) ); break;
      case 17: break;
      case 18: break;
      case 19: break;
      case 20: break;
    }
  }
}

void rainbow_hole(){
fill_rainbow(leds_F, NUM_LEDS_F, hue, 1 );
hue++;

}

void root_Motion(){
for (int i=0; i<NUM_LEDS_A-1; i++){
leds_A[i]=leds_A[i+1];
}
for (int i=0; i<NUM_LEDS_B-1; i++){
leds_B[i]=leds_B[i+1];
}
}



void fadeall() { 
for(int i = 0; i < NUM_LEDS_A; i++) { leds_A[i].nscale8(240); } 
for(int i = 0; i < NUM_LEDS_B; i++) { leds_B[i].nscale8(240); }



}

