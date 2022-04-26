#include <REGX52.H>

#define LED7SEG P0
sbit LED1 = P2^0;
sbit LED2 = P2^3;
sbit LED3 = P2^6;

sbit BTN1 = P3^0;
sbit BTN2 = P3^1;
sbit BTN3 = P3^2;

unsigned char code CODE7SEG[] = {0xC0, 0xF9};

void setup()
{
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}

void xulyLed1()
{
	if(BTN1 == 0)
		{
			LED1 = ~LED1;
			while(!BTN1);
		}
}

void xulyLed2()
{
	if(BTN2 == 0)
		{
			LED2 = ~LED2;
			while(!BTN2);
		}
}

void xulyLed3() interrupt 0
{
	if(BTN3 == 0)
	{
		LED3 = ~LED3;
		while(!BTN3);
	}
}

void xulyLED7SEG()
{
	LED7SEG = CODE7SEG[~LED1];
}

void main()
{
	setup();
	while(1)
	{
		xulyLed1();
		xulyLed2();
		xulyLED7SEG();
	}
}