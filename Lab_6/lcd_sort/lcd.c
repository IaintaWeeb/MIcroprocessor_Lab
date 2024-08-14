#include <at89c5131.h>
#include "lcd.h"
code unsigned char display_msg1[]="START PROGRAM";						
code unsigned char display_msg2[]="FIRST INPUT";					
code unsigned char display_msg3[]="NEXT INPUT";	
code unsigned char display_msg4[]="SORTING...";	
code unsigned char display_msg5[]="SORTING";
code unsigned char display_msg6[]="COMPLETED";
code unsigned char display_msg7[]="NUMBER TO BE";
code unsigned char display_msg8[]="SEARCHED";
code unsigned char display_msg9[]="THE INDEX IS";
code unsigned char display_msg10[]="NUMBER";
code unsigned char display_msg11[]="NOT FOUND";

void main()
{ //Variable initialization
	unsigned char number[5];
	unsigned char num;
	unsigned char index = 0;
	unsigned char i;
	unsigned char j;
	unsigned char temp;
	
	lcd_init();
	lcd_cmd(0x80);													
	msdelay(4);
	P1=0x0F;
	lcd_write_string(display_msg1);
	msdelay(5000);
	lcd_init();
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg2);
	msdelay(5000);
	//Input Loop
	for(i=0;i<=4;i++){
		number[i]=P1;
	  P1 = number[i] << 4;
		P1 = P1|0x0F;
		lcd_init();
		lcd_cmd(0x80);												
		msdelay(4);
	
		if(i==4){
			lcd_write_string(display_msg4);
		}
		else lcd_write_string(display_msg3);
		
		msdelay(5000);
		P1=P1&0x0F;
		if(i==4){
			lcd_init();
			lcd_cmd(0x80);													
			msdelay(4);
			lcd_write_string(display_msg5);
			msdelay(4);
			lcd_cmd(0xC0);
			lcd_write_string(display_msg6);
		}
		msdelay(1000);		
	}

	// Bubblesort
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4-i; j++){
			if (number[j] > number[j + 1]){
				temp=number[j+1];
				number[j+1]=number[j];
				number[j]=temp; 
			}
		}
	}
	// display sorted array
	for(i=0;i<=4;i++){
		P1 = number[i] << 4;
		msdelay(5000);
		P1=0x0F;
		msdelay(1000);
	}
	
	P1=0xFF;
	lcd_init();
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg7);
	msdelay(4);
	lcd_cmd(0xC0);
	lcd_write_string(display_msg8);
	msdelay(5000);
	num=P1%16;
	P1=num;
	lcd_init();
	msdelay(1000);
	// linear search
	for(i=0;i<5;i++){
		if(number[i] == num){
			index=i+1;
	  }
	}
	// index diaplay
	if(index!=0){
		lcd_cmd(0x80);													
	  msdelay(4);
		lcd_write_string(display_msg9);
		P1=index << 4;
		msdelay(5000);
	}
	else {
		P1=0xFF;
		lcd_cmd(0x80);													
		msdelay(4);
		lcd_write_string(display_msg10);
		msdelay(4);
		lcd_cmd(0xC0);
		lcd_write_string(display_msg11);
		msdelay(5000);
	}
	
	while(1);
		
}