


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
TRISE = 0b00000000;    //LCD selector
char autodecision,tiltangle1,direction;
int invalid1,invalid2,invalid3;

while(1){
    
 
    do{  
    
    invalid1=0;
    // "C autopilot
    // D to turn"

    autodecision=getkeypad();
        
    if(autodecision=='C'){
    
        //"input tilt 
        // 90 max"
    
        tiltangle1= getkeypad();
    
        //"A=left
        //B=right"
    
        direction= getkeypad();
  
        do{
            invalid2=0;
            
            if(direction=='A'){
            //"turning left"
            //display tilt angle
            }

            else if(direction=='B'){
            //"turning right"
            //display tilt angle
            }
            else{
            //"invalid input"
                 invalid2=1;
            } 
        }while(invalid2==1);   
    
        //playsound1
        
        //decrement tiltangle1 to zero
        
        //playsound2
    

        }//if1

    else if(autodecision=='D'){
   
        //"A=left
        //B=right"
        direction= getkeypad();
        
        do{ 
        
        invalid3=0;    
        
       
            if(direction=='B'){ //"turning right"
                 //display turn angle 15 
            }
           
    
       
            else if(direction=='A'){ //"Turing left"
                 //display turn angle 15
            }
           
            
       
                else{//"invalid input"
                    invalid3=1;}
                    
        
        }while(invalid3==1); //do while loop to check direction for manual turn
                
        
    }//if2

    else{
        //"invalid input"
        invalid1=1;
    }

        }while(invalid1==1); //check autodecision for auto or not and loop again if invalid

}//large while 

}//main



