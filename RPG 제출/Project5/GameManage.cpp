#include "GameManage.h"



GameManage::GameManage()
{
	char buff[50];
	sprintf(buff, "mode con: cols=%d lines=%d", WIDTH * 2 + 1, HEIGHT);
	system(buff);

	m_Player = NULL;
	m_Monster = NULL;
}

void GameManage::Start()
{
	int line;
	int Margin = 3;
	int Select = 0;


	while (Select != 3)
	{
		line = 0;

		DrawManager.ClearWindow();

		DrawManager.DrawMidText("☆★ DunGeonRPG ★☆", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("New Game", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Load Game", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Game Exit", WIDTH, 10 + (Margin * line++));
		Select = DrawManager.MenuSelectCursor(3, Margin, WIDTH / 3, 10 + Margin);

		switch (Select)
		{
		case 1:
			NewGame();
			Menu();
			break;
		case 2:
			if (LoadGame())
				Menu();
			break;
		}
	}
}

void GameManage::NewGame()
{
	DrawManager.ClearWindow();

	string name;

	m_Player = new Character;

	YELLOW
	DrawManager.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT / 2);
	cin >> name;
	m_Player->SetName(name);
	ORIGINAL

		ReadDefaultPlayer();

	ReadDefaultMonster();
}

bool GameManage::LoadGame()
{
	int Margin = 2;
	int line = 0;
	int Select = 0;
	int num;
	ifstream slot;

	
	while (1)
	{
		DrawManager.ClearWindow();
		num = 1;
		line = 0;
		GREEN
			for (; num <= 10; num++)
			{
				DrawManager.DrawMidText(to_string(num) + "번슬롯 : (파일여부 : ", WIDTH, 5 + (Margin * line++));
				slot.open("SavePlayer" + to_string(num) + ".txt");
				if (slot.is_open())
					cout << "O)";
				else
					cout << "X)";
				slot.close();
			}
		DrawManager.DrawMidText(to_string(num) + ".돌아가기", WIDTH, 5 + (Margin * line++));
		ORIGINAL

			Select = DrawManager.MenuSelectCursor(11, Margin, WIDTH / 4, 5);
		
		if (Select == num)
			return false;
		else
		{
			slot.open("SavePlayer" + to_string(Select) + ".txt");
			if (slot.is_open())
			{
				slot.close();
				ReadPlayer(Select);
				ReadMonster(Select);
				return true;
			}
			else
			{
				slot.close();
				DrawManager.ClearWindow();

				DrawManager.DrawMidText("파일이 없습니다.", WIDTH, HEIGHT / 2);
				getch();
			}
			
		}
	}
}

void GameManage::ReadDefaultPlayer()
{
	ifstream load;
	int tmp;

	load.open("DefaultPlayer.txt");
	if (load.is_open())
	{
		load >> tmp;
		m_Player->SetAtk(tmp);

		load >> tmp;
		m_Player->SetHealth(tmp);
		m_Player->SetMaxHealth(tmp);

		load >> tmp;
		m_Player->SetMaxExp(tmp);

		load >> tmp;
		m_Player->SetExp(tmp);
		m_Player->SetGetExp(tmp);

		load >> tmp;
		m_Player->SetLevel(tmp);

		load >> tmp;
		m_Player->SetGold(tmp);

		load.close();
	}
}

void GameManage::ReadDefaultMonster()
{
	ifstream load;
	string name;
	int tmp;

	load.open("DefaultMonster.txt");

	while (!load.eof())
	{
		load >> tmp;
		m_iMonsterNum = tmp;
		m_Monster = new Character[m_iMonsterNum];
		for (int i = 0; i < m_iMonsterNum; i++)
		{
			load >> name;
			m_Monster[i].SetName(name);

			load >> tmp;
			m_Monster[i].SetAtk(tmp);

			load >> tmp;
			m_Monster[i].SetHealth(tmp);
			m_Monster[i].SetMaxHealth(tmp);

			load >> tmp;
			m_Monster[i].SetMaxExp(tmp);

			load >> tmp;
			m_Monster[i].SetGetExp(tmp);

			m_Monster[i].SetExp(0);

			load >> tmp;
			m_Monster[i].SetLevel(tmp);

			load >> tmp;
			m_Monster[i].SetGold(tmp);
		}
	}

	load.close();
}

void GameManage::ReadPlayer(int num)
{
	m_Player = new Character;

	ifstream load;
	int tmp;
	string name;

	load.open("SavePlayer" + to_string(num) + ".txt");
	if (load.is_open())
	{
		load >> name;
		m_Player->SetName(name);

		load >> tmp;
		m_Player->SetAtk(tmp);

		load >> tmp;
		m_Player->SetMaxHealth(tmp);

		load >> tmp;
		m_Player->SetMaxExp(tmp);

		load >> tmp;
		m_Player->SetGetExp(tmp);

		load >> tmp;
		m_Player->SetLevel(tmp);

		load >> tmp;
		m_Player->SetGold(tmp);

		load >> tmp;
		m_Player->SetExp(tmp);

		load >> tmp;
		m_Player->SetHealth(tmp);

		load >> name;
		if (name != "0")
			m_Player->EquipWeapon(m_Shop.LoadWeapon(name));
		else
			m_Player->EquipWeapon(NULL);

		load.close();
	}
}

