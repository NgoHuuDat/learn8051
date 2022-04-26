#include <REGX52.H>

sbit LED = P2^0;
sbit BTN = P2^4;

unsigned char revData = ' ';

void setup();
void serialSend(unsigned char c);
void Delay_ms(unsigned char time);

void main()
{
	unsigned char sendData, count,countt;
	setup();
	sendData = 'A';
	count = 0;
	countt=0;
	while(1)
	{
		if(BTN == 0)
		{
			while(!BTN);
			serialSend(sendData);
		}
		
		if(revData == 'A')
		{	
			Delay_ms(10);
			countt++;
			if(countt >=26)
			{
				if(count%2 == 0)
					LED = 0;
				else
					LED = 1;
				count++;
				if(count == 10)
				{	
					count = 0;
					revData = 'B';
				}
				countt = 0;
			}			
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
	
	BTN = 1;
	LED = 1;
}
void serialSend(unsigned char c)
{
	SBUF = c;
	while(!TI);
	TI = 0;
	if(RI ==1)
		RI = 0;
}
void serial_ISR() interrupt 4
{
	if(RI == 1)
	{
		revData = SBUF;
		RI = 0;
	}
	if(TI ==1)
		TI = 0;
}

void Delay_ms(unsigned char time)
{
	unsigned char i;
	while(time--)
	{
		for(i = 0; i<123;i++){}
	}
}