/*
 * LCD.h
 *
 * Created: 2/6/2020 12:37:02 AM
 *  Author: Mohamed Moawya
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <util/delay.h>
#include <avr/io.h>
#define SET_BIT(port, pin)    (port|=(1<<pin))
#define CLR_BIT(port, pin)    (port&=~(1<<pin))

#define EN PB0    // pin enable for the LCD  
#define RW PB1	  // read/write pin for the LCD	  
#define RS PB2    // data/command pin for the LCD 
#define LCD_PORT_DIR DDRA
#define LCD_PORT_DATA PORTA 
#define CONTROL_PINS_DATA PORTB
#define CONTROL_PINS_DIR DDRB

void lcd_Init();
void lcd_send_command(unsigned char);
void lcd_send_data(unsigned char);
void lcd_clear();
void lcd_set_curser(unsigned char, unsigned char);
void lcd_send_string(char *);
void lcd_out(unsigned char, unsigned char, char *);
void lcd_convert_data(unsigned int);
 

 
	



#endif /* LCD_H_ */