#include "Player.h"

bool Player::MoveCheck()
{
	if (MoveTimeCheck())
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case ARROW:
				switch (_getch())
				{
				case ARROW_UP:
					Move(UP);
					break;
				case ARROW_DOWN:
					Move(DOWN);
					break;
				case ARROW_LEFT:
					Move(LEFT);
					break;
				case ARROW_RIGHT:
					Move(RIGHT);
					break;
				}
				return true;
			case 'q':

				return false;
			case 'w':

				return false;
			case 'e':

				return false;
			case 'r':

				return false;
			case 'a':
				Attack();
				return false;
			default:
				return false;
			}
		}
	}

	return false;
}