#pragma once
#include "Mecro.h"
#include"MapDraw.h"
#include"Bow.h"
#include"Dagger.h"
#include"Gun.h"
#include"Hammer.h"
#include"Sword.h"
#include"Wand.h"
#include"Character.h"

#define WPNUM 6

enum WEAPON
{
	WEAPON_DAGGER,
	WEAPON_GUN,
	WEAPON_SWORD,
	WEAPON_WAND,
	WEAPON_BOW,
	WEAPON_HAMMER
};

class Shop
{
private:
	Weapon* m_Weapon[WPNUM];
	MapDraw DrawManager;
public:
	void Menu(Character* player);
	void ShowList(Character* player, WEAPON type);
	void addWeapon(Weapon* newweapon, WEAPON type);
	void addWeapon(Weapon* newweapon, Weapon* check);
	void ShowWeapon(WEAPON type, int startNum, int endNum);
	Weapon* SearchWeapon(WEAPON type, int num);
	Weapon* SearchWeapon(Weapon* weapon);
	void ClearWeapon();
	void ClearWeapon(Weapon* weapon);
	void ClearWindow();
	Shop();
	~Shop();
};

