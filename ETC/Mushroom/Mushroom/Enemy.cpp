#include "Enemy.h"

Enemy::Enemy(Position pos) : Character(pos)
{

}

bool Enemy::MoveCheck()
{
	return false;
}