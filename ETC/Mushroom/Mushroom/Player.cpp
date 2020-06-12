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

				return true;
			case 'w':

				return true;
			case 'e':

				return true;
			case 'r':

				return true;
			case 'a':
				Attack();
				return true;
			default:
				return false;
			}
		}
	}

	return false;
}