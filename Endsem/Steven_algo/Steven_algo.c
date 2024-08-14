#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="PROD: ";
code unsigned char display_msg2[]="TIME: ";
code unsigned char display_msg3[]=" us ";
long unsigned int cnt ;
long unsigned int x=14571;
long unsigned int x0;
long unsigned int x1;
long unsigned int y0;
long unsigned int y1;
long unsigned int z1;
long unsigned int z2;
long unsigned int z3;
long unsigned int y=8636;
long unsigned int prod;
unsigned char cnt_str[5];
unsigned char prod_str[10]="125835156";
//interrupt_subroutine
void timer0_isr () interrupt 1{
	cnt=cnt+1;
	TH0	=	0xFF;
	TL0	=	0xFE;
}
void steven_algo(void){
	TR0=1;
	x0=x%10;
	x1=x/10;
	y0=y%10;
	y1=y/10;
	z1=x0*y0;
	z2=x1*y0+y1*x0;
	z3=x1*y1;
	prod=z1+10*(z2)+100*(z3);
	TR0=0;
}
//Main function
void main(void){
	cnt=0;
	TMOD = 0x01; //timer0 as counter in mode1
	TH0	=	0xFF;
	TL0	=	0xFE;
	ET0 = 1; //activate interrupts for both timers
	EA = 1;  //activate global interrupts
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg1);
	msdelay(4);
	steven_algo();
	//int_to_string(prod,prod_str);
	int_to_string(cnt,cnt_str);
	lcd_write_string(prod_str);
	lcd_cmd(0xC0);
	lcd_write_string(display_msg2);
	lcd_write_string((cnt_str));
	lcd_write_string(display_msg3);
	while(1);
}