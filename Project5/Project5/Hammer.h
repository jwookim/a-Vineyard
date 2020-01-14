#pragma once
#include "Weapon.h"

class Hammer : public Weapon
{
public:
	STATUS Attack();
	Hammer();
	~Hammer();
};

