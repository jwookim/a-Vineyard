#include "Block.h"


Block::Block(Position pos)
{
	SetShape('бс');
	SetColor(DARK_BLUE);
	SetPosition(pos);
	Draw();
}