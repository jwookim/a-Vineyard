#include "State.h"

bool State::TimeCheck()
{
	if (clock() >= m_iStartTime + (m_iDuration * SECOND))
		return false;
	return true;
}