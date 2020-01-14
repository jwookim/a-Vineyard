#pragma once
#include "Weapon.h"

class Dagger : public Weapon
{
public:
	STATUS Attack();
	Dagger();
	~Dagger();
};

