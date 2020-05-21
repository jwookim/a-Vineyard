#include "Character.h"

void Character::TimeCheck()
{

}

bool Character::MoveInput()
{
	if (MoveCheck())
	{
		if (kbhit())
		{
			if (getch() == 224)
			{
				switch (getch())
				{
				case ARROW_UP:
					Move(UP);
				case ARROW_DOWN:
					Move(DOWN);
				case ARROW_LEFT:
					Move(LEFT);
				case ARROW_RIGHT:
					Move(RIGHT);
				}
				return true;
			}
		}
	}

	return false;
}