#include "Teemo.h"


Teemo::Teemo()
{
	SetShape("¿À");
	SetColor(YELLOW);
	SetRange(RANGE_LONG);
	SetAtk(70);
	SetHealth(400);
	SetAtkSpeed(70);

	SetSpeed(90);
	SetPosition({ WIDTH / 4, HEIGHT / 2 });
	Draw();
}