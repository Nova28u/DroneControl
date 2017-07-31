


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
char v1,v2,v3,v4;


while(1){

v1= getkeypad();

if(v1=='c'){
    
    //"input tilt simulation 90 max"
    v2= getkeypad();
    //playsound1
    //decrement tilt to zero
    //playsound2
   
}//if

else{
   
   //"select turn direction
   v3= getkeypad();

   switch(v3){
        
       case 'A': //"turning right"
                 //display turn angle
           
       break;
       
       case 'B': //"Turing left"
                 //display turn angle
           
           break;


}//switch

}//while

}//main