void GameManage::ReadMonster(int num)
{
	ifstream load;
	string name;
	int tmp;

	load.open("SaveMonster" + to_string(num) + ".txt");

	while (!load.eof())
	{
		load >> tmp;
		m_iMonsterNum = tmp;
		m_Monster = new Character[m_iMonsterNum];
		for (int i = 0; i < m_iMonsterNum; i++)
		{
			load >> name;
			m_Monster[i].SetName(name);

			load >> tmp;
			m_Monster[i].SetAtk(tmp);

			load >> tmp;
			m_Monster[i].SetMaxHealth(tmp);

			load >> tmp;
			m_Monster[i].SetMaxExp(tmp);

			load >> tmp;
			m_Monster[i].SetGetExp(tmp);

			load >> tmp;
			m_Monster[i].SetLevel(tmp);

			load >> tmp;
			m_Monster[i].SetGold(tmp);

			load >> tmp;
			m_Monster[i].SetExp(tmp);

			load >> tmp;
			m_Monster[i].SetHealth(tmp);
		}
	}

	load.close();
}

void GameManage::Menu()
{
	int line;
	int Margin = 2;
	int Select = 0;

	

	while (Select != 6)
	{
		line = 0;
		DrawManager.ClearWindow();

		DrawManager.DrawMidText("☆★ Menu ★☆", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Dungeon", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Player Info", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Monster Info", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Weapon Shop", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Save", WIDTH, 10 + (Margin * line++));
		DrawManager.DrawMidText("Exit", WIDTH, 10 + (Margin * line++));

		Select = DrawManager.MenuSelectCursor(6, Margin, WIDTH / 3, 10 + Margin);

		switch (Select)
		{
		case 1:
			if (!m_Dungeon.Menu(m_Player, m_Monster, m_iMonsterNum))
				Select = 6;
			break;
		case 2:
			PlayerInfo();
			break;
		case 3:
			MonsterInfo();
			break;
		case 4:
			m_Shop.Menu(m_Player);
			break;
		case 5:
			Save();
			break;
		}
	}

	DeleteInfo();
}

void GameManage::PlayerInfo()
{
	DrawManager.ClearWindow();
	YELLOW
		m_Player->ShowInfo(HEIGHT / 2);
	ORIGINAL

		getch();
}

void GameManage::MonsterInfo()
{
	DrawManager.ClearWindow();
	int line = HEIGHT / 10;
	for (int i = 0; i < m_iMonsterNum; i++)
	{
		line = m_Monster[i].ShowInfo(line);
	}

	getch();
}

void GameManage::Save()
{
	int Margin = 2;
	int line = 0;
	int Select = 0;
	int num;
	ifstream slot;

	while (1)
	{
		DrawManager.ClearWindow();
		num = 1;
		line = 0;
		GREEN
			for (; num <= 10; num++)
			{
				DrawManager.DrawMidText(to_string(num) + "번슬롯 : (파일여부 : ", WIDTH, 5 + (Margin * line++));
				slot.open("SavePlayer" + to_string(num) + ".txt");
				if (slot.is_open())
					cout << "O)";
				else
					cout << "X)";
				slot.close();
			}
		DrawManager.DrawMidText(to_string(num) + ".돌아가기", WIDTH, 5 + (Margin * line++));
		ORIGINAL

			Select = DrawManager.MenuSelectCursor(11, Margin, WIDTH / 4, 5);

		if (Select == num)
			break;
		else
		{
			SaveData(Select);
			break;
		}
	}
}

void GameManage::SaveData(int num)
{
	ofstream save;
	save.open("SavePlayer" + to_string(num) + ".txt");

	save << m_Player->GetName() << " ";

	save << m_Player->GetAtk() << " ";

	save << m_Player->GetMaxHealth() << " ";

	save << m_Player->GetMaxExp() << " ";

	save << m_Player->GetGetExp() << " ";

	save << m_Player->GetLevel() << " ";

	save << m_Player->GetGold() << " ";

	save << m_Player->GetExp() << " ";

	save << m_Player->GetHealth() << endl;

	if (m_Player->GetWeapon() != NULL)
	{
		save << m_Player->GetWeapon()->GetName();
	}
	else
		save << "0";

	save.close();

	save.open("SaveMonster" + to_string(num) + ".txt");

	save << m_iMonsterNum;
	for (int i = 0; i < m_iMonsterNum; i++)
	{
		save << endl;

		save << m_Monster[i].GetName() << " ";

		save << m_Monster[i].GetAtk() << " ";

		save << m_Monster[i].GetMaxHealth() << " ";

		save << m_Monster[i].GetMaxExp() << " ";

		save << m_Monster[i].GetGetExp() << " ";

		save << m_Monster[i].GetLevel() << " ";

		save << m_Monster[i].GetGold() << " ";

		save << m_Monster[i].GetExp() << " ";

		save << m_Monster[i].GetHealth();
	}

	save.close();
}

void GameManage::DeleteInfo()
{
	if (m_Player != NULL)
	{
		delete m_Player;
		m_Player = NULL;
	}


	if (m_Monster != NULL)
	{
		delete[] m_Monster;
		m_Monster = NULL;
	}
}

GameManage::~GameManage()
{
	DeleteInfo();
}
