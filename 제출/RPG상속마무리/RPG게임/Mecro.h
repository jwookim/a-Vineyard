#pragma once

#include<iostream>
#include<Windows.h>
#include<string>
#include<time.h>
#include<fstream> // ostream ^ istream >> file system
#include<conio.h> // getch()

#define PLAYER 1
#define Enemy 0

#define 가위 0
#define 바위 1
#define 보 2

#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WIDTH 30
#define HEIGHT 30

using namespace std;


enum CHARCTER
{
	CPLAYER,
	CENEMY
};
enum MAIN
{
	MAIN_NEW = 1,
	MAIN_LOAD,
	MAIN_DETAIL,
	MAIN_EXIT
};

enum MENU
{
	MENU_DONGEON = 1,
	MENU_PINFO,
	MENU_MINFO,
	MENU_WEAPONSHOP,
	MENU_SAVE,
	MENU_EXIT
};
enum WEAPONTYPE
{
	WDagger = 1,
	WGun,
	WSword,
	WWand,
	WBow,
	WHammer
};

enum BUYTYPE
{
	N,
	D,
	G,
	S,
	W,
	B,
	H
};