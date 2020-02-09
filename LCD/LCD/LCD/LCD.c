/*
 * LCD.c
 *
 * Created: 2/6/2020 12:36:41 AM
 *  Author: Mohamed Moawya
 */ 
#include "LCD.h"
void lcd_Init(void){
	LCD_PORT_DIR = 0xFF ; //  set LCD port as output
	CONTROL_PINS_DATA = 0 ;
	 //   set control pins as output
	 SET_BIT(CONTROL_PINS_DIR, EN);
	 SET_BIT(CONTROL_PINS_DIR, RW);
	 SET_BIT(CONTROL_PINS_DIR, RS);
	 
	 SET_BIT(CONTROL_PINS_DATA, EN); // Active enable pin
	 
	 lcd_send_command(0x38);        // set LCD at 8bit mode 	 
	 lcd_send_command(0x0C);       // Display on cursor off		 
}
void lcd_send_command(unsigned char cmd){
	LCD_PORT_DATA = cmd;							   // send command to LCD port 
	
	CLR_BIT(CONTROL_PINS_DATA, RW); // activate writing to the LCD by clear RW pin 
	CLR_BIT(CONTROL_PINS_DATA, RS); // activate command by clear RS pin 
	
	//adjust enable 
	CLR_BIT(CONTROL_PINS_DATA, EN);
	 _delay_us(1);
	SET_BIT(CONTROL_PINS_DATA, EN);
	 _delay_us(1);

    _delay_ms(100); // let LCD excute the command 
}
void lcd_send_data(unsigned char data){
	LCD_PORT_DATA = data;                             // send data to the LCD port 
	
	CLR_BIT(CONTROL_PINS_DATA, RW); // activate writing to the LCD by clear RW pin
	SET_BIT(CONTROL_PINS_DATA, RS); // activate data by set RS pin
	
	
	//adjust enable 
	CLR_BIT(CONTROL_PINS_DATA, EN);
	_delay_us(1);
	SET_BIT(CONTROL_PINS_DATA, EN);
	_delay_us(1);
	
	_delay_ms(100); // let LCD Display the data 
}
void lcd_clear(){
	lcd_send_command(0x01); // send clear command to the lcd
}
void lcd_send_string(char *str){
	
	while (*str!=0){
		lcd_send_data(*str);  // send the string char by char to the LCD
		str++ ;
	}
}
void lcd_set_curser(unsigned char x, unsigned char y){
	
	// x for column y for row 
	if(y == 0)                  
	{
		lcd_send_command(0x80+x);   // 0x80 the beginning of the first line
	}
	else
	{
		lcd_send_command(0xC0+x); // 0x80 the beginning of the second line
	}
}

void lcd_out(unsigned char x, unsigned char y, char *str){
	lcd_set_curser(x, y);       // set cursor at position (x, y)
	lcd_send_string(str);       // start writing the string form that position 
}

void lcd_convert_data(unsigned int var){
	
    int i ;
    char number[17];
	unsigned char enter = 0;
	
	while(var!=0)
	{
	  number[enter++] = (var%10) + 48 ;
	  var = var/10 ;	
	}
	
	enter--;
	for(i=enter ;i>=0;i--)
	{
		lcd_send_data(number[i]); 
	}
}









