#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="   EE337-2023   ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="a";						//Display msg on 1st line of lcd
code unsigned char display_msg3[]="b";						//Display msg on 1st line of lcd
void main()
{
	unsigned char array[6],i;
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string(display_msg1);
	for(i=0;i<=5;i++){
		array[i]=i+34;
		lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
		msdelay(4);
		lcd_write_string(array);
		msdelay(1000);
	}
		while(1);
		
}