#include "Dagger.h"



Dagger::Dagger()
{

}

void Dagger::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <=40)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "대거 파워스트라이크 효과 발동 완료 !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 30;
	}
	else
	{
		YELLOW
		DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ 대거 파워스트라이크 효과 발동 실패.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Dagger::Draw(int h)
{
	YELLOW
	DrawM.gotoxy(WIDTH-10, h);
	cout << m_strName << " ( DAGGER - 근접 ) " ;
	DrawM.gotoxy(WIDTH-13, ++h);
	cout << "가격 : " << m_iPrice << " G   공격력 : " << m_iWeaponAttack;
	ORIGINAL
}
Dagger::~Dagger()
{
}
