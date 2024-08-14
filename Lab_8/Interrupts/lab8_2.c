#include <at89c5131.h>

/*

Two frequency simultaneously with timers in interrupts mode.

First LED1 time period is 2ms.
Second LED2 time period is 3ms.

*/

sbit LED1=P3^6;
sbit LED2=P3^7;


void timer0_isr () interrupt 1
{
   LED1 = ~LED1;
	 TL0 = 0x90; //Starting Count value
   TH0 = 0xE8;
   //Reload values for TH0 and TL0. Start timer 0.

}

void timer1_isr () interrupt 3
{		
   LED2 = ~LED2;
	 TL1 = 0x60; //Starting Count value
   TH1 = 0xF0;
   //Reload values for TH1 and TL1. Start timer 1.
   
}

//Main function
void main(void)
{
	TMOD = 0x11; //mode 1 timer 0 and timer 1
	TL1 = 0x60; //Starting Count value
  TH1 = 0xF0;
	TL0 = 0x90; //Starting Count value
  TH0 = 0xE8;
	ET0 = 1; //activate interrupts for both timers
	ET1 = 1;
	EA = 1;  //activate global interrupts
	TR0 = 1; //start timer 0
	TR1 = 1; //start timer 1
	
	while(1);
}

