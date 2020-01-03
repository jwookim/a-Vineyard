#pragma once
#include"Weapon.h"
class Bow : public Weapon
{
public:
	Bow();
	void Draw(int h);
	void Show();
	~Bow();
};

