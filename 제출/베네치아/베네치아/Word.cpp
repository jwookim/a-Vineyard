#include "Word.h"



Word::Word()
{
	m_NextWord = NULL;
	m_ix = rand() % (WIDTH * 2 - (GAP * 2)) - GAP;
	m_iy = 1;

	if (rand() % 10 == 0)
	{
		m_Effect = (EFFECT)(rand() % 5 + 2);
	}
	else
		m_Effect = EFFECT_NORMAL;
}

void Word::SetName(string name)
{
	m_strName = name;
}

void Word::SetNextWord(Word* nextWord)
{
	m_NextWord = nextWord;
}

void Word::Drop()
{
	m_iy++;
}

Word::~Word()
{
}
