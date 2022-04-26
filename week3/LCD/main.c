#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include "common.h"

sbit UP = P3^3;
sbit DOWN = P3^4;
sbit RIGHT = P3^5;
sbit LEFT = P3^6;
sbit OK = P3^7;

void code setup();
void code MenuDisplay(Menu* menu,unsigned char select);

void main()
{
	unsigned char select = 1;
	Menu* menu;
	menu = &MainMenu;
	setup();	
	
	MenuDisplay(menu,select);
	while(1)
	{
		if(DOWN == 0)
		{
			while(!DOWN);
			LCD_String_xy(select,0," ");
			if(menu == &MainMenu)
				select = (select == 3)?1:select+1;
			else
				select = (select == 3)?0:select+1;
			LCD_String_xy(select,0,">");
			
			
		}
		
		if(UP == 0)
		{
			while(!UP);
			LCD_String_xy(select ,0," ");
			if(menu == &MainMenu)
				select = (select == 1)?3:select-1;
			else
				select = (select == 0)?3:select-1;
			LCD_String_xy(select,0,">");
			
		}
		
		if(RIGHT == 0)
		{
			while(!RIGHT);
			switch(select)
			{
				case 0: menu = (menu->Menulist0 ==NULL)?menu:menu->Menulist0; break;
				case 1: menu = (menu->Menulist1 ==NULL)?menu:menu->Menulist1; break;
				case 2: menu = (menu->Menulist2 ==NULL)?menu:menu->Menulist2; break;
				case 3: menu = (menu->Menulist3 ==NULL)?menu:menu->Menulist3; break;
			}
			select = 1;
		  MenuDisplay(menu,select);
		}
		if(LEFT == 0)
		{
			while(!LEFT);
			menu = menu->pre;
			MenuDisplay(menu,select);
		}
		
	}
}

void code setup()
{
	LCD_Init();
	UP = 1;
	DOWN = 1;
	RIGHT = 1;
	LEFT = 1;
	OK = 1;
}
void code MenuDisplay(Menu* menu,unsigned char select)
{
	LCD_String_xy(0,0,menu->Tile);
	LCD_String_xy(1,0,menu->list1);
	LCD_String_xy(2,0,menu->list2);
	LCD_String_xy(3,0,menu->list3);
	LCD_String_xy(select,0,">");
}

