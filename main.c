#include <xc.h>
#include "main_project.h"

#define LEDRED PORTAbits.RA2
#define LEDYELLOW PORTAbits.RA3
#define LEDGREEN PORTAbits.RA4

#define LCD_DATA PORTC
#define LCD_RS PORTAbits.RA0
#define LCD_E PORTAbits.RA1
#define SET LCD_sendCW(0b00111000)
#define D1C1 LCD_sendCW(0b00001100)
#define ENTRY LCD_sendCW(0b00000110)
#define CLEAR LCD_sendCW(0b00000001)
#define HOME LCD_sendCW(0b00000010)


void initLCD(void);
void LCD_sendCW(char x);
void LCD_sendData(char x);

char getkeypad();
void safetysound();
void warningsound();
void sevensegmentC();
void sevensegmentD();

void main(){
  
    
ADCON1 = 0x0F;         //allow usage of digital inputs for all pins
TRISA = 0b11100000;    //Declare extra output pins for LCD 
TRISB = 0b11001111;    //Declare inputs from RB0 to RB3 and output from RB4 and RB5 ignore RB6 and RB7 note: RB5 is speaker
TRISC = 0b00000000;    //Declare output pins for LCD
TRISD = 0b00000000;    //Declare outputs for 7 segment
TRISE = 0b00000000;    //LCD selector

char autodecision,tiltangle1,direction;
char i;
int m,z,checker;
char x;

checker=0;

PORTE=0b00000001;
PORTD=0b11111111;
PORTE=0b00000010;
PORTD=0b11111111; //clear 7 segment

char MESS[][16] = {
				{"C TO AUTOPILOT"},
                {"D TO STEER"},
				{"INPUT TILT"},
                {"90 MAX"},
				{"A=LEFT"},
                {"B=RIGHT"},
				{"UAV"},
                {"TURNING LEFT"},
				{"UAV"},
                {"TURNING RIGHT"},
				{"INVALID/NO INPUT"},
                {"FLIGHT CONTINUES"},
                {"WELCOME TO UAV"},
                {"SIMULATOR 2017"}
                
               
                
};
LEDRED=1;
LEDYELLOW=1;
LEDGREEN=1;


        initLCD();
        LCD_sendCW(0b00000110);
		m=6*2;
		for(i=0;MESS[m][i]!=0;i++)
			LCD_sendData(MESS[m][i]);
        
        LCD_sendCW(0b11000000); //Next Line
        for(i=0;MESS[m+1][i]!=0;i++)
			LCD_sendData(MESS[m+1][i]);
        
        for(z=0;z<1000;z++){_delay(10000);}
        
		LCD_sendCW(0b00000001);

LEDRED=0;
LEDYELLOW=0;
LEDGREEN=0;      
       
    
    while(1){
        
   
       
        
        initLCD(); 
    
		LCD_sendCW(0b00000110);
		m=0*2;
		for(i=0;MESS[m][i]!=0;i++)
			LCD_sendData(MESS[m][i]);
        
        LCD_sendCW(0b11000000); //Next Line
        for(i=0;MESS[m+1][i]!=0;i++)
			LCD_sendData(MESS[m+1][i]);
        
        for(z=0;z<1000;z++){_delay(10000);}
        
		LCD_sendCW(0b00000001);
	
    // "C to autopilot 
    //   D to steer
   
    autodecision=getkeypad();
    
 
         
       
    if(autodecision=='C'){
         

        

            initLCD(); 

            LCD_sendCW(0b00000110);
            m=2*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(10000);}

            LCD_sendCW(0b00000001);

            //"A=left
            //B=right"

          direction= getkeypad();
        
        
            
            
  
            if(direction=='A'){
                 
                
            initLCD(); 

            LCD_sendCW(0b00000110);
            m=3*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(10000);}

            LCD_sendCW(0b00000001);
	
            //"turning left"
            
                

                initLCD(); 

                LCD_sendCW(0b00000110);
                m=1*2;
                for(i=0;MESS[m][i]!=0;i++)
                    LCD_sendData(MESS[m][i]);

                LCD_sendCW(0b11000000); //Next Line
                for(i=0;MESS[m+1][i]!=0;i++)
                    LCD_sendData(MESS[m+1][i]);

                for(z=0;z<1000;z++){_delay(10000);}

                LCD_sendCW(0b00000001);

                //"input tilt 
                // 90 max"

        
            
                sevensegmentC();
                
            }

            else if(direction=='B'){
                
            

            initLCD(); 

            LCD_sendCW(0b00000110);
            m=4*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(10000);}

            LCD_sendCW(0b00000001);
	
                
            //"turning right"
            
                

                initLCD(); 

                LCD_sendCW(0b00000110);
                m=1*2;
                for(i=0;MESS[m][i]!=0;i++)
                    LCD_sendData(MESS[m][i]);

                LCD_sendCW(0b11000000); //Next Line
                for(i=0;MESS[m+1][i]!=0;i++)
                    LCD_sendData(MESS[m+1][i]);

                for(z=0;z<1000;z++){_delay(10000);}

                LCD_sendCW(0b00000001);

                //"input tilt 
                // 90 max"

        
           
                sevensegmentC();
            }
            
            else{
                
                    

              initLCD(); 

              LCD_sendCW(0b00000110);
              m=5*2;
              for(i=0;MESS[m][i]!=0;i++)
                  LCD_sendData(MESS[m][i]);

              LCD_sendCW(0b11000000); //Next Line
              for(i=0;MESS[m+1][i]!=0;i++)
                  LCD_sendData(MESS[m+1][i]);

              for(z=0;z<1000;z++){_delay(3000);}

              LCD_sendCW(0b00000001);
	  
            //"invalid input"
                 
            }   
    

        }//if1

    else if(autodecision=='D'){
        
        
    
            initLCD(); 

            LCD_sendCW(0b00000110);
            m=2*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(10000);}

            LCD_sendCW(0b00000001);

            //"A=left
            //B=right"

        
        
        
        
        
         direction= getkeypad();
        
              
            if(direction=='B'){ 
                
                
    
            initLCD(); 

            LCD_sendCW(0b00000110);
            m=4*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(10000);}

            LCD_sendCW(0b00000001);

                
                //"turning right"
                sevensegmentD(); 
            }
           
    
       
            else if(direction=='A')
            { 
                
                
            initLCD(); 

            LCD_sendCW(0b00000110);
            m=3*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(10000);}

            LCD_sendCW(0b00000001);
	
                
                //"Turing left"
                sevensegmentD();
            }
           
            
    else{
                
                
    
            initLCD(); 

            LCD_sendCW(0b00000110);
            m=5*2;
            for(i=0;MESS[m][i]!=0;i++)
                LCD_sendData(MESS[m][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESS[m+1][i]!=0;i++)
                LCD_sendData(MESS[m+1][i]);

            for(z=0;z<1000;z++){_delay(3000);}

            LCD_sendCW(0b00000001);
	
                
                //"invalid input"
                    
    }         
        
        
                
        
    }//if2

    else{
        
        
    
        initLCD(); 
    
		LCD_sendCW(0b00000110);
		m=5*2;
		for(i=0;MESS[m][i]!=0;i++)
			LCD_sendData(MESS[m][i]);
        
        LCD_sendCW(0b11000000); //Next Line
        for(i=0;MESS[m+1][i]!=0;i++)
			LCD_sendData(MESS[m+1][i]);
        
        for(z=0;z<1000;z++){_delay(3000);}
        
		LCD_sendCW(0b00000001);
	
        //"invalid input"
         
    }

        

    }//while(1)
}//main


