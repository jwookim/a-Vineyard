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
				case ARROW:
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
				case 'q':

					return true;
				case 'w':

					return true;
				case 'e':

					return true;
				case 'r':

					return true;
				case 'a':

					return true;
				default:
					return false;
				}
			}
		}
	}

	return false;
}