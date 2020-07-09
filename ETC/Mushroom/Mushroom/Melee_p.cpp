#include "Melee_p.h"
#include "Character.h"

Melee_long::Melee_long(MovingObject* caster) : Projectile(caster)
{
	m_iColor = caster->GetColor();
	m_iSpeed = 300;
	m_iDuration = SECOND * 5;
	m_Attack = &(((Character*)caster)->MeleeAttack);

	if (m_Direct.x == 1)
		SetShape("¡æ");
	else if (m_Direct.x == -1)
		SetShape("¡ç");
	else if (m_Direct.y == 1)
		SetShape("¡é");
	else if (m_Direct.y == -1)
		SetShape("¡è");

	Draw();
}

Melee_close::Melee_close(MovingObject* caster) : Projectile(caster)
{
	m_iColor = caster->GetColor();
	m_iSpeed = 190;
	m_iDuration = SECOND / 2;
	m_Attack = &(((Character*)caster)->MeleeAttack);

	if (m_Direct.x == 1)
		SetShape("¢º");
	else if (m_Direct.x == -1)
		SetShape("¢¸");
	else if (m_Direct.y == 1)
		SetShape("¡å");
	else if (m_Direct.y == -1)
		SetShape("¡ã");

	Draw();
}