char getkeypad(){
    

char value_needed[]={'1','2','3','F','4','5','6','E','7','8','9','D','A','0','B','C' }; //look up table for inputs to encoder, index is binary expression
// char value_used; //value used from look up table
 char selection,selection2; //Declare for variable needed to perform lookup
 char value_used;

 
 
   selection= (PORTB & 0x0F); //Selection is the variable used to performed lookup, PORTC in binary expression also preserves inputs for rc0 to rc3. This statement reads input.
   _delay(80000);//software debounce
   selection2 = (PORTB & 0x0F);
   
   if(selection2==selection)
   {
    value_used = value_needed[selection]; 
          }

 return value_used;

} //keypad    



void sevensegmentD(void)
{
int display[10] = {0b00000011, 0b10011111, 0b00100101, 0b00001101, 0b10011001, 0b01001001, 0b01000001, 0b00011111,0b00000001,0b00011001};   //CC lookup table
int  HN = 0, LN = 0;
int t;

	
LEDYELLOW=1;
				HN = 1; //Finding the Lower Number
				LN = 5; //Finding the Higher Number

				for(t=0;t<10000;t++)
            		{
                        PORTE = 0b00000001;
                        PORTD = display[LN];  //writing to LCD
                    	_delay(500); //setting time delay so we can see the lower number in a long enough time
                	
               	
                        PORTE = 0b00000010;
                        PORTD = display[HN]; //writing to LCD
                        _delay(500);
                    }
      
LEDYELLOW=0;               
                
				PORTE=0b00000001;
                
                PORTD=0b11111111;
                PORTE=0b00000010;
                PORTD=0b11111111; //clear 7 segment
				

}

