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

			else if (x == 1 || y == 1 || x == WIDTH / 2 - 3 || y == HEIGHT - 3)
			{
				Bush* newBush = new Bush({ x, y });
				m_Bush.Insert(newBush);
			}
		}
	}

	m_Player = new Teemo;
}

END_TYPE StageManage::TimeProgress()
{
	END_TYPE check;
	while (1)
	{
		StatusCheck();

		MoveCheck();

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

void StageManage::HitCheck()
{
	Projectile* tmp;
	if (m_Projectile.First())
	{
		tmp = m_Projectile.ViewNode();

		if (m_Player->GetPosition() == tmp->GetPosition())
		{
			if ((Character*)m_Player != (Character*)(tmp->GetCaster()))
			{
				((Character*)(tmp->GetCaster()))->Attack(m_Player);
				m_Player->Draw();
				delete m_Projectile.Remove();
			}
		}
		else
		{
			if (m_Enemy.First())
			{
				if (m_Enemy.ViewNode()->GetPosition() == tmp->GetPosition())
				{
					if ((Character*)m_Enemy.ViewNode() != (Character*)(tmp->GetCaster()))
					{
						((Character*)(tmp->GetCaster()))->Attack(m_Enemy.ViewNode());
						m_Enemy.ViewNode()->Draw();
						delete m_Projectile.Remove();
					}
				}
				while (m_Enemy.Next())
				{
					if (m_Enemy.ViewNode()->GetPosition() == tmp->GetPosition())
					{
						if ((Character*)m_Enemy.ViewNode() != (Character*)(tmp->GetCaster()))
						{
							((Character*)(tmp->GetCaster()))->Attack(m_Enemy.ViewNode());
							m_Enemy.ViewNode()->Draw();
							delete m_Projectile.Remove();
						}
					}
				}
			}
		}

		Object* block = m_Block.Search(tmp->GetPosition());

		if (block != NULL)
		{
			block->Draw();
			delete m_Projectile.Remove();
		}
		while (m_Projectile.Next())
		{
			tmp = m_Projectile.ViewNode();

			if (m_Player->GetPosition() == tmp->GetPosition())
			{
				if ((Character*)m_Player != (Character*)(tmp->GetCaster()))
				{
					((Character*)(tmp->GetCaster()))->Attack(m_Player);
					m_Player->Draw();
					delete m_Projectile.Remove();
				}
			}
			else
			{
				if (m_Enemy.First())
				{
					if (m_Enemy.ViewNode()->GetPosition() == tmp->GetPosition())
					{
						if ((Character*)m_Enemy.ViewNode() != (Character*)(tmp->GetCaster()))
						{
							((Character*)(tmp->GetCaster()))->Attack(m_Enemy.ViewNode());
							m_Enemy.ViewNode()->Draw();
							delete m_Projectile.Remove();
						}
					}
				}
				while (m_Enemy.Next())
				{
					if (m_Enemy.ViewNode()->GetPosition() == tmp->GetPosition())
					{
						if ((Character*)m_Enemy.ViewNode() != (Character*)(tmp->GetCaster()))
						{
							((Character*)(tmp->GetCaster()))->Attack(m_Enemy.ViewNode());
							m_Enemy.ViewNode()->Draw();
							delete m_Projectile.Remove();
						}
					}
				}
			}

			Object* block = m_Block.Search(tmp->GetPosition());

			if (block != NULL)
			{
				block->Draw();
				delete m_Projectile.Remove();
			}
		}
	}
}

END_TYPE StageManage::EndCheck()
{

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