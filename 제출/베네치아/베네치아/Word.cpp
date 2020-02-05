#include "Word.h"



Word::Word()
{
	m_NextWord = NULL;
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
