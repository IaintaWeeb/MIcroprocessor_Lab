#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg[]="   STOP WATCH   ";
code unsigned char key[]="0123456789";
sbit SW=P1^0;
unsigned char cnt ;
unsigned char time[]="      00:00     ";

//interrupt_subroutine
void timer0_isr () interrupt 1{
	cnt=cnt+1;
	lcd_cmd(0xC0);
	time[10] = key[(cnt%60)%10];
	time[9] = key[(cnt%60)/10];
	time[8] = ':';
	time[7] = key[((cnt/60)%10)];
	time[6] = key[((cnt/60)/10)];
	lcd_write_string(time);
	TH0	=	0xFF;
	TL0	=	0xC4;
}

//Main function
void main(void){
	cnt=0;
	P1=0x0F;
	TMOD = 0x15; //timer0 as counter in mode1
	TH0	=	0xFF; //-60
	TL0	=	0xF2;
	ET0 = 1; //activate interrupts for both timers
	EA = 1;  //activate global interrupts
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg);
	msdelay(4);
	lcd_cmd(0xC0);
	msdelay(4);
	lcd_write_string(time);
	while(1){
		if( SW == 1){
			TR0 = 1; //start timer 0
		}
		else{
			TR0 = 0; //stop timer 0
		}
	}
}