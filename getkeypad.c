#include <xc.h>
#include "main_project.h"
#define DA PORTDbits.RD0 // Define data available from encoder 



char getkeypad(void)
{
unsigned char value_needed[]={'1','2','3','F','4','5','6','E','7','8','9','D','A','0','B','c' }; //look up table for inputs to encoder, index is binary expression
// char value_used; //value used from look up table
 int selection,selection2; //Declare for variable needed to perform lookup
 unsigned char value_used;
 int switchvalue0,switchvalue1,switchvalue2,switchvalue3; //declares input reading variables

 while(1){ //loop scanning process
 
if(DA==1)
{   _delay(80000); //80ms delay to act as software debounce, also assists physical debounce circuit    
    selection= (PORTC & 0x0F); //Selection is the variable used to performed lookup, PORTC in binary expression also preserves inputs for rc0 to rc3. This statement reads input.
   _delay(80000);
   selection2= (PORTC & 0x0F);
   if(selection2=selection)
   {
    value_used= value_needed[selection]; //convert binary input into character through look up table
   }
   return value_used;
} //Execute if data available is 1

    
   } 
  
} //Main     
  
