#pragma once
#include"Projectile.h"
class Melee_p : public Projectile
{
private:

public:
	Melee_p(Position pos, Direct dir, MovingObject* caster);
};

