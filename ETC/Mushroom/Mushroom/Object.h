#pragma once
#include"Position.h"
#include"MapDraw.h"

class Object
{
private:
	Position m_Position;
	char m_chShape;
	int m_iColor;
	MapDraw DrawManager;
	/*int m_iWidth;
	int m_iHeight;*/
public:
	Object();
	inline Position GetPosition()
	{
		return m_Position;
	}
	void SetPosition(Position pos);
	void SetShape(char shape);
	void SetColor(int color);
	void Draw();
	void Erase();
	~Object();
};

