#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;

#define ENTER 13
#define WIDTH 800
#define HEIGHT 600

//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000/* | 0x0008 << 4 */);
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 | 0x0008 << 4 );
#define GREEN SetConsoleTextAttribute( col,0x0002 | 0x0008 << 4 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 | 0x0008 << 4 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 | 0x0008 << 4 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 | 0x0008 << 4 );
#define GOLD SetConsoleTextAttribute( col,0x0006 | 0x0008 << 4 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 | 0x0008 << 4 );
#define GRAY SetConsoleTextAttribute( col,0x0008 | 0x0008 << 4 );
#define BLUE SetConsoleTextAttribute( col,0x0009 | 0x0008 << 4 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a | 0x0008 << 4 );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b | 0x0008 << 4 );
#define RED SetConsoleTextAttribute( col,0x000c | 0x0008 << 4 );
#define PLUM SetConsoleTextAttribute( col,0x000d | 0x0008 << 4 );
#define YELLOW SetConsoleTextAttribute( col,0x000e | 0x0008 << 4 );
//////////////////////////////////////////////////////


class MapDraw
{
public:
	void BoxDraw(int Start_x,int Start_y, int Width, int Height);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	void ClearWindow();
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

