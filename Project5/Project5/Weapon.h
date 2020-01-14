#pragma once
#include<iostream>
#include<string>
#include"MapDraw.h"
using namespace std;

enum STATUS
{
	STATUS_NORMAL,
	STATUS_STUN,
	STATUS_BLEEDING,
	STATUS_POISON,
	STATUS_SHOCK,
	STATUS_CRIT
};

class Weapon
{
protected:
	string m_strName;
	string m_strType;
	int m_iAtk;
	int m_iPrice;
	MapDraw DrawManager;
	Weapon* m_pNextWeapon;
public:
	virtual STATUS Attack() = 0;
	void SetName(string name);
	void SetType(string Type);
	void SetAtk(int atk);
	void SetPrice(int price);
	void SetNextWeapon(Weapon* weapon);
	inline string GetName()
	{
		return m_strName;
	}
	inline string GetType()
	{
		return m_strType;
	}
	inline int GetAtk()
	{
		return m_iAtk;
	}
	inline int GetPrice()
	{
		return m_iPrice;
	}
	inline Weapon* GetNextWeapon()
	{
		return m_pNextWeapon;
	}
	void Clear();
	void ShowInfo_Shop(int line);
	void ShowInfo(int line);
	Weapon();
	~Weapon();
};

