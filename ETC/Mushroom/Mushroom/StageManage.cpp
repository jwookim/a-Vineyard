#include "StageManage.h"

StageManage::StageManage(int stage)
{
	m_istage = stage;

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
		}
	}

	m_Player = new Teemo;
}

void StageManage::TimeProgress()
{
	while (1)
	{
		StatusCheck();

		MoveCheck();

		SwitchCheck();

		TrapCheck();


	}
}

void StageManage::MoveCheck()
{
	Position dest;
	Enemy* curNode;

	if (m_Player->MoveCheck())
	{
		dest = m_Player->GetNextPos();

		if (m_Block.Search(dest) != NULL)
			m_Player->MoveCancle();
		else
		{
			if (m_Enemy.First())
			{
				if (m_Enemy.ViewNode()->GetPosition() == dest)
					m_Player->MoveCancle();
				else
				{
					while (m_Enemy.Next())
					{
						if (m_Enemy.ViewNode()->GetPosition() == dest)
						{
							m_Player->MoveCancle();
							break;
						}
					}
				}
			}
		}

		Restoration(m_Player);
		m_Player->Move();
	}

	if (m_Enemy.First())
	{
		while (1)
		{
			curNode = m_Enemy.ViewNode();
			if (curNode->MoveCheck())
			{
				dest = curNode->GetNextPos();

				if (m_Block.Search(dest) != NULL)
					curNode->MoveCancle();
				else
				{
					if (m_Player->GetPosition() == dest)
						curNode->MoveCancle();
					else
					{
						m_Enemy.First();
						if (m_Enemy.ViewNode()->GetPosition() == dest && m_Enemy.ViewNode() != curNode)
							curNode->MoveCancle();
						else
						{
							while (m_Enemy.Next())
							{
								if (m_Enemy.ViewNode() == curNode)
									continue;
								if (m_Enemy.ViewNode()->GetPosition() == dest)
								{
									m_Player->MoveCancle();
									break;
								}
							}
						}

						m_Enemy.First();
						while (m_Enemy.ViewNode() != curNode)
							m_Enemy.Next();
					}
				}

				Restoration(curNode);
				curNode->Move();
			}

			if (m_Enemy.Next() == 0)
				break;
		}
	}

	if (m_Projectile.First())
	{
		if (m_Projectile.ViewNode()->MoveCheck())
		{
			Restoration(m_Projectile.ViewNode());
			m_Projectile.ViewNode()->Move();
		}
		while (m_Projectile.Next())
		{
			if (m_Projectile.ViewNode()->MoveCheck())
			{
				Restoration(m_Projectile.ViewNode());
				m_Projectile.ViewNode()->Move();
			}
		}
	}
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