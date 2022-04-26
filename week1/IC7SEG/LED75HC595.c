#include <REGX52.H>

sbit SHCP  = P2^0;
sbit STCP  = P2^2;
sbit DATAS  = P2^1;

char code CODE7SEG[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void Delay_ms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i = i+1)
	{	for(j=0;j<123;j = j+1){}
	}
}

void PPDich74HC595(unsigned char dt)
{
	unsigned char i, datas;
	datas = dt;

	for (i = 0; i < 8; i++)
	{
		DATAS = datas & (0x80 >> i);
		SHCP = 0;
		SHCP = 1;
	}
}

void main(void)
{
	unsigned char i, chuc, donvi;
	while(1)
	{
		for( i = 0; i<100; i = i+1)
		{
			chuc = CODE7SEG[i/10];
			donvi = CODE7SEG[i%10];
			
			PPDich74HC595(donvi);
			PPDich74HC595(chuc);
			STCP = 0;
			STCP = 1;
			
			Delay_ms(500);
		}
	}
}	