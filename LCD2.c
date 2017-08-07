void lcdmessage(){
	unsigned char i;
	int m;
    	int x;
	
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
    
    while(1){
		LCD_sendCW(0b00000110);
		m= PORTC & 0xf;
		for(i=0;MESS[m][i]!=0;i++)
			LCD_sendData(MESS[m][i]);
		LCD_sendCW(0b00000001);
	}
}

void LCD_sendCW(char x)
{
	LCD_RS=0;
	LCD_E=1;
	LCD_DATA=x;
	LCD_E=0;
	_delay(1000);
}

void LCD_sendData(char x)
{
	LCD_RS=0;
	LCD_E=1;
	LCD_DATA=x;
	LCD_E=0;
	_delay(500);
}
