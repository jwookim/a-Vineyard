#pragma once
#include "Weapon.h"

class Wand : public Weapon
{
public:
	STATUS Attack();
	Wand();
	~Wand();
};

