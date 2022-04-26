#include <REGX52.H>

#define LED  P0 

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;

sbit LE1 = P1^0;
sbit LE2 = P1^1;
sbit LE3 = P1^2;

sbit BTN1 = P3^2;
sbit BTN2 = P3^1;
sbit BTN3 = P3^0;

unsigned char code CODE7SEG[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

unsigned char time1,time2,time3;

void setup();
void resetLED();
void Delay();
void Display7seg(unsigned char choose,unsigned char num);
void Display();
void checkBTN2();
void checkBTN3();

void main()
{
	unsigned char count1,count2,count3,count4,count4p;
	count1 = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;
	count4p = 0;
	setup();
	while(1)
	{
		checkBTN2();
		checkBTN3();
		Display();
		resetLED();
		Delay();
		
		if(time1 != 0)
			count1++;
		if(time2 != 0)
			count2++;
		if(time3 != 0)
			count3++;
		count4++;
		if(count4 >= 41)
		{	
			count4p++;
			count4 = 0;
		}
		if(count4p == 10)
			LED4 = 0;
		if(count4p == 11)
			LED4 = 1;
		
		if(count1 >= 41)
		{
			count1 = 0;
			if(time1 != 0)
				time1--;
		}
		if(count2 >= 41)
		{
			count2 = 0;
			if(time2 != 0)
				time2--;
		}
		if(count3 >= 41)
		{
			count3 = 0;
			if(time3 != 0)
				time3--;
		}
	}
}

void setup()
{
	LE1 = 0;
	LE2 = 0;
	LE3 = 0;
	
	BTN1 = 1;
	BTN2 = 1;
	BTN3 = 1;
	
	EA = 1;
	EX0 = 1;
	IT0 = 1;
	
	time1 = 0;
	time2 = 0;
	time3 = 0;
	
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	LED4 = 1;
}

void resetLED()
{
	if(time1 == 0)
		LED1 = 1;
	if(time2 == 0)
		LED2 = 1;
	if(time3 == 0)
		LED3 = 1;
}

void ISR_ex0() interrupt 0
{
	time1 = 9;
	LED1 = 0;
	while(!BTN1);
}

void Delay()
{
	unsigned int times;
	times = 1;
	while(times--)
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
void Display7seg(unsigned char choose,unsigned char num)
{
	switch(choose)
	{
		case 0:
			LED = CODE7SEG[num];
			LE1 = 1;
			LE1 = 0;
			break;
		case 1:
			LED = CODE7SEG[num];
			LE2 = 1;
			LE2 = 0;
			break;
		case 2:
			LED = CODE7SEG[num];
			LE3 = 1;
			LE3 = 0;
			break;
	}	
}
void Display()
{
		Display7seg(0,time1);
		Display7seg(1,time2);
		Display7seg(2,time3);
}

void checkBTN2()
{
	if(!BTN2)
	{
		time2 = 9;
		LED2 = 0;
		while(!BTN2);
	}
}
void checkBTN3()
{
	if(!BTN3)
	{
		time3 = 9;
		LED3 = 0;
		while(!BTN3);
	}
}

