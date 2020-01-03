#include "Wand.h"



Wand::Wand()
{
}


void Wand::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 30)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "완드 매직클로 효과 발동 완료 !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 60;	
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ 완드 매직클로 효과 발동 실패.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
	
}
void Wand::Draw(int h)
{

	YELLOW
		DrawM.gotoxy(WIDTH - 10, h);
		cout << m_strName << " ( WAND ) " ;
		DrawM.gotoxy(WIDTH - 13, ++h);
	cout << "가격 : " << m_iPrice << " G   공격력 : " << m_iWeaponAttack;
	ORIGINAL
}
Wand::~Wand()
{
	
}
