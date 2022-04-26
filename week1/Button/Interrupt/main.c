#include <REGX52.H>

#define LED P2
sbit  BTN1 = P3^2;
sbit  BTN2 = P3^3;

unsigned int check1,check2,count,n;

void DichLed()
{
	if(LED == 0xFF)
		LED = LED >> 1;
	else
		LED = ((LED >> 1) | 0x80);
}

void Delay(unsigned int time)
{
	unsigned int lap;
	while(time--)
	{
		lap = 10;
		while(lap--)
		{
			TMOD = 0x01;
			TH0 = 0x3C;
			TL0 = 0xB0;
			TR0 = 1;
			while(!TF0);
			TF0 = 0;
			TR0 = 0;
		}
	}
}

void xulyDung() interrupt 2
{
	check1 = ~check1;
	while(!BTN2);
}
void xulyTimer() interrupt 0
{
	if(check1 == 1)
	{
		n++;
		count++;
	  while(!BTN1);
	}
}

void checkCount()
{
	if(n == 1)
		count = 0;
	
	if(count == 0)
		check2 = 1;
	else if(count == 1)
		check2 = 2;
	else if(count == 2)
		check2 = 4;
	else if(count == 3)
		check2 = 6;
	if(count == 4)
	{
		count = 0;	
		check2 = 1;
	}
}

void initIRS()
{
	EA = 1;
	EX0 = 1;
	IT0 = 1;
	EX1 = 1;
	IT1 = 1;
}

void setup()
{
	BTN1 = 1;
	BTN2 = 1;
	check1 = 1;
	check2 = 2;
	count = 1;
	n = 0;
	LED = 0xFF;
}
void main(void)
{
	setup();
	initIRS();	
	while(1)
	{		
		checkCount();
		if(check1 == 1)
		{
			DichLed();
			if(LED == 0xFF)
				LED = 0x7F;
			Delay(check2);
			checkCount();
		}
	}
}