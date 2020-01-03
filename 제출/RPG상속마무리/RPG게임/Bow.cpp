#include "Bow.h"

Bow::Bow()
{
}

void Bow::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 100) // 확인을위해 100
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText( "보우 크리티컬 효과 발동 완료 !! ", WIDTH, HEIGHT*0.5);
	ORIGINAL
		m_iRandom = 50; // 랜덤확률성공시 공격력 50 추가
	}	
	else
	{
		YELLOW
		DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ 보우 크리티컬 효과 발동 실패.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Bow::Draw(int h)
{
	YELLOW
	DrawM.gotoxy(WIDTH - 10, h);
	cout << m_strName << " ( BOW - 원거리 ) ";
	DrawM.gotoxy(WIDTH - 13, ++h);
	cout << "가격 : " << m_iPrice << " G   공격력 : " << m_iWeaponAttack;
	ORIGINAL
}


Bow::~Bow()
{

}
