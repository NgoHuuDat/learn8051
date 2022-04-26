#include <REGX52.H>

sbit LED = P3^0;

void Delay()
{
	unsigned int lap,i;
	lap = 20;
	while(lap--)
	{
		TMOD = 0x01;
		TH0 = 0x3C;
		TL0 = 0xC7;
		TR0 = 1;
		while(!TF0);
		TF0 = 0;
		TR0 = 0;
	}
	  i = 1;
		while(i--);
	  LED =LED;
}

void main()
{	
	LED = 0;
	while(1)
	{
		Delay();
		LED = ~LED;
	}

}