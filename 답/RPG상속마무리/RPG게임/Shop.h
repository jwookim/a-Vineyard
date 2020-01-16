#pragma once
#include"Dagger.h"
#include"Bow.h"
#include"Wand.h"
#include"Sword.h"
#include"Hammer.h"
#include"Gun.h"
#include"MapDraw.h"
class Shop
{
private:
	Dagger Daggers[6];
	Bow Bows[5];
	Wand Wands[5];
	Sword Swords[5];
	Hammer Hammers[5];
	Gun Guns[4];
	MapDraw DrawManager;
	int m_iSelectWAttack;
	int m_iSelectWGold;
	bool m_bFlag;
	BUYTYPE b;
	int m_iPlusAttack;
public:
	Shop();
	void SetWeapons();
	void ShowShop();
	void SetDaggers();
	void ShowDaggers();
	void SetBows();
	void ShowBows();
	void SetWands();
	void ShowWands();
	void SetSwords();
	void ShowSwords();
	void SetHammers();
	void ShowHammers();
	void SetGuns();
	void ShowGuns();
	void Random();
	inline int GetSelectAttack() { return m_iSelectWAttack; }
	inline int GetSelectGold() { return m_iSelectWGold; }
	inline bool GetFlag() { return m_bFlag; }
	inline int GetPlusAttack() { return m_iPlusAttack; }

	~Shop();
};

