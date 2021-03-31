#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

int sw_1 = 5; //Switch 1
int sw_2 = 4; //Switch 2
int sw_3 = 3; //Switch 3
int sw_4 = 2; //Switch 4
int sw_off = 6; //Switch ON/OFF


// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define DATA_PIN  10
#define CS_PIN    11
#define CLK_PIN   12

MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

int scrollSpeed = 50;    // used to set text scroll speed in Parola at start

// sets scrolling direction if slider in middle at start
textEffect_t scrollEffect = PA_SCROLL_LEFT;

textPosition_t scrollAlign = PA_LEFT;  // how to aligh the text

int scrollPause = 0; // ms of pause after finished displaying message

#define  BUF_SIZE  75  // Maximum of 75 characters
char curMessage[BUF_SIZE] = { "Happy Valentines Day Babe" };  // used to hold current message

void setup() {
  
  pinMode(sw_1, INPUT_PULLUP);
  pinMode(sw_2, INPUT_PULLUP);
  pinMode(sw_3, INPUT_PULLUP);
  pinMode(sw_4, INPUT_PULLUP);
  pinMode(sw_off, INPUT_PULLUP);
  
  // Start Parola
  P.begin();  
  
  // configure Parola
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
}
void loop() {
 
  if (P.displayAnimate() && digitalRead(sw_off) == LOW) // If finished displaying message
  {
   
    if(digitalRead(sw_1) == LOW){
      char newMessage[BUF_SIZE] = { "I'm So Lucky to Have You" };
      strcpy(curMessage, newMessage);
    }
    else if (digitalRead(sw_2) == LOW){
      char newMessage[BUF_SIZE] = { "You're My Everything" };
      strcpy(curMessage, newMessage);
    }
    else if(digitalRead(sw_3) == LOW){
      char newMessage[BUF_SIZE] = { "I'll Be Yours Forever" };
      strcpy(curMessage, newMessage);
    }
    else if (digitalRead(sw_4) == LOW){
      char newMessage[BUF_SIZE] = { "My One and Only Love" };
      strcpy(curMessage, newMessage);
    }
    else
    {
      char newMessage[BUF_SIZE] = { "I Love You to the Moon and Back" };
      strcpy(curMessage, newMessage);
    }
    P.displayReset();  // Reset and display it again 
  }
}
