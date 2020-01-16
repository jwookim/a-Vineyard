#pragma once
#include "Weapon.h"

class Gun : public Weapon
{
public:
	Gun();
	void Draw(int h);
	void Show();
	~Gun();
};

