#include "Teemo.h"


Teemo::Teemo()
{
	SetShape("¿À");
	SetColor(YELLOW);


	SetSpeed(90);
	SetPosition({ WIDTH / 4, HEIGHT / 2 });
	Draw();
}