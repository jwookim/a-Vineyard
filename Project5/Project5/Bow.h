#pragma once
#include "Weapon.h"
class Bow : public Weapon
{
public:
	STATUS Attack();
	Bow();
	~Bow();
};

