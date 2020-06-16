#include "Garen.h"


Garen::Garen()
{
	SetShape("บุ");
	SetColor(BLUE);
	SetRange(RANGE_CLOSE);
	SetAtk(100);
	SetHealth(600);
	SetAtkSpeed(120);

	SetSpeed(100);
	SetPosition({ WIDTH / 4, HEIGHT / 4 });
	Draw();
}