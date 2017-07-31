


#include <xc.h>
#include "main_project.h"
char getkeypad(void);
int playsound1(void);
int playsound2(void);

//message functions declare here later
void main(void) {
    
ADCON1 = 0x0F;         //allow usage of digital inputs for all pins
TRISA = 0b00111111;    //Declare extra output pins for LCD
TRISB = 0b11001111;    //Declare inputs from RB0 to RB3 and output from RB4 and RB5 ignore RB6 and RB7 note: RB5 is speaker
TRISC = 0b00000000;    //Declare output pins for LCD
TRISD = 0b00000000;    //Declare outputs for 7 segment
TRISE = 0b00000000;   //LCD selector
char keypad_input;

//"press C to fly straight"

int getkeypad()













    
}   
    
 
