#include "Player.h"

bool Player::MoveCheck()
{
	if (MoveTimeCheck())
	{
		if (kbhit())
		{
			if (getch() == ARROW)
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