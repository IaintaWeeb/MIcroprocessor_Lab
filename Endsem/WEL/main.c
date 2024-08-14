/**********************************************************
EE337: ADC IC MCP3008 interfacing with pt-51
(1) Complete spi_init() function from spi.h 

***********************************************************/

#include <at89c5131.h>
#include "serial.c"	
unsigned char WELinit[4]={'5','5','8','6'};
unsigned char WEL[4]={'5','5','8','6'};
int q;
int i;
int q_;

void issue_state(void){
	transmit_string("Enter Resource to be borrowed:");
	while(1){
		i=receive_char()-48;
		if ((i==1)||(i==2)||(i==3)||(i==4)){
				transmit_string("Enter Quantity:");
				while(1){
					q=receive_char()-48;
					q_= WEL[i-1]-48;
					if (q_ >= q){
						transmit_string("Requested resource allocated!");
						WEL[i-1]= q_-q + 48;
						break;
					}
					else{
						transmit_string("Requested resource not available...");
						break;
					}
				}
				break;
			}
	}
}	

void return_state(void){
	transmit_string("Enter Resource to be returned:");
	while(1){
		i=receive_char()-48;
		if(WEL[i-1]==WELinit[i-1]){
			transmit_string(" You can’t return what you don’t have...");
			continue;
		}
		if ((i==1)||(i==2)||(i==3)||(i==4)){
				transmit_string("Enter Quantity:");
				while(1){
					q=receive_char()-48;
					q_= WEL[i-1]-48;
					if (q_+q <= WELinit[i-1]-48){
						transmit_string("Returned resource received!");
						WEL[i-1]= (q_+q + 48);
						transmit_char(WEL[i-1]);
						break;
					}
					else{
						transmit_string("Returned resource out of bounds...");
						break;
					}
				}
				break;
			}
	}
}	

void main(void)
{
	uart_init();
	while(1)
	{
		transmit_string("Resources available: DSO-");
		transmit_char(WEL[0]);
		transmit_string(" AFG- ");
		transmit_char(WEL[1]);
		transmit_string(" DMM- ");
		transmit_char(WEL[2]);
		transmit_string(" DPS-");
		transmit_char(WEL[3]);
		transmit_string("\r\n");
		transmit_string("Press I for Issue and R for Return");
		transmit_string("\r\n");
		if(receive_char()=='I'){
			issue_state();
		}
	  if(receive_char()=='R'){
			return_state();
		}
	}
}

