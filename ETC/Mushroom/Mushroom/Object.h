#pragma once
#include"Position.h"
class Object
{
private:
	Position m_Position;
	/*int m_iWidth;
	int m_iHeight;*/
public:
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

