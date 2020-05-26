#include "Projectile.h"

bool Projectile::MoveCheck()
{
	if (MoveTimeCheck())
	{
		Move(GetDirect());
		return true;
	}
	return false;
}