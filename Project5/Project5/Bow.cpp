#include "Bow.h"



Bow::Bow()
{
	SetType("헌트");
}

STATUS Bow::Attack()
{
	int check = rand() % 3;

	if (check == 0)
		return STATUS_BLEEDING;
	else
		return STATUS_NORMAL;
}

Bow::~Bow()
{
}
