#pragma once
#include"Singletone.h"
#include"MapDraw.h"
#include"Mine.h"
#include<iostream>
#include<conio.h>
#include<map>
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


typedef Position Direct;

class GameManage : public Singletone<GameManage>
{
private:
	map<Position , Block*> m_Map;
	int m_iCheckNum;
	bool m_bAlive;
	Position m_Cursor;
public:
	GameManage();
	void Init(Position pos);
	void Play();
	void Move();
	void MoveCursor();
	void Check(Position pos);
	void Spread();
	void Spread(Position pos);
	int Detection(Position pos);
	void Boom();
	//CHECK Check(Position pos);
};
