#include "Wand.h"



Wand::Wand()
{
	SetType("¡ˆ∆Œ¿Ã");
}

STATUS Wand::Attack()
{
	int check = rand() % 5;

	if (check == 0)
		return STATUS_SHOCK;
	else
		return STATUS_NORMAL;
}

Wand::~Wand()
{
}
