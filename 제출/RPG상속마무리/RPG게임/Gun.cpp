#include "Gun.h"



Gun::Gun()
{
}
void Gun::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 30)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "건 치명타 효과 발동 완료 !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 80;
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ 건 치명타 효과 발동 실패.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}

void Gun::Draw(int h)
{

	YELLOW
		DrawM.gotoxy(WIDTH - 10, h);
		cout << m_strName << " ( GUN - 원거리 ) ";	
		DrawM.gotoxy(WIDTH - 13, ++h);
		cout << "가격 : " << m_iPrice << " G   공격력 : " << m_iWeaponAttack ;
	ORIGINAL
}

Gun::~Gun()
{
}
