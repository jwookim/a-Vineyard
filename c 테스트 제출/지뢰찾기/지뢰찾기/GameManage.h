#pragma once
#include"Singletone.h"
#include"MapDraw.h"
#include<iostream>
using namespace std;

#define ENTER 13

#define WIDTH 10
#define HEIGHT 10
#define MINE 30

#define UP {0, -1}
#define DOWN {0, 1}
#define LEFT {-1, 0}
#define RIGHT {1, 0}
#define UL {-1, -1}
#define UR {1, -1}
#define DL {-1, 1}
#define DR {1, 1}

enum CHECK
{
	CHECK_UNKNOWN = -1,
	CHECK_BLANK,
	CHECK_MINE
};

struct Position
{
	int x;
	int y;
};

class GameManage : public Singletone<GameManage>
{
private:
	CHECK m_Map[HEIGHT][WIDTH];
	CHECK m_CheckMap[HEIGHT][WIDTH];
	int m_iCheckNum;
	Position m_Cursor;
public:
	GameManage();
	void Init(Position pos);
	void Play();
	void Move();
	void Check();
	void Spread(Position pos);
	CHECK Check(Position pos);
};

bool operator == (Position p1, Position p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	
	return false;
}