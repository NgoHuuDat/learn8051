#include <REGX52.H>

#define LEDQ P3

sbit LE1 = P2^0;
sbit LE2 = P2^1;

char code CODE7SEG[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void Delay_ms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i = i+1)
	{	for(j=0;j<123;j = j+1){}
	}
}

void PPDich74HC573()
{
	unsigned int i, c, d;
	P2_0 = 0;
	P2_1 = 0;
	for(i = 0; i < 100; i = i+1)
		{
			if( i % 10 == 0)
			{
				c = i / 10;
				LEDQ = CODE7SEG[c];
				LE1 = 1;
				LE1 = 0;
			}
			
			d = i%10;
			LEDQ = CODE7SEG[d];
			LE2 = 1;
			LE2 = 0;
			Delay_ms(500);
		}
}

void main(void)
{

	while(1)
	{
		PPDich74HC573();
	}
}	