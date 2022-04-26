#include <REGX52.H>

#define LED1 P2

void Delay_ms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i = i+1)
	{	for(j=0;j<123;j = j+1){}
	}
}

void Trai()
{
	LED1 = (LED1 >> 1); 
}

void DTrai()
{
	LED1 = (LED1 >> 1) | 0x80;
}

void Phai()
{
	LED1 = (LED1 << 1);
}

void DPhai()
{
	LED1 = (LED1 << 1) | 0x01; 
}


void main(void)
{
	unsigned int i;
	while(1)
	{
		LED1 = 0xFF;
		Delay_ms(250);
		for(i = 0; i< 8; i=i+1)
		{
			Trai();
			Delay_ms(250);
		}
		
		LED1 = 0xFF;
		Delay_ms(250);
		for(i = 0; i< 8; i=i+1)
		{
			Phai();
			Delay_ms(250);
		}
		
		LED1 = 0xFF;
		Delay_ms(250);
		LED1 = 0x7F;
		Delay_ms(250);
		for(i = 0; i< 7; i=i+1)
		{
			DTrai();
			Delay_ms(250);
		}
		
		LED1 = 0xFF;
		Delay_ms(250);
		LED1 = 0xFE;
		Delay_ms(250);
		for(i = 0; i< 7; i=i+1)
		{
			DPhai();
			Delay_ms(250);
		}
	}

}