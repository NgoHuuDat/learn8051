#include <REGX52.H>

sbit LED1 = P2^0;
sbit LED2 = P2^2;
sbit LED3 = P2^4;

unsigned char revData = ' ';
unsigned char flag = 0;

void setup();

void main()
{
	setup();

	while(1)
	{
		if(flag == 1)
		{
			if(revData == '1')
				LED1 = !LED1;
			if(revData == '2')
				LED2 = !LED2;
			if(revData == '3')
				LED3 = !LED3;
			flag = 0;
		}
	}
}

void setup()
{
	SCON = 0x50;
	EA = 1;
	ES = 1;
	
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
	
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
}
void serial_ISR() interrupt 4
{
	if(RI == 1)
	{
		revData = SBUF;
		RI = 0;
		TI = 0;
		flag = 1;
	}
}