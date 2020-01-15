#pragma once
#include "Weapon.h"

class Gun : public Weapon
{
public:
	STATUS Attack();
	Gun();
	~Gun();
};

