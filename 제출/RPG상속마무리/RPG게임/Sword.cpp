#include "Sword.h"



Sword::Sword()
{
}

void Sword::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 30)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "소드 더블어택 효과 발동 완료 !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 70;
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ 소드 더블어택 효과 발동 실패.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Sword::Draw(int h)
{

	YELLOW
	DrawM.gotoxy(WIDTH - 10, h);
	cout << m_strName << " ( SWORD - 근접 ) " ;
	DrawM.gotoxy(WIDTH - 13, ++h);
	cout << "가격 : " << m_iPrice << " G   공격력 : " << m_iWeaponAttack ;
	ORIGINAL
}


Sword::~Sword()
{

}
