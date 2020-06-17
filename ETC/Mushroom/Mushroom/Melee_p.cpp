#include "Melee_p.h"


Melee_p::Melee_p(Position pos, Direct dir, MovingObject* caster)
{
	SetPosition(pos);
	SetDirect(dir);
	SetSpeed(300);
	SetCaster(caster);
	SetColor(caster->GetColor());

	if (dir.x == 1)
		SetShape("กๆ");
	else if (dir.x == -1)
		SetShape("ก็");
	else if (dir.y == 1)
		SetShape("ก้");
	else if (dir.y == -1)
		SetShape("ก่");

	Draw();
}