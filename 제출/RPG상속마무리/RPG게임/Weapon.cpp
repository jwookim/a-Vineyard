#include "Weapon.h"



Weapon::Weapon()
{
	
}
void Weapon::Set(string _name, int _Pri, int _Att, WEAPONTYPE _Ty)
{
	m_strName = _name;
	m_iPrice = _Pri;
	m_iWeaponAttack = _Att;
	m_eType = _Ty;

}

Weapon::~Weapon()
{
}
