#include "Melee_p.h"


Melee_p::Melee_p(MovingObject* caster) : Projectile(caster)
{
	m_iColor = caster->GetColor();
	m_iSpeed = 300;

	if (m_Direct.x == 1)
		SetShape("กๆ");
	else if (m_Direct.x == -1)
		SetShape("ก็");
	else if (m_Direct.y == 1)
		SetShape("ก้");
	else if (m_Direct.y == -1)
		SetShape("ก่");

	Draw();
}