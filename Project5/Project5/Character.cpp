#include "Character.h"



Character::Character()
{
	m_Weapon = NULL;
}

int Character::Dmg(int Atk)
{
	m_iHealth -= Atk;

	return m_iHealth;
}

int Character::ShowInfo(int line)
{
	DrawManager.DrawMidText("======" + m_strName + "(" + to_string(m_iLevel) + "Lv)======", WIDTH, line++);
	DrawManager.TextDraw("공격력 = " + to_string(m_iAtk) + "	생명력 = " + to_string(m_iHealth) + "/" + to_string(m_iMaxHealth), WIDTH / 2, line++);
	DrawManager.TextDraw("경험치 = " + to_string(m_iExp) + "/" + to_string(m_iMaxExp) + "	GetExp : " + to_string(m_iGetExp), WIDTH / 2, line++);
	DrawManager.TextDraw("Gold = " + to_string(m_iGold), WIDTH / 2, line++);
	if (m_Weapon != NULL)
		m_Weapon->ShowInfo(line++);
	return line;
}

void Character::SetName(string name)
{
	m_strName = name;
}

void Character::SetLevel(int level)
{
	m_iLevel = level;
}

void Character::SetAtk(int atk)
{
	m_iAtk = atk;
}

void Character::SetHealth(int health)
{
	m_iHealth = health;
}

void Character::SetMaxHealth(int health)
{
	m_iMaxHealth = health;
}

void Character::SetExp(int exp)
{
	m_iExp = exp;
}

void Character::SetMaxExp(int exp)
{
	m_iMaxExp = exp;
}

void Character::SetGetExp(int exp)
{
	m_iGetExp = exp;
}

void Character::SetGold(int gold)
{
	m_iGold = gold;
}

void Character::BuyItem(Weapon* weapon)
{
	if (weapon !=NULL && m_iGold >= weapon->GetPrice())
	{
		m_iGold -= weapon->GetPrice();
		m_Weapon = weapon;
	}
}

Character::~Character()
{
}
