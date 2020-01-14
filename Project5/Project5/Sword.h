#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	STATUS Attack();
	Sword();
	~Sword();
};

