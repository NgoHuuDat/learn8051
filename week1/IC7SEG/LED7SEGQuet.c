#include <REGX52.H>

#define LEDQ P3

sbit CTRL1 = P2^0;
sbit CTRL2 = P2^1;

char code CODE7SEG[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void Delay_ms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i = i+1)
	{	for(j=0;j<123;j = j+1){}
	}
}

void PPQuet()
{
	unsigned int i,j, c, d;
	for(i = 0; i < 100; i = i+1)
		{
			for(j = 0; j < 10; j = j+1)
			{
				c = i / 10;
				LEDQ = CODE7SEG[c];
				CTRL1 = 1;
				Delay_ms(25);
				CTRL1 = 0;
				
				d = i%10;
				LEDQ = CODE7SEG[d];
				CTRL2 = 1;
				Delay_ms(25);
				CTRL2 = 0;
			}
		}
}

void main(void)
{
	while(1)
	{
		PPQuet();
	}
}	