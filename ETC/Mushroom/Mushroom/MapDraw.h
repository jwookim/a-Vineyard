#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;

#define ENTER 13
#define WIDTH 200
#define HEIGHT 50

//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK 0x0000/* | 0x0008 << 4 */
#define DARK_BLUE 0x0001 /*| 0x0008 << 4*/
#define GREEN 0x0002 /*| 0x0008 << 4*/
#define BLUE_GREEN 0x0003 /*| 0x0008 << 4*/
#define BLOOD 0x0004 /*| 0x0008 << 4*/
#define PUPPLE 0x0005 /*| 0x0008 << 4*/
#define GOLD 0x0006 /*| 0x0008 << 4*/			//색상 지정
#define ORIGINAL 0x0007 /*| 0x0008 << 4*/
#define GRAY 0x0008 /*| 0x0008 << 4*/
#define BLUE 0x0009 /*| 0x0008 << 4*/
#define HIGH_GREEN 0x000a /*| 0x0008 << 4*/
#define SKY_BLUE 0x000b /*| 0x0008 << 4*/
#define RED 0x000c /*| 0x0008 << 4*/
#define PLUM 0x000d /*| 0x0008 << 4*/
#define YELLOW 0x000e /*| 0x0008 << 4*/
//////////////////////////////////////////////////////


class MapDraw
{
public:
	void ChangeColor(WORD color);
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

