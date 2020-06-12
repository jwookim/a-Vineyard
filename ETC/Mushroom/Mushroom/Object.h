#pragma once
#include"Position.h"
#include"MapDraw.h"

class Object
{
private:
	Position m_Position;
	string m_strShape;
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
	inline int GetColor()
	{
		return m_iColor;
	}
	void SetPosition(Position pos);
	void SetShape(string shape);
	void SetColor(int color);
	void Draw();
	void Erase();
	~Object();
};

