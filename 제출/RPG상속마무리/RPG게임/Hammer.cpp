#include "Hammer.h"



Hammer::Hammer()
{

}

void Hammer::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 40)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "해머 충격파 효과 발동 완료 !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 40;
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ 해머 충격파 효과 발동 실패.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Hammer::Draw(int h)
{

	YELLOW
		DrawM.gotoxy(WIDTH - 10, h);
		cout << m_strName << " ( HAMMER - 근접 ) ";
		DrawM.gotoxy(WIDTH - 13, ++h);
		cout << "가격 : " << m_iPrice << " G   공격력 : " << m_iWeaponAttack ;
	ORIGINAL
}
Hammer::~Hammer()
{

}
