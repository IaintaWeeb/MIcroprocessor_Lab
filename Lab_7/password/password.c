#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="ENTER PASSWORD:";
code unsigned char display_msg2[]="CORRECT PASSWORD";				
code unsigned char display_msg3[]="ACCESS GRANTED";
code unsigned char display_msg4[]="WRONG PASSWORD";
code unsigned char display_msg5[]="ACCESS DENIED";
code unsigned char key_code[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};


void main(){
	unsigned char i,j,col,row,key,passcode[8];
	unsigned char correct_password[8]="15A8*D6#";
	unsigned int flag=0;
	P1=0x00;
	lcd_init();
	lcd_cmd(0x80);													
	msdelay(4);
	lcd_write_string(display_msg1);
	for(i=0;i<8;i++){
		P3=0x0F;
		while(1){
			if(P3 != 0x0F){
				continue;
			}
			while(1){
				if(P3 != 0x0F){
					break;
				}
			}
			msdelay(20);
			key=P3;
			if( P3 == 0x0F){
				continue;
			}
			P3 = 0xEF;
			for(j=0;j<4;j++){
				key = P3;
				key = key&0x0F;
				if(key != 0x0F){
					row=j;
					if(key == 0x07 ){ 
						col=0;
					}
					if(key == 0x0B){ 
						col=1;
					}
					if(key == 0x0D){ 
						col=2;
					}
					if(key == 0x0E){						
						col=3;
					}
					break;
				}
				P3=(P3 << 1)|0x0F;
			 }
			break;
		 }
		passcode[i]=key_code[row][col];
		lcd_cmd(0xC0);
		msdelay(4);
		if(i<7){
			lcd_write_string(passcode);
		}
	}
	for(i=0;i<=7;i++){
		if(passcode[i]!=correct_password[i]){
			flag=flag+1;
		}
	}
			
	if(flag==0){
		lcd_init();
		lcd_cmd(0x80);													
		msdelay(4);
		lcd_write_string(display_msg2);
		lcd_cmd(0xC0);													
		msdelay(4);
		lcd_write_string(display_msg3);
	}
	else {
		lcd_init();
		lcd_cmd(0x80);													
		msdelay(4);
		lcd_write_string(display_msg4);
		lcd_cmd(0xC0);													
		msdelay(4);
		lcd_write_string(display_msg5);
	}
	while(1);		
}