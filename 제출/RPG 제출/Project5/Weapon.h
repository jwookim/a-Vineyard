#pragma once
#include<iostream>
#include<string>
#include<list>
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
	Weapon* m_pParent;
	string m_strName;
	string m_strType;
	int m_iAtk;
	int m_iPrice;
	MapDraw DrawManager;
public:
	virtual STATUS Attack() = 0;
	void SetName(string name);
	void SetType(string Type);
	void SetAtk(int atk);
	void SetPrice(int price);
	void SetParent(Weapon* weapon);
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
	inline Weapon* GetParent()
	{
		return m_pParent;
	}
	void Clear();
	void ShowInfo_Shop(int line);
	void ShowInfo(int line);
	virtual void AddWeapon(Weapon* wp) {};
	virtual void RemoveWeapon(Weapon* wp) {};
	Weapon();
	~Weapon();
};

class WpList : public Weapon
{
protected:
	list<Weapon*> m_Weapon;
public:
	void AddWeapon(Weapon* wp);
	void RemoveWeapon(Weapon* wp);
};