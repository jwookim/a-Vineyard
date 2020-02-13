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

	Draw();
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
	Erase();
	m_iy++;
	Draw();
}

void Word::Draw()
{
	if (m_iy < HEIGHT)
	{
		if (m_Effect == EFFECT_NORMAL)
			BLUE
		else
			PUPPLE

			DrawManager.DrawMidText(m_strName, m_ix, m_iy);
	}
}

void Word::Erase()
{
	GRAY
		DrawManager.DrawMidText(m_strName, m_ix, m_iy);;
}

Word::~Word()
{
	Erase();
}
