#include <REGX52.H>

#define LEDC P1
#define LEDDV P0

char code CODE7SEG[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void Delay_ms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i = i+1)
	{	for(j=0;j<123;j = j+1){}
	}
}

void PPGan()
{
	unsigned int i, v, d;
	for(i = 0; i < 100; i = i+1)
		{
			v = i / 10;
			LEDC = CODE7SEG[v];
			d = i%10;
			LEDDV = CODE7SEG[d];
			Delay_ms(500);
		}
}

void main(void)
{
	while(1)
	{
		PPGan();
	}
}	