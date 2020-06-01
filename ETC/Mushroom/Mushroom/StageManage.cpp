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
	Position tmp;
	if (m_Player->MoveCheck())
	{
		tmp = m_Player->GetNextPos();

		if (m_Block.Search(tmp))
			m_Player->MoveCancle();
		else
		{
			m_Enemy.First();
			if (m_Enemy.ViewNode()->GetPosition() == tmp)
				m_Player->MoveCancle();
			else
			{
				while (m_Enemy.Next())
				{
					if (m_Enemy.ViewNode()->GetPosition() == tmp)
					{
						m_Player->MoveCancle();
						break;
					}
				}
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

StageManage::~StageManage()
{

}