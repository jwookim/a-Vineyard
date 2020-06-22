#include "Projectile.h"

Projectile::Projectile(MovingObject* caster) : MovingObject(caster->GetPosition() + caster->GetDirect())
{
	m_Caster = caster;
	m_Direct = m_Caster->GetDirect();
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