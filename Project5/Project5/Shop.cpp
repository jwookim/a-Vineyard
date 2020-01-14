#include "Shop.h"



Shop::Shop()
{
	for (int i = 0; i < WPNUM; i++)
	{
		m_Weapon[i] = NULL;
		m_iWeaponNum[i] = 0;
	}

	ifstream load;
	string tmp;
	int tmpNum;
	WEAPON type;
	Weapon* weapon;
	load.open("WeaponList.txt");

	while (!load.eof())
	{
		load >> tmp;
		if (tmp == "Bow")
		{
			weapon = new Bow;
			type = WEAPON_BOW;
		}
		else if (tmp == "Dagger")
		{
			weapon = new Dagger;
			type = WEAPON_DAGGER;
		}
		else if (tmp == "Gun")
		{
			weapon = new Gun;
			type = WEAPON_GUN;
		}
		else if (tmp == "Sword")
		{
			weapon = new Sword;
			type = WEAPON_SWORD;
		}
		else if (tmp == "Wand")
		{
			weapon = new Wand;
			type = WEAPON_WAND;
		}
		else if (tmp == "Hammer")
		{
			weapon = new Hammer;
			type = WEAPON_HAMMER;
		}
		else
			break;

		load >> tmp;
		weapon->SetName(tmp);

		load >> tmpNum;
		weapon->SetAtk(tmpNum);

		load >> tmpNum;
		weapon->SetPrice(tmpNum);
		addWeapon(weapon, type);

		m_iWeaponNum[type]++;

		
	}

	load.close();
}

void Shop::Menu(Character* player)
{
	int Select = 0;
	int Margin = 2;
	int line;
	while (Select != 7)
	{
		line = 0;
		DrawManager.ClearWindow();

		DrawManager.DrawMidText("♧ ♣ S H O P ♣ ♧", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Dagger", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Gun", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Sword", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Wand", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Bow", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Hammer", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT / 4 + (Margin * line++));

		Select = DrawManager.MenuSelectCursor(7, 2, WIDTH / 2 - 3, HEIGHT / 4 + Margin);

		if (Select != 7)
			ShowList(player, (WEAPON)(Select - 1));
	}
}

void Shop::ShowList(Character* player, WEAPON type)
{
	int Select = 0;
	int listsize = 0;
	int listStartNum = 0;
	int Margin = 3;
	int line = 0;
	string tmp;

	switch (type)
	{
	case WEAPON_DAGGER:
		tmp = "Dagger";
		break;
	case WEAPON_GUN:
		tmp = "Gun";
		break;
	case WEAPON_SWORD:
		tmp = "Sword";
		break;
	case WEAPON_WAND:
		tmp = "Wand";
		break;
	case WEAPON_BOW:
		tmp = "Bow";
		break;
	case WEAPON_HAMMER:
		tmp = "Hammer";
		break;
	}

	while (Select != listsize + 3)
	{
		DrawManager.ClearWindow();
		DrawManager.DrawMidText("보유 Gold : " + to_string(player->GetGold()), WIDTH, 3);
		DrawManager.DrawMidText(tmp + " Shop", WIDTH, 5);

		if (listStartNum + LISTSIZE <= m_iWeaponNum[type])
			listsize = LISTSIZE;
		else
			listsize = m_iWeaponNum[type] % 5;
		YELLOW
			ShowWeapon(type, listStartNum, listStartNum + listsize, 7);
		ORIGINAL

			line = listsize;

		DrawManager.DrawMidText("이전 페이지", WIDTH, 7 + (Margin * line++));
		DrawManager.DrawMidText("다음 페이지", WIDTH, 7 + (Margin * line++));
		DrawManager.DrawMidText("돌아가기", WIDTH, 7 + (Margin * line++));

		Select = DrawManager.MenuSelectCursor(listsize + 3, Margin, WIDTH / 6, 7);

		if (Select <= listsize)
		{
			player->BuyItem(SearchWeapon(type, (Select - 1) + listStartNum));
			break;
		}
		else if (Select == listsize + 1)
		{
			if (listStartNum - LISTSIZE >= 0)
				listStartNum -= LISTSIZE;
		}
		else if (Select == listsize + 2)
		{
			if (listStartNum + LISTSIZE < m_iWeaponNum[type])
				listStartNum += LISTSIZE;
		}

	}

}

void Shop::ShowWeapon(WEAPON type, int startNum, int endNum, int line)
{
	if (m_Weapon[type] != NULL)
		ShowWeapon(m_Weapon[type], startNum, endNum, line);
}

void Shop::ShowWeapon(Weapon* weapon, int startNum, int endNum, int line)
{
	if (startNum <= 0)
	{
		weapon->ShowInfo_Shop(line);
		line += 3;
		endNum--;
	}

	startNum--;

	if (weapon->GetNextWeapon() != NULL && endNum > 0)
		ShowWeapon(weapon->GetNextWeapon(), startNum, endNum, line);
}

void Shop::addWeapon(Weapon* newWeapon, WEAPON type)
{
	if (m_Weapon[type] != NULL)
		addWeapon(newWeapon, m_Weapon[type]);
	else
		m_Weapon[type] = newWeapon;
}

void Shop::addWeapon(Weapon* newWeapon, Weapon* check)
{
	if (check->GetNextWeapon() != NULL)
		addWeapon(newWeapon, check->GetNextWeapon());
	else
		check->SetNextWeapon(newWeapon);
}

Weapon* Shop::SearchWeapon(WEAPON type, int num)
{
	if (m_Weapon[type] != NULL)
	{
		if (num <= 0)
			return m_Weapon[type];
		else
			return SearchWeapon(m_Weapon[type], num - 1);
	}
	else
		return NULL;
}

Weapon* Shop::SearchWeapon(Weapon* weapon, int num)
{
	if (weapon->GetNextWeapon() != NULL)
	{
		if (num <= 0)
			return weapon->GetNextWeapon();
		else
			return SearchWeapon(weapon->GetNextWeapon(), num - 1);
	}
	else
		return NULL;
}

void Shop::ClearWeapon()
{
	for (int i = 0; i < WPNUM; i++)
	{
		if (m_Weapon[i] != NULL)
		{
			ClearWeapon(m_Weapon[i]);
			delete m_Weapon[i];
			m_Weapon[i] = NULL;
		}
	}
}

void Shop::ClearWeapon(Weapon* weapon)
{
	if (weapon->GetNextWeapon() != NULL)
	{
		ClearWeapon(weapon->GetNextWeapon());
		weapon->Clear();
	}
}

Shop::~Shop()
{
	ClearWeapon();
}
