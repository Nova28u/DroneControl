#include <xc.h>	
#include ‘config.h’
unsigned char lcd[9] = {1111110; 0110000; 1101101; 1111001; 0110011; 1011011; 1011111; 1110000;1111111;1111011;};   //CC lookup table
void main()
{

ADCON1 = 1;
TRISD = 0b0000 0000; //7seg LCD
TRISE = 0b0000 0000; //LCD selector
int DEGREE = 0, HN = 0, LN = 0;

	while(1)
		{
			if(autodecision==0)
				{
				LN = DEGREE%10; //Finding the Lower Number
				HN = DEGREE/10; //Finding the Higher Number

				For(t=0;t<1000;t++)
					{
						PORTE = 0b00000001;
						PORTD = lcd[LN];  //writing to LCD
						delay_(500); //setting time delay so we can see the lower number in a long enough time
					}
				For(t=0;t<1000;t++)
					{
						PORTE = 0b00000010;
						PORTD = lcd[HN]; //writing to LCD
						delay_(500); //setting time delay so we can see the higher number in a long enough time
					}
				LN = 0;
				HN = 0; //resetting write cache
				}
			else if(autodecision==1)
				{
				while(DEGREE>0)
					{
					For(t=0;t<1000;t++)
					{
						LN = DEGREE%10; //Finding the Lower Number
						HN = DEGREE/10; //Finding the Higher Number
						
						PORTE = 0b00000001;
						PORTD = lcd[LN];  //writing to LCD
						delay_(500); //setting time delay so we can see the lower number in a long enough time
						
						PORTE = 0b00000010;
						PORTD = lcd[HN]; //writing to LCD
						delay_(500); //setting time delay so we can see the higher number in a long enough time
						
						DEGREE/1.1;
					}
					}
				}
	}
}
