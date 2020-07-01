#pragma once
#include"Projectile.h"
class Melee_long : public Projectile
{
private:

public:
	Melee_long(MovingObject* caster);
};

class Melee_close : public Projectile
{
private:

public:
	Melee_close(MovingObject* caster);
};