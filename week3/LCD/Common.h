#ifndef COMMON_H	
#define COMMON_H

#include<stdio.h>
#include<stddef.h>

typedef code struct Linkedlist
{
	struct Linkedlist *pre;
	unsigned char Tile[20];
	struct Linkedlist *Menulist0;
	unsigned char list1[20];
	struct Linkedlist *Menulist1;
	unsigned char list2[20];
	struct Linkedlist *Menulist2;
	unsigned char list3[20];
	struct Linkedlist *Menulist3;
}Menu;

Menu code MainMenu,RechangeMenu, SettingMenu,ProductMenu1,ProductMenu2,ProductMenu3;

Menu code MainMenu = {
	NULL,
	"     MAIN MENU     ",NULL,
	"   RECHANGE        ",&RechangeMenu,
	"   SETTING         ",&SettingMenu,
	"   EXIT            ",NULL,
};

Menu code RechangeMenu = {
	&MainMenu,
	"   5000            ",&ProductMenu1,
	"   10000           ",&ProductMenu1,
	"   15000           ",&ProductMenu1,
	"   20000           ",&ProductMenu1,
};
Menu code ProductMenu1 = {
	&RechangeMenu,
	"  REDBULL 10000  10",&ProductMenu2,
	"  NUMBER1 10000  10",&ProductMenu2,
	"  COMPACT 10000  10",&ProductMenu2,
	"  MONSTER 10000  10",&ProductMenu2,
};

Menu code ProductMenu2 = {
	&ProductMenu1,
	"  COCACOLA 5000  15",&ProductMenu3,
	"  PEPSI    5000  15",&ProductMenu3,
	"  LAVIE    5000  10",&ProductMenu3,
	"  STING    5000  10",&ProductMenu3,
};

Menu code ProductMenu3 = {
	&ProductMenu2,
	"  TIGER  14000  12 ",NULL,
	"  HANOI  10000  24 ",NULL,
	"  HUDA   9000   24 ",NULL,
	"  333    8000   24 ",NULL,
};

Menu code SettingMenu = {
	&MainMenu,
	"      SETTING      ",NULL,
	"   CHANGE          ",NULL,
	"   DELETE          ",NULL,
	"   SORT            ",NULL,
};

#endif