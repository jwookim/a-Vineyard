#pragma once
#include"Mecro.h"
#include"MapDraw.h"

class Weapon
{
protected:
	string m_strName;
	int m_iPrice;
	int m_iWeaponAttack;
	WEAPONTYPE m_eType;
	MapDraw DrawM;
	int m_iRandom;
public:
	Weapon();
	virtual void Draw(int h) = 0; // 순수가상함수
	virtual void Show() = 0;
	void Set(string _name, int _Pri, int _Att, WEAPONTYPE _Ty);
	inline int GetPrice() { return m_iPrice; }
	inline int GetAttack() { return m_iWeaponAttack; }
	inline int GetRandom() { return m_iRandom; }
	~Weapon();
};



















