/*
 * LCD.c
 *
 * Created: 2/6/2020 12:35:26 AM
 * Author : MOOO
 */ 

#include <avr/io.h>
#include "LCD.h"


int main(void)
{
    lcd_Init();
    while (1) 
    {
      lcd_send_string("hello world ");
	  lcd_convert_data(2000+20);
	  lcd_set_curser(0, 1);
	  lcd_send_string("hope you're good");
	  lcd_set_curser(0,0);
	  
	}
}

