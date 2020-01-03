#include "Character.h"

Character::Character()
{
	h = HEIGHT * 0.1;
	w = WIDTH / 2;
	m_iSelectNum = 0;
	m_iPAttack = 0;
	SetDefault();
}
void Character::SetDefault()
{
	ofstream Save;
	Save.open("Default.txt");
	if (Save.is_open())
	{
		Save << "500 5000 10 0 1 1 100" << endl;
		Save << "6" << endl;
		Save << "달팽이 3 20 5 5 1 0 10" << endl;
		Save << "파란달팽이 20 100 20 50 1 0 20" << endl;
		Save << "빨간달팽이 50 250 50 250 1 0 30" << endl;
		Save << "주황버섯 120 500 500 700 1 0 40" << endl;
		Save << "뿔버섯 200 800 200 1500 1 0 50" << endl;
		Save << "좀비버섯 300 3000 300 3000 1 0 60" << endl;
		Save.close();
	}

	ifstream Load;
	Load.open("Default.txt");

	Load >> m_PLAYER.iAttack;
	Load >> m_PLAYER.iMaxHealth;
	m_PLAYER.iCurHealth = m_PLAYER.iMaxHealth;
	m_PLAYER.iEXP = 0;
	Load >> m_PLAYER.iMaxEXP;
	Load >> m_PLAYER.iGetEXP;
	Load >> m_PLAYER.iLevel;
	Load >> m_PLAYER.iType;
	Load >> m_PLAYER.iGold;
	m_PLAYER.iWAttack = 0;
	Load >> m_iStage;

	m_ENEMY = new CHARAC[m_iStage];
	for (int i = 0; i < m_iStage; i++)
	{
		
		Load >> m_ENEMY[i].strName;
		Load >> m_ENEMY[i].iAttack;
		Load >> m_ENEMY[i].iMaxHealth;
		m_ENEMY[i].iCurHealth = m_ENEMY[i].iMaxHealth;
		m_ENEMY[i].iEXP = 0;
		Load >> m_ENEMY[i].iMaxEXP;
		Load >> m_ENEMY[i].iGetEXP;
		Load >> m_ENEMY[i].iLevel;
		Load >> m_ENEMY[i].iType;
		Load >> m_ENEMY[i].iGold;
		m_ENEMY[i].iWAttack = 0;
	}

	Load.close();
}
void Character::ShowPlayerDetail()
{
	h = HEIGHT * 0.4;
	w = WIDTH / 2;
	ShowDetail(&m_PLAYER);
	DrawManager.gotoxy(0, 33);
}
void Character::ShowMonsterDetail()
{
	h = HEIGHT * 0.1;
	w = WIDTH / 2 ;
	for (int i = 0; i < m_iStage; i++)
	{
		ShowDetail(&m_ENEMY[i]);
		h++;
	}
	
	DrawManager.gotoxy(0, 33);
}
void Character::ShowDetail(CHARAC* C)
{
	DrawManager.gotoxy(w, h);
	RED
	cout <<"====== "<< C->strName << " ( " << C->iLevel << " Lv ) ======";
	ORIGINAL
	DrawManager.gotoxy(w, ++h);
	cout << "공격력 = " << C->iAttack;
	RED
		cout << "(+ " << C->iWAttack << " )";
	ORIGINAL
	BLUE
		cout << "(+ " << m_iPAttack << " )";
	ORIGINAL
	DrawManager.gotoxy(w, ++h);
	cout<<"경험치 = " << C->iEXP << " / " << C->iMaxEXP << "    GetEXP : " << C->iGetEXP ;
	DrawManager.gotoxy(w, ++h);
	cout<<"골드 = " << C->iGold << " G  생명력 = " << C->iCurHealth << " / " << C->iMaxHealth; 
}
void Character::ShowFightPage(int i)
{
	h = HEIGHT * 0.1;
	w = WIDTH /2;
	ShowDetail(&m_PLAYER);
	++h;
	DrawManager.TextDraw("가위 : 0 , 바위 : 1, 보 : 2",w,++h);
	DrawManager.TextDraw("===========================VS===========================", 2, HEIGHT/2);
	h = HEIGHT * 0.75;
	ShowDetail(&m_ENEMY[i]);
}
void Character::CharacterClear()
{
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	RED
	DrawManager.DrawMidText("!!!!!모든 던전을 격파했습니다!!!!!", WIDTH, HEIGHT*0.45);
	DrawManager.DrawMidText("!!!!!축하합니다!!!!!", WIDTH, HEIGHT*0.55);
	ORIGINAL
	DrawManager.gotoxy(0, 33);
	system("pause");
	exit(1);
}
int Character::EnemySelect()
{
	int k = HEIGHT * 0.3;

	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	DrawManager.DrawMidText("▒▒▒▒▒▒ DONGEON ▒▒▒▒▒▒", WIDTH, HEIGHT *0.2);
	for (int i = 0; i < m_iStage; i++)
	{
		DrawManager.gotoxy(WIDTH/2 +2 , k);
		cout << i + 1 << "층 던전 : [ " << m_ENEMY[i].strName << " ]";

		if (m_ENEMY[i].iCurHealth <= 0)
			cout << " ( 처치 완료 )";
		k += 3;
	}
	if (m_ENEMY[0].iCurHealth <= 0 && m_ENEMY[1].iCurHealth <= 0 && m_ENEMY[2].iCurHealth <= 0 && m_ENEMY[3].iCurHealth <= 0 && m_ENEMY[4].iCurHealth <= 0 && m_ENEMY[5].iCurHealth <= 0)
		CharacterClear();
	return( DrawManager.MenuSelectCursor(m_iStage, 3,4, HEIGHT*0.3) -1 );
}
void Character::Fight(int index) // index-1 is monster number
{
	
	while (1)
	{	system("cls");
		DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
		ShowFightPage(index);
		while (1)
		{
			DrawManager.gotoxy(WIDTH , HEIGHT *0.3);
			cin >> m_iPlayerChoice;
			if (m_iPlayerChoice >= 0 && m_iPlayerChoice <= 2)
				break;
		}

		h = HEIGHT * 0.4;
		w = WIDTH;
		m_iEnemyChoice = rand() % 3; // 0-2 
		ShowChoice(m_iPlayerChoice);
		ShowChoice(m_iEnemyChoice);
		if (m_iPlayerChoice == m_iEnemyChoice)
		{
			RED
			DrawManager.TextDraw("DRAW", WIDTH-2, HEIGHT*0.45);
			DrawManager.TextDraw("DRAW", WIDTH - 2, HEIGHT*0.57);
			ORIGINAL
		}
		else if (m_iPlayerChoice > m_iEnemyChoice)
		{
			if (m_iPlayerChoice == 보 && m_iEnemyChoice == 가위)
			{
				RED
					DrawManager.TextDraw("LOSE", WIDTH - 2, HEIGHT*0.45);
					DrawManager.TextDraw("WIN", WIDTH - 2, HEIGHT*0.57);
				ORIGINAL
				Attack(&m_ENEMY[index], &m_PLAYER);
			}
			else
			{
				RED
				DrawManager.TextDraw("WIN", WIDTH - 2, HEIGHT*0.45);
				DrawManager.TextDraw("LOSE", WIDTH - 2, HEIGHT*0.57);
				ORIGINAL
				Attack(&m_PLAYER, &m_ENEMY[index]);
			}
		}
		else
		{
			if (m_iPlayerChoice == 가위 && m_iEnemyChoice == 보)
			{
				RED
				DrawManager.TextDraw("WIN", WIDTH - 2, HEIGHT*0.45);
				DrawManager.TextDraw("LOSE", WIDTH - 2, HEIGHT*0.57);
				ORIGINAL
					Attack(&m_PLAYER, &m_ENEMY[index]);
			}
			else 
			{
				RED
				DrawManager.TextDraw("LOSE", WIDTH - 2, HEIGHT*0.45);
				DrawManager.TextDraw("WIN", WIDTH - 2, HEIGHT*0.57);
				ORIGINAL
				Attack(&m_ENEMY[index], &m_PLAYER);
			}
		}
		DrawManager.gotoxy(0, 33);
		system("pause");
		if (m_PLAYER.iCurHealth <= 0)
		{
			ExpUp(&m_ENEMY[index],&m_PLAYER);
			return;
		}
		else if (m_ENEMY[index].iCurHealth <= 0)
		{
			ExpUp(&m_PLAYER,&m_ENEMY[index]);
			return;
		}
	}
	return;
}
void Character::ExpUp(CHARAC* P1, CHARAC* P2)
{
	int Num; 
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	YELLOW
	DrawManager.DrawMidText(P1->strName, WIDTH , HEIGHT*0.45);
	DrawManager.DrawMidText("!!!!WIN!!!!", WIDTH, HEIGHT*0.55);
	DrawManager.gotoxy(0, 33);
	ORIGINAL

	P1->iEXP += P2->iGetEXP;
	P1->iGold += P2->iGold;
	if (P1->iEXP >= P1->iMaxEXP)
		LevelUp(P1);
	if (P2->iType == PLAYER )
	{	
		P2->iEXP = 0;
		P2->iGetEXP = 0;
	
		DrawManager.BoxErase(WIDTH - 2, HEIGHT - 1);
		DrawManager.gotoxy(WIDTH - 5, HEIGHT*0.5);
		RED
		cout << "GAME OVER!!" << endl;
		ORIGINAL
		Sleep(2000);
		exit(1);
		return;
	}

	if (P1->iType == PLAYER)
		P1->iGetEXP = P1->iEXP;
	
	P1->iCurHealth = P1->iMaxHealth;
	system("pause");
}
void Character::LevelUp(CHARAC* P1)
{
	int Num;
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	RED
	DrawManager.DrawMidText(P1->strName, WIDTH - 6, HEIGHT *0.4);
	DrawManager.DrawMidText(" 레벨 업 !! ", WIDTH + 6, HEIGHT *0.4);
	
	Num = rand() % UPATTACK + 1; 
	P1->iAttack += Num;
	DrawManager.DrawMidText("공격력 <    > 만큼 증가 !",WIDTH , HEIGHT*0.5);
	DrawManager.gotoxy(WIDTH-2, HEIGHT*0.5);
	cout << Num;
	Num = rand() % UPHEALTH + 1;
	P1->iMaxHealth += Num;
	DrawManager.DrawMidText("생명력 <    > 만큼 증가 !", WIDTH, HEIGHT*0.6);
	DrawManager.gotoxy(WIDTH-2 , HEIGHT*0.6);
	cout <<  Num ;
	ORIGINAL
	DrawManager.gotoxy(0,HEIGHT+3);
	P1->iEXP = 0;
	P1->iMaxEXP += P1->iMaxEXP * 0.2;
	P1->iLevel++;
	P1->iCurHealth = P1->iMaxHealth;
}
void Character::Attack(CHARAC* P1, CHARAC* P2)
{
	P2->iCurHealth -= P1->iAttack;
	if (P2->iCurHealth < 0)
		P2->iCurHealth = 0;

}
void Character::ShowChoice(int Num)
{

	switch (Num)
	{
	case 가위:
		DrawManager.TextDraw("▶ 가위 ◀", w-4, h);
		break;
	case 바위:
		DrawManager.TextDraw("▶ 바위 ◀", w-4, h);
		break;
	case 보:
		DrawManager.TextDraw("▶ 보 ◀", w-4, h);
		break;
	default:
		break;
	}
	h += 6;
	
}
void Character::FileList()
{
	char buf[256];
	for (int i = 1; i <= 10; i++)
	{
		sprintf(buf, "SaveFile%d.txt", i); 
		ifstream Save;
		Save.open(buf);
		DrawManager.gotoxy(WIDTH / 2,i+10);
		GREEN
			cout << i << " 번 슬롯 : ( 파일 여부 : ";
		if (!Save.is_open())
			cout << " X )" << endl;
		else
		{
			cout << " O )" << endl;
			Save.close();
		}
		ORIGINAL
	}
	GREEN
	m_iSelectNum=DrawManager.MenuSelectCursor(10, 1, 5, 11);
	ORIGINAL
	system("pause");
}
void Character::Save()
{
	char buf[256];

	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	FileList();
	ofstream Save;
	sprintf(buf, "SaveFile%d.txt", m_iSelectNum);
	Save.open(buf);
	if (Save.is_open())
	{
		Save << m_PLAYER.strName<< " ";
		Save << m_PLAYER.iAttack<< " ";
		Save << m_PLAYER.iCurHealth << " ";
		Save << m_PLAYER.iMaxHealth << " ";
		Save << m_PLAYER.iEXP << " ";
		Save << m_PLAYER.iGetEXP << " ";
		Save << m_PLAYER.iMaxEXP << " ";
		Save << m_PLAYER.iLevel << " ";
		Save << m_PLAYER.iType << " ";
		Save << m_PLAYER.iGold <<endl;
		Save << m_iStage<<endl;
		for (int i = 0; i < m_iStage; i++)
		{
			Save << m_ENEMY[i].strName << " ";
			Save << m_ENEMY[i].iAttack << " ";
			Save << m_ENEMY[i].iCurHealth << " ";
			Save << m_ENEMY[i].iMaxHealth << " ";
			Save << m_ENEMY[i].iEXP << " ";
			Save << m_ENEMY[i].iGetEXP << " ";
			Save << m_ENEMY[i].iMaxEXP << " ";
			Save << m_ENEMY[i].iLevel << " ";
			Save << m_ENEMY[i].iType << " ";
			Save << m_ENEMY[i].iGold << endl;
		}
		Save.close();
	}


}
int Character::Load()
{
	ifstream Load;
	char buf[256];
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	FileList();
	sprintf(buf, "SaveFile%d.txt", m_iSelectNum);
	Load.open(buf);
	if (!Load.is_open())
	{
		DrawManager.BoxErase(WIDTH - 2, HEIGHT - 1);
		GREEN
		DrawManager.DrawMidText("※ 해당 저장 파일이 없습니다. ※", WIDTH, HEIGHT*0.5);
		ORIGINAL
		DrawManager.gotoxy(0, HEIGHT + 3);
		system("pause");
		return 0;
	}
	Load>> m_PLAYER.strName ;
	Load >> m_PLAYER.iAttack ;
	Load >> m_PLAYER.iCurHealth;
	Load >> m_PLAYER.iMaxHealth;
	Load >> m_PLAYER.iEXP ;
	Load >> m_PLAYER.iGetEXP;
	Load >> m_PLAYER.iMaxEXP;
	Load >> m_PLAYER.iLevel ;
	Load >> m_PLAYER.iType ;
	Load >> m_PLAYER.iGold ;
	Load>>  m_iStage ;
	for (int i = 0; i < m_iStage; i++)
	{
		Load >> m_ENEMY[i].strName ;
		Load >> m_ENEMY[i].iAttack ;
		Load >> m_ENEMY[i].iCurHealth;
		Load >> m_ENEMY[i].iMaxHealth;
		Load >> m_ENEMY[i].iEXP ;
		Load >> m_ENEMY[i].iGetEXP ;
		Load >> m_ENEMY[i].iMaxEXP ;
		Load >> m_ENEMY[i].iLevel ;
		Load>> m_ENEMY[i].iType ;
		Load >> m_ENEMY[i].iGold;
	}
	Load.close();
	return 1;
	
}
void Character::BuyWeapon()
{
	bool tmp = false;
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	
	while (!tmp)
	{
		RED
		DrawManager.DrawMidText("보유 골드 : ", WIDTH - 3, HEIGHT*0.95);
		DrawManager.gotoxy(WIDTH + 6, HEIGHT*0.95);
		cout << m_PLAYER.iGold;
		ORIGINAL
		ShopManager.ShowShop();

		if (m_PLAYER.iGold >= ShopManager.GetSelectGold() && ShopManager.GetSelectGold() > 1 && ShopManager.GetFlag() == true )
		{
			m_PLAYER.iGold -= ShopManager.GetSelectGold(); // 무기값을 빼주고 
			m_PLAYER.iAttack += ShopManager.GetSelectAttack(); // 무기공격력을 더해준다.
			m_PLAYER.iWAttack += ShopManager.GetSelectAttack();
			ShopManager.Random();
			m_iPAttack += ShopManager.GetPlusAttack();
			m_PLAYER.iAttack += m_iPAttack;
			RED
			DrawManager.BoxErase(WIDTH - 2, HEIGHT );
			DrawManager.DrawMidText(to_string(ShopManager.GetSelectGold()) + " G를 사용하여 구매 완료 ! ", WIDTH, HEIGHT*0.45);
			DrawManager.DrawMidText(to_string(m_PLAYER.iGold) + " G가 남았다! ", WIDTH, HEIGHT*0.55);
			ORIGINAL
				DrawManager.gotoxy(0, 33);
				system("pause");
		}
			
		tmp = true;
	
		
	}
	
}

Character::~Character()
{
	delete[] m_ENEMY;
	delete &m_PLAYER;
}

