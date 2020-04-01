#pragma once
#include"Play.h"
#include <stdlib.h>
#include <crtdbg.h>

void main()
{
	Play play;
	play.Setting();

	play.Start();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}