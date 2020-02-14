#include "Word.h"



Word::Word()
{
	m_bState = false;
}

void Word::SetName(string name)
{
	m_strName = name;
}

void Word::Live()
{
	m_ix = rand() % ((WIDTH * 2) - (GAP * 2)) + GAP;
	m_iy = 1;

	if (rand() % 5 == 0)
	{
		m_Effect = (EFFECT)(rand() % 5 + 2);
	}
	else
		m_Effect = EFFECT_NORMAL;
	
	m_bState = true;

	Draw();
}

void Word::Dead()
{
	Erase();
	Init();
}

void Word::Drop()
{
	m_iy++;
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

void Word::Hide()
{
	string hide;
	for (int i = 0; i < m_strName.length(); i++)
		hide += "=";
	if (m_iy < HEIGHT)
	{
		if (m_Effect == EFFECT_NORMAL)
			BLUE
		else
			PUPPLE

			DrawManager.DrawMidText(hide, m_ix, m_iy);
	}
}

void Word::Erase()
{
	GRAY
		DrawManager.DrawMidText(m_strName, m_ix, m_iy);;
}

void Word::Init()
{
	m_ix = 0;
	m_iy = 0;

	m_Effect = EFFECT_NORMAL;

	m_bState = false;
}

Word::~Word()
{
	Erase();
}
