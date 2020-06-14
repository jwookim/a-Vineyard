#include "Projectile.h"

Projectile::Projectile(Direct dir)
{
	SetDirect(dir);
	SetMoveTime(clock());
}

void Projectile::SetCaster(MovingObject* caster)
{
	m_Caster = caster;
}

bool Projectile::MoveCheck()
{
	if (MoveTimeCheck())
	{
		Move(GetDirect());
		return true;
	}
	return false;
}