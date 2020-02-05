#include "Word.h"



Word::Word()
{
	m_NextWord = NULL;
}

void Word::Drop()
{
	m_iy++;
}

Word::~Word()
{
}
