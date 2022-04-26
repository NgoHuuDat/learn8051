#include <REGX52.H>

sbit LED = P2^0;
sbit BTN = P2^1;


char revData = ' ';

void setup();
void serialSend(char c);

void main()
{
	char sendData = 'A';
	setup();
	while(1)
	{
		if(BTN == 0)
		{
			while(!BTN);
			serialSend(sendData);
			sendData++;	
		}
		
		if(revData == '1')
			LED = 0;
		else
			LED = 1;
	}
}

void setup()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	
	EA = 1;
	ES = 1;
	
	BTN = 1;
	LED = 1;
}

void serial_ISR() interrupt 4
{
	if(RI==1)
	{
		revData = SBUF;
		RI = 0;
	}	
	if(TI == 1)
		TI = 0;
}

void serialSend(char c)
{
	SBUF = c;
	while(!TI)
	TI = 0;	
	if(RI == 1)
		RI = 0;
}