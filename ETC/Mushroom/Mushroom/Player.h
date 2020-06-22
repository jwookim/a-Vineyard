#pragma once
#include "Character.h"

class Player : public Character
{
private:
	
public:
	Player(Position pos);
	bool MoveCheck();
};

