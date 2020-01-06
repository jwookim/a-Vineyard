#include "Shop.h"



Shop::Shop()
{
	m_Weapon = NULL;

	ifstream load;
	string tmp;
	int tmpNum;

	Weapon* weapon;
	load.open("WeaponList.txt");

	while (!load.eof())
	{
		load >> tmp;
		
		if (tmp == "Bow")
		{
			weapon = new Bow;
		}
		else if (tmp == "Dagger")
		{
			weapon = new Dagger;
		}
		else if (tmp == "Gun")
		{
			weapon = new Gun;
		}
		else if (tmp == "Sword")
		{
			weapon = new Sword;
		}
		else if (tmp == "Wand")
		{
			weapon = new Wand;
		}
		else if (tmp == "Hammer")
		{
			weapon = new Hammer;
		}

		addWeapon(weapon);

		load >> tmp;
		weapon->SetName(tmp);

		load >> tmpNum;
		weapon->SetAtk(tmpNum);

		load >> tmpNum;
		weapon->SetPrice(tmpNum);
	}

	load.close();
}


void Shop::addWeapon(Weapon* newWeapon)
{
	if(m_Weapon != NULL)
		addWeapon(newWeapon, m_Weapon->GetNextWeapon());
	else
		m_Weapon->SetNextWeapon(newWeapon);
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
	if (m_Weapon != NULL)
	{
		ClearWeapon(m_Weapon);
		delete m_Weapon;
		m_Weapon = NULL;
	}
}

void Shop::ClearWeapon(Weapon* weapon)
{
	if (weapon->GetNextWeapon() != NULL)
	{
		ClearWeapon(m_Weapon);
		weapon->Clear();
	}
}

Shop::~Shop()
{
	ClearWeapon();
}
