#include "StageManage.h"

StageManage::StageManage(int stage)
{
	m_istage = stage;


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

		if (m_Block.Search(dest))
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

				if (m_Block.Search(dest))
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

				curNode->Move();
			}

			if (m_Enemy.Next() == 0)
				break;
		}
	}

	if (m_Projectile.First())
	{
		if (m_Projectile.ViewNode()->MoveCheck())
			m_Projectile.ViewNode()->Move();

		while (m_Projectile.Next())
		{
			if (m_Projectile.ViewNode()->MoveCheck())
				m_Projectile.ViewNode()->Move();
		}
	}
}

void StageManage::SwitchCheck()
{

}

void StageManage::TrapCheck()
{

}

StageManage::~StageManage()
{

}