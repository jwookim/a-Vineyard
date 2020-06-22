#include "StageManage.h"

StageManage::StageManage()
{
	m_istage = 1;

	char Buff[30];

	sprintf_s(Buff, "mode con cols=%d lines=%d", WIDTH, HEIGHT);

	system(Buff);

	for (int y = 0; y < HEIGHT - 1; y++)
	{
		for (int x = 0; x < WIDTH / 2 - 1; x++)
		{
			if (x == 0 || y == 0 || x == WIDTH / 2 - 2 || y == HEIGHT - 2)
			{
				Block* newBlock = new Block({ x, y });
				m_Block.Insert(newBlock);
			}

			else if (x == 1 || y == 1 || x == WIDTH / 2 - 3 || y == HEIGHT - 3)
			{
				Bush* newBush = new Bush({ x, y });
				m_Bush.Insert(newBush);
			}
		}
	}

	m_Player = new Teemo({ WIDTH / 4, HEIGHT / 2 });

	m_Enemy.push_back(new Garen({ WIDTH / 4, HEIGHT / 4 }));
}

END_TYPE StageManage::TimeProgress()
{
	END_TYPE check;
	while (1)
	{
		StatusCheck();

		MoveCheck();

		AttackCheck();

		SwitchCheck();

		TrapCheck();

		HitCheck();

		check = EndCheck();

		if (check != END_CONTINUE)
			return check;
	}
}

void StageManage::MoveCheck()
{
	Position dest;

	list<Enemy*>::iterator Eiter;
	list<Enemy*>::iterator Eiter2;
	list<Projectile*>::iterator Piter;
	if (m_Player->MoveCheck())
	{
		dest = m_Player->GetNextPos();

		if (m_Block.Search(dest) != NULL)
			m_Player->MoveCancle();
		else
		{
			if (!m_Enemy.empty())
			{
				for (Eiter = m_Enemy.begin(); Eiter != m_Enemy.end(); ++Eiter)
				{
					if ((*Eiter)->GetPosition() == dest)
					{
						m_Player->MoveCancle();
						break;
					}
				}

			}
		}

		Restoration(m_Player);
		m_Player->Move();
	}
	if (!m_Enemy.empty())
	{
		for (Eiter = m_Enemy.begin(); Eiter != m_Enemy.end(); ++Eiter)
		{
			if ((*Eiter)->MoveCheck())
			{
				dest = (*Eiter)->GetNextPos();

				if (m_Block.Search(dest) != NULL)
					(*Eiter)->MoveCancle();
				else
				{
					if (m_Player->GetPosition() == dest)
						(*Eiter)->MoveCancle();
					else
					{
						for (Eiter2 = m_Enemy.begin(); Eiter2 != m_Enemy.end(); ++Eiter2)
						{
							if (Eiter == Eiter2)
								continue;

							if ((*Eiter)->GetPosition() == dest)
							{
								(*Eiter)->MoveCancle();
								break;
							}
						}
					}
				}

				Restoration((*Eiter));
				(*Eiter)->Move();
			}
		}
	}


	if (!m_Projectile.empty())
	{
		for (Piter = m_Projectile.begin(); Piter != m_Projectile.end(); ++Piter)
		{
			if ((*Piter)->MoveCheck())
			{
				Restoration(*Piter);
				(*Piter)->Move();
			}
		}
	}
}

void StageManage::AttackCheck()
{
	Projectile* tmp = NULL;
	if ((tmp = m_Player->AttackCheck()) != NULL)
		m_Projectile.push_back(tmp);
	tmp = NULL;
}

void StageManage::SwitchCheck()
{

}

void StageManage::TrapCheck()
{

}

void StageManage::StatusCheck()
{

}

void StageManage::HitCheck()
{
	list<Projectile*>::iterator Piter;
	list<Enemy*>::iterator Eiter;
	Object* block;

	for (Piter = m_Projectile.begin(); Piter != m_Projectile.end();)
	{
		block = m_Block.Search((*Piter)->GetPosition());
		
		if (block != NULL)
		{
			block->Draw();
			delete *Piter;
			Piter = m_Projectile.erase(Piter);
		}

		else if (m_Player->GetPosition() == (*Piter)->GetPosition())
		{
			if ((Character*)m_Player != (Character*)((*Piter)->GetCaster()))
			{
				((Character*)((*Piter)->GetCaster()))->Attack(m_Player);
				m_Player->Draw();
				delete *Piter;
				Piter = m_Projectile.erase(Piter);
			}
			else
				Piter++;
		}

		else
		{
			int check = 0;
			for (Eiter = m_Enemy.begin(); Eiter != m_Enemy.end(); ++Eiter)
			{
				if ((*Eiter)->GetPosition() == (*Piter)->GetPosition())
				{
					check = 1;

					if ((Character*)(*Eiter) != (Character*)((*Piter)->GetCaster()))
					{
						if (((Character*)(*Eiter))->GetAlive())
						{
							((Character*)((*Piter)->GetCaster()))->Attack(*Eiter);
							(*Eiter)->Draw();
						}
						else
						{
							(*Eiter)->Erase();
							delete *Eiter;
							m_Enemy.erase(Eiter);
						}

						delete *Piter;
						Piter = m_Projectile.erase(Piter);
						break;
					}

					Piter++;
					break;
				}
			}

			if (check == 0)
				Piter++;
		}

	}
}


END_TYPE StageManage::EndCheck()
{
	if (!m_Player->GetAlive())
		return END_GAME_OVER;
	if (m_Player->GetPosition() == m_Goal)
		return END_CLEAR;
	return END_CONTINUE;
}

void StageManage::Restoration(Object* target)
{

	Position tpos = target->GetPosition();
	Object* tmp;
	if ((tmp = m_Block.Search(tpos)) != NULL)
	{
		tmp->Draw();
		return;
	}

	if ((tmp = m_Bush.Search(tpos)) != NULL)
	{
		tmp->Draw();
		return;
	}

	if ((tmp = m_Switch.Search(tpos)) != NULL)
	{
		tmp->Draw();
		return;
	}

	if ((tmp = m_Trap.Search(tpos)) != NULL)
	{
		tmp->Draw();
		return;
	}

	target->Erase();

}

StageManage::~StageManage()
{

}