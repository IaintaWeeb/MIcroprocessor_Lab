#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="      Pt-51     ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="   IIT Bombay   ";						//Display msg on 1st line of lcd

void main()
{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string(display_msg1);
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg2);
	while(1);
		
}
int Arr[x][y] = {{ele 1, ele 2, .. ele y} , {......} , {..., ele xy-1, ele xy}};
			/*key=P3;
			if(key == 0x07){
				col= 0;
			}
			if(key == 0x0B){
				col= 1;
			}
			if(key == 0x0D){
				col= 2;
			}
			if(key == 0x0E){
				col= 3;
			}
			if(P3 != 0x0F){
					break;
			}
		}
		P3=0xEF;
		key=P3&0x0F; 
		if(key != 0x0F){
			row=0;
		}
		P3=0xDF;
		key=P3&0x0F; 
		if(key != 0x0F){
			row=1;
		}
		P3=0xBF;
		key=P3&0x0F ;
		if(key != 0x0F){
			row=2;
		}	
		P3=0x7F;
		key=P3&0x0F ;
		if(key != 0x0F){
			row=3;
		}		*/