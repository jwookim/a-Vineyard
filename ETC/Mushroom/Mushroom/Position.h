#pragma once
#include<iostream>
using namespace std;
#define UP {0, -1}
#define DOWN {0, 1}
#define LEFT {-1, 0}
#define RIGHT {1, 0}


class Position
{
private:

public:
	int x;
	int y;

	friend Position operator +(Position p1, Position p2);

	friend bool operator >=(Position p1, Position p2);

	friend bool operator <=(Position p1, Position p2);

	friend bool operator >(Position p1, Position p2);

	friend bool operator <(Position p1, Position p2);

	friend bool operator ==(Position p1, Position p2);
};
