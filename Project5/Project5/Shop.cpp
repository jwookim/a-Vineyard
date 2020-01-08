#include "Shop.h"



Shop::Shop()
{
	for (int i = 0; i < WPNUM; i++)
		m_Weapon[i] = NULL;

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
		ClearWindow();

		DrawManager.DrawMidText("♧ ♣ S H O P ♣ ♧", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Dagger", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Gun", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Sword", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Wand", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Bow", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("Hammer", WIDTH, HEIGHT / 4 + (Margin * line++));
		DrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT / 4 + (Margin * line++));

		Select = DrawManager.MenuSelectCursor(7, 2, WIDTH / 2 - 3, HEIGHT / 4 + Margin);

		switch (Select)
		{
		case 1:

		case 2:

		case 3:

		case 4:

		case 5:

		case 6:
			break;
		}
	}
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

void Shop::ClearWindow()
{
	system("cls");
	BLUE
		DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL
}

Shop::~Shop()
{
	ClearWeapon();
}
