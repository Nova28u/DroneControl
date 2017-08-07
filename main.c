#include <xc.h>
#include "main_project.h"
#define DA PORTDbits.RD0 // Define data available from encoder

#define LCD_DATA PORTA
#define LCD_RS PORTAbits.RA0
#define LCD_E PORTBbits.RB1
#define SET 0b00111000
#define D1C1 0b00001100
#define ENTRY 0b00000110
#define CLEAR 0b00000001
#define HOME 0b00000010//for LCD



char getkeypad(void);
void safeteysound(void);
void warningsound(void);

void main(void) {
  
    
ADCON1 = 0x0F;         //allow usage of digital inputs for all pins
TRISA = 0b00111111;    //Declare extra output pins for LCD 
TRISB = 0b11001111;    //Declare inputs from RB0 to RB3 and output from RB4 and RB5 ignore RB6 and RB7 note: RB5 is speaker
TRISC = 0b00000000;    //Declare output pins for LCD
TRISD = 0b00000000;    //Declare outputs for 7 segment
TRISE = 0b00000000;    //LCD selector
char autodecision,tiltangle1,direction;
int invalid1,invalid2,invalid3;//loop back to first condition of if else statements

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
    
        warningsound();//playsound1
        
        //decrement tiltangle1 to zero
        
        safetysound();//playsound2
    

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

char getkeypad(void)
{
 char value_needed[]={'1','2','3','F','4','5','6','E','7','8','9','D','A','0','B','c' }; //look up table for inputs to encoder, index is binary expression
// char value_used; //value used from look up table
 int selection,selection2; //Declare for variable needed to perform lookup
 char value_used;
 

 while(1){ //loop scanning process
 
if(DA==1)
{   _delay(80000); //80ms delay to act as software debounce, also assists physical debounce circuit    
    selection= (PORTC & 0x0F); //Selection is the variable used to performed lookup, PORTC in binary expression also preserves inputs for rc0 to rc3. This statement reads input.
   _delay(80000);
   selection2= (PORTC & 0x0F);
   if(selection2==selection)
   {
    value_used= value_needed[selection]; //convert binary input into character through look up table
   }
   return value_used;
   
} //Execute if data available is 1

    
   } 
 
  return value_used;
} //keypad     
  

char MESS[][32] = {
				{"PRESS C TO FLY STRAIGHT"},
				{"INPUT TILT SIMULATION"},
				{"TILT CORRECTED"},
				{"SELECT TURN DIRECTION"},
				{"TURNING RIGHT"},
				{"TURNING LEFT"},
				{"INVALID INPUT"}
				};

void lcdmessage()
{
	unsigned char i;
	int m=1;
    int e;
    char CW[5]={0b00111000,0b00001100,0b00000110,0b00000001,0b00000010};
	ADCON1=0x0F;
	TRISA=0b11111100;
	TRISC=0b00000000;
	
    SET;
	_delay(1);
	D1C1;
	_delay(1);
	ENTRY;
	_delay(1);
	CLEAR;
	_delay(1);
	HOME;
	_delay(1);//Init LCD replacement
    
    
	m= PORTC & 0xf;
	TRISC=m;
	for(i=0;MESS[m][i]!=0;i++)
		LCD_sendData(MESS[m][i]);
}


void LCD_sendCW(char e)
{
	LCD_RS=0;
	LCD_E=1;
	LCD_DATA=CW[e];
	LCD_E=0;
	_delay(1000);
}

void LCD_sendData(char e)
{
	LCD_RS=0;
	LCD_E=1;
	LCD_DATA=e;
	LCD_E=0;
	_delay(500);
}

sevensegment(char autodecision)
{
int lcd[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000,0b1111111,0b1111011};   //CC lookup table
int DEGREE = 0, HN = 0, LN = 0;
int t;

	while(1)
		{
			if(autodecision=='C')
				{
				LN = DEGREE%10; //Finding the Lower Number
				HN = DEGREE/10; //Finding the Higher Number

				for(t=0;t<1000;t++)
					{
						PORTE = 0b00000001;
						PORTD = lcd[LN];  //writing to LCD
						_delay(500); //setting time delay so we can see the lower number in a long enough time
					}
				for(t=0;t<1000;t++)
					{
						PORTE = 0b00000010;
						PORTD = lcd[HN]; //writing to LCD
						_delay(500); //setting time delay so we can see the higher number in a long enough time
					}
				LN = 0;
				HN = 0; //resetting write cache
				}
			else if(autodecision=='D')
				{
				while(DEGREE>0)
					{
					for(t=0;t<1000;t++)
					{
						LN = DEGREE%10; //Finding the Lower Number
						HN = DEGREE/10; //Finding the Higher Number
						
						PORTE = 0b00000001;
						PORTD = lcd[LN];  //writing to LCD
						_delay(500); //setting time delay so we can see the lower number in a long enough time
						
						PORTE = 0b00000010;
						PORTD = lcd[HN]; //writing to LCD
						_delay(500); //setting time delay so we can see the higher number in a long enough time
						
						DEGREE/1.1;
					}
					}
				}
	}
return autodecision;
}// end of seven segment


void safetysound(void){
int x;
for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(758);
            PORTAbits.RA4=0;
            _delay(758);
        }
        for(x=0;x<1500;x++)
        {
        PORTAbits.RA4=0;
        }
          for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(758);
            PORTAbits.RA4=0;
            _delay(758);
        }
        for(x=0;x<3000;x++)
        {
        PORTAbits.RA4=0;
        }
        for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(758);
            PORTAbits.RA4=0;
            _delay(758);
        }
        for(x=0;x<3000;x++)
        {
        PORTAbits.RA4=0;
        }
        for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(980);
            PORTAbits.RA4=0;
            _delay(980);
        }
        for(x=0;x<1000;x++)
        {
        PORTAbits.RA4=0;
        }
        for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(758);
            PORTAbits.RA4=0;
            _delay(758);
        }
        for(x=0;x<3000;x++)
        {
        PORTAbits.RA4=0;
        }
        for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(649);
            PORTAbits.RA4=0;
            _delay(649);
        }
         for(x=0;x<5500;x++)
        {
        PORTAbits.RA4=0;
        }
        for (x=0;x<20;x++)
        {
            PORTAbits.RA4=1;
            _delay(1316);
            PORTAbits.RA4=0;
            _delay(1316);
        }
         for(x=0;x<5750;x++)
        {
        PORTAbits.RA4=0;
        }
}//end of sound

void warningsound(void){
    int x;
for (x=0;x<200;x++)
        {
            PORTEbits.RE0=1;
            _delay(568);
            PORTEbits.RE0=0;
            _delay(269);
        }
          for (x=0;x<600;x++)
        {
            PORTEbits.RE0=1;
            _delay(239);
            PORTEbits.RE0=0;
            _delay(239);
        }
}//end of sound