void sevensegmentC(void)
{
int display[10] = {0b00000011, 0b10011111, 0b00100101, 0b00001101, 0b10011001, 0b01001001, 0b01000001, 0b00011111,0b00000001,0b00011001};   //CC lookup table
int  HN = 0, LN = 0;
int t,z,i,result;
char x;
char MESSspecial[4][16] = {
				
                {"INPUT BIG NO"},
                {"BOI"},
                {"INPUT SMALL NO"},
                {"BOI"}      };

            
    
            initLCD(); 

            LCD_sendCW(0b00000110);
           
            for(i=0;MESSspecial[0][i]!=0;i++)
            LCD_sendData(MESSspecial[0][i]);

            LCD_sendCW(0b11000000); //Next Line
            for(i=0;MESSspecial[1][i]!=0;i++)
                LCD_sendData(MESSspecial[1][i]);

            for(z=0;z<1000;z++){_delay(5000);}

            LCD_sendCW(0b00000001);
	
                
                //"INPUT BIG NO, BOI"
                    

						HN = getkeypad()-'0'; //Finding the Lower Number char to int
                       
                        
                         
                    initLCD(); 

                    LCD_sendCW(0b00000110);
                    
                    for(i=0;MESSspecial[2][i]!=0;i++)
                        LCD_sendData(MESSspecial[2][i]);

                    LCD_sendCW(0b11000000); //Next Line
                    for(i=0;MESSspecial[3][i]!=0;i++)
                        LCD_sendData(MESSspecial[3][i]);

                    for(z=0;z<1000;z++){_delay(5000);}

                    LCD_sendCW(0b00000001);

                
                //"INPUT SMALL NO, BOI" 
                        
                        
                        
						LN = getkeypad()-'0'; //Finding the Higher Number char to int
                        
						for(t=0;t<5000;t++)
                        {
                    	
						PORTE = 0b00000001;
						PORTD = display[LN];  //writing to LCD
						_delay(500); //setting time delay so we can see the lower number in a long enough time
                    
                        
						PORTE = 0b00000010;
						PORTD = display[HN]; //writing to LCD
						_delay(500); //setting time delay so we can see the higher number in a long enough time
                       
                        }
                        
                        do{
                        
                            
                        LEDRED=1;
                            
                        warningsound();//beep boop beep boop danger
                        
                        result=((HN*10)+LN)/1.1;
                        HN=result/10;
                        LN=result%10;
                        
                        
                        
                        for(t=0;t<1000;t++)
                        {
                        
                    	
						PORTE = 0b00000001;
						PORTD = display[LN];  //writing to LCD
						_delay(500); //setting time delay so we can see the lower number in a long enough time
                    
                        
						PORTE = 0b00000010;
						PORTD = display[HN]; //writing to LCD
						_delay(500); //setting time delay so we can see the higher number in a long enough time
                        
                        
                        }
                        
                        LEDRED=0;
                        
                        }while((HN*10+LN)>0);
                      
                        LEDGREEN=1;
                        
                        safetysound();
                        
                        LEDGREEN=0;
                        
                        PORTD=0b11111111;
                        PORTE=0b00000010;
                        PORTD=0b11111111; //clear 7 segment
                        
}// end of seven segment

void safetysound(void){
int x;
for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(758);
            PORTBbits.RB5=0;
            _delay(758);
        }
        for(x=0;x<1500;x++)
        {
        PORTBbits.RB5=0;
        }
          for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(758);
            PORTBbits.RB5=0;
            _delay(758);
        }
        for(x=0;x<3000;x++)
        {
        PORTBbits.RB5=0;
        }
        for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(758);
            PORTBbits.RB5=0;
            _delay(758);
        }
        for(x=0;x<3000;x++)
        {
        PORTBbits.RB5=0;
        }
        for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(980);
            PORTBbits.RB5=0;
            _delay(980);
        }
        for(x=0;x<1000;x++)
        {
        PORTBbits.RB5=0;
        }
        for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(758);
            PORTBbits.RB5=0;
            _delay(758);
        }
        for(x=0;x<3000;x++)
        {
        PORTBbits.RB5=0;
        }
        for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(649);
            PORTBbits.RB5=0;
            _delay(649);
        }
         for(x=0;x<5500;x++)
        {
        PORTBbits.RB5=0;
        }
        for (x=0;x<30;x++)
        {
            PORTBbits.RB5=1;
            _delay(1316);
            PORTBbits.RB5=0;
            _delay(1316);
        }
         for(x=0;x<5750;x++)
        {
        PORTBbits.RB5=0;
        }
}//end of sound

void warningsound(void){
    int x,a;
    for(a=0;a<2;a++)
    {
        for(x=0;x<50;x++)
        {
            PORTBbits.RB5=1;
            _delay(1260);
            PORTBbits.RB5=0;
            _delay(1260);
        }
 
        for(x=0;x<5000;x++)
        {
        PORTBbits.RB5=0;
        }
    }
}//end of sound

