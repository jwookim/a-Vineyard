#pragma once
#include"Block.h"

class Play
{
private:
	Block* m_Line[3];
	int m_iFloor;
	int m_iInterval;
	bool m_bSkip;
	MapDraw DrawManager;
public:
	void Setting();
	void Start();
	void CreateBlock(int line, int num);
	void MoveTower(int start, int dest, int num);
	void MoveBlock(int start, int dest);
	void TimeInterval();
	void DrawAll();
	void DeleteBlock(Block* block);
	Play();
	~Play();
};

