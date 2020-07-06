#pragma once
#include"Singletone.h"
#include"MapDraw.h"
#include"Mine.h"
#include<iostream>
#include<conio.h>
#include<set>
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

struct BlockPointerComparator
{
	bool operator () (const Block* a, const Block* b)
	{
		return a->GetPosition() < b->GetPosition();
	}
};

enum CHECK
{
	CHECK_UNKNOWN = -1,
	CHECK_BLANK,
	CHECK_MINE
};

class GameManage : public Singletone<GameManage>
{
private:
	set<Block*, BlockPointerComparator> m_Map;
	//Block* m_Map[HEIGHT][WIDTH];
	//CHECK m_CheckMap[HEIGHT][WIDTH];
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
