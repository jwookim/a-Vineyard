#include "Character.h"



Character::Character()
{
	m_Weapon = NULL;
	m_Status = STATUS_NORMAL;
	m_iStatusDur = 0;
}

void Character::Attack(Character* enemy)
{
	STATUS tmp;
	enemy->Dmg(m_iAtk);
	if (m_Weapon != NULL)
	{
		enemy->Dmg(m_Weapon->GetAtk());
		tmp = m_Weapon->Attack();
		switch (tmp)
		{
		case STATUS_NORMAL:
			break;
		case STATUS_CRIT:
			enemy->Dmg(m_iAtk + m_Weapon->GetAtk());
			break;
		default:
			enemy->SetStatus(tmp);
			break;
		}
	}
}

int Character::Dmg(int Atk)
{
	m_iHealth -= Atk;

	if (m_iHealth < 0)
		m_iHealth = 0;

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
	if (m_Status != STATUS_NORMAL)
	{
		DrawManager.TextDraw("상태 이상 : ", WIDTH / 2, line++);
		switch (m_Status)
		{
		case STATUS_STUN:
			cout << "기절";
			break;
		case STATUS_BLEEDING:
			cout << "출혈";
			break;
		case STATUS_POISON:
			cout << "중독";
			break;
		case STATUS_SHOCK:
			cout << "감전";
			break;
		}
	}
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

void Character::EquipWeapon(Weapon* weapon)
{
	m_Weapon = weapon;
}

void Character::SetStatus(STATUS stat)
{
	m_Status = stat;
	m_iStatusDur = 2;
}

int Character::Bleeding()
{
	int dmg = 0;
	if (m_Status == STATUS_BLEEDING)
	{
		dmg = m_iMaxHealth / 10;
		if (m_iHealth - dmg <= 0)
			dmg -= (dmg - m_iHealth) + 1;

		Dmg(dmg);
	}
	return dmg;
}

void Character::BuyItem(Weapon* weapon)
{
	if (weapon !=NULL && m_iGold >= weapon->GetPrice())
	{
		m_iGold -= weapon->GetPrice();
		m_Weapon = weapon;
	}
}

void Character::DurationCheck()
{
	if (m_iStatusDur > 0)
	{
		if (--m_iStatusDur <= 0)
			Cure();
	}
}

void Character::Cure()
{
	m_Status = STATUS_NORMAL;
	m_iStatusDur = 0;
}

void Character::Recovery()
{
	m_iHealth = m_iMaxHealth;
	Cure();
}

void Character::Win(Character* enemy)
{
	DrawManager.ClearWindow();

	RED
		DrawManager.DrawMidText(m_strName + " 승리!!", WIDTH, HEIGHT / 4);

	DrawManager.DrawMidText(m_strName + "가 경험치 " + to_string(enemy->GetGetExp()) + "를 얻었습니다.", WIDTH, HEIGHT / 3);

	m_iGetExp += enemy->GetGetExp();
	m_iExp += enemy->GetGetExp();
	m_iGold += enemy->GetGold();
	ORIGINAL

		getch();

	while (m_iExp >= m_iMaxExp)
	{
		LevelUp();
	}
}

void Character::LevelUp()
{
	DrawManager.ClearWindow();
	int Benefit;
	m_iExp -= m_iMaxExp;
	m_iGetExp -= m_iMaxExp;

	PUPPLE
		DrawManager.DrawMidText(m_strName + " 레벨 업!!", WIDTH, HEIGHT / 2 - 2);
	m_iLevel++;
	m_iMaxExp += 3;

	Benefit = rand() % 10 + 1;
	m_iAtk += Benefit;
	DrawManager.DrawMidText("공격력 " + to_string(Benefit) + " 증가!!", WIDTH, HEIGHT / 2);

	Benefit = rand() % 10 + 1;
	m_iMaxHealth += Benefit;
	DrawManager.DrawMidText("생명력 " + to_string(Benefit) + " 증가!!", WIDTH, HEIGHT / 2 + 2);

	Recovery();
	ORIGINAL

		getch();
}

Character::~Character()
{
}
