#pragma once
#include "Mecro.h"
#include"Bow.h"
#include"Dagger.h"
#include"Gun.h"
#include"Hammer.h"
#include"Sword.h"
#include"Wand.h"

class Shop
{
private:
	Weapon* m_Weapon;
public:
	void addWeapon(Weapon* newweapon);
	void addWeapon(Weapon* newweapon, Weapon* check);
	void ClearWeapon();
	void ClearWeapon(Weapon* weapon);
	Shop();
	~Shop();
};

