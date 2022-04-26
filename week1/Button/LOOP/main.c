#include <REGX52.H>

#define LED P2
sbit  BTN1 = P3^0;
sbit  BTN2 = P3^1;

unsigned int check,time,count,countt;

void DichLed()
{
	LED = ((LED >> 1) | 0x80);
}

void Delay()
{
	unsigned int lap;
	lap = 2;
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

void checkbtn2()
{
	if(BTN2 == 0)
		{
			check++;
			while(!BTN2);
		}
}

void checkbtn1()
{
	if(BTN1 == 0)
	{
		switch(count)
		{
			case 0:
				time = 5;
				break;
			case 1:
				time = 10;
				break;
			case 2:
				time = 20;
				break;
			case 3:
				time = 30;
				break;
		}
		count = count + 1;
		while(!BTN1);
		if(count == 4)
			count = 0;	
		countt = 0;
	}	
}

void checkLED()
{
			Delay();
			countt = countt + 1;
			if(countt == time)
			{
				countt = 0;
				DichLed();
			}
			if(LED == 0xFF)
				LED = 0x7F;
}

void setup()
{
	BTN1 = 1;
	BTN2 = 1;
	check = 0;
	time = 10;
	count = 0;
	countt = 0;
	LED = 0x7F;
}

void main(void)
{
	setup();
	
	while(1)
	{		
		checkbtn2();
		if(check%2 == 0)
		{
			checkbtn1();
			checkLED();
		}
	}
}
