#pragma once
#include"Position.h"
#include"MapDraw.h"
class Object
{
private:
	Position m_Position;
	char m_chShape;
	MapDraw DrawManager;
	/*int m_iWidth;
	int m_iHeight;*/
public:
	inline Position GetPosition()
	{
		return m_Position;
	}
	void SetPosition(Position pos);
	void Draw();
	void Erase();
};

