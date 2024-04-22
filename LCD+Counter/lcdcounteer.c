#include<reg52.h>

sbit counter=P3^4;
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;
unsigned char i;
unsigned int cnt_value;

void send_comment(unsigned int a);
void send_data(unsigned int a);
void ms_delay(unsigned int b);
//LCD Initialize

void main(){
	send_comment(0x38);
	send_comment(0x0e);
	send_comment(0x01);
	TMOD=0x06;
	
	 counter=1;
	
	 while(1){
	   TL0=00;
	   TH0=00;
		 TR0=1;
		 while(!TF0){
		 
			 send_comment(0x80);
			  cnt_value=TL0;
			  i=cnt_value/10;
			  send_data(i+0x30);
			 i=cnt_value%10;
			  send_data(i+0x30);
			 if(cnt_value==100){
			   break;
			 }
	 }
		 TF0=0;
	   TR0=0;

}
	 }

void send_comment(unsigned int a){
	    P1=a;
      RS=0;
	    RW=0;
	    E=1;
	    ms_delay(10);
	    E=0;
}
void send_data(unsigned int a){
	    P1=a;
      RS=1;
	    RW=0;
	    E=1;
	    ms_delay(10);
	    E=0;
}
void ms_delay(unsigned int b){
   int i,j;
	 for(i=0;i<b;i++){
	   for(j=0;j<113;j++);
	 }
}