#pragma once
#include<iostream>
#include<string>
#include"MapDraw.h"
#include"Bow.h"
#include"Dagger.h"
#include"Gun.h"
#include"Hammer.h"
#include"Sword.h"
#include"Wand.h"
using namespace std;


class Character
{
protected:
	string m_strName;
	int m_iLevel;
	int m_iAtk;
	int m_iHealth;
	int m_iMaxHealth;
	int m_iExp;
	int m_iMaxExp;
	int m_iGetExp;
	int m_iGold;
	int m_iStatusDur;
	STATUS m_Status;
	Weapon* m_Weapon;
	MapDraw DrawManager;
public:
	Character();
	void Attack(Character* enemy);
	int Dmg(int Atk);
	int ShowInfo(int line);
	void SetName(string name);
	void SetLevel(int level);
	void SetAtk(int atk);
	void SetHealth(int health);
	void SetMaxHealth(int health);
	void SetExp(int exp);
	void SetMaxExp(int exp);
	void SetGetExp(int exp);
	void SetGold(int gold);
	void EquipWeapon(Weapon* weapon);
	void SetStatus(STATUS stat);
	inline string GetName()
	{
		return m_strName;
	}
	inline int GetLevel()
	{
		return m_iLevel;
	}
	inline int GetAtk()
	{
		return m_iAtk;
	}
	inline int GetHealth()
	{
		return m_iHealth;
	}
	inline int GetMaxHealth()
	{
		return m_iMaxHealth;
	}
	inline int GetExp()
	{
		return m_iExp;
	}
	inline int GetMaxExp()
	{
		return m_iMaxExp;
	}
	inline int GetGetExp()
	{
		return m_iGetExp;
	}
	inline int GetGold()
	{
		return m_iGold;
	}
	inline Weapon* GetWeapon()
	{
		return m_Weapon;
	}
	inline STATUS GetStatus()
	{
		return m_Status;
	}
	int Bleeding();
	void DurationCheck();
	void Cure();
	void Recovery();
	void Win(Character* enemy);
	void LevelUp();
	void BuyItem(Weapon* weapon);
	~Character();
};

