#include "Play.h"



Play::Play()
{
	Init();
}

void Play::Story()
{
	ifstream load;
	int lineMax;
	int line = 0;
	int time;
	char skip = NULL;

	load.open("베네치아_스토리.txt");

	if (load.is_open())
	{
		load >> lineMax;


		for (int i = 0; i < lineMax && skip != 's'; i++)
		{
			system("cls");
			time = clock();
			if (line >= LINE)
			{
				for (int j = 0; j < LINE - 1; j++)
					m_strStory[j] = m_strStory[j + 1];
				line--;
			}

			getline(load, m_strStory[line]);

			for (int j = 0; j < LINE; j++)
			{
				/*Draw*/
				cout << m_strStory[j] << endl;
			}
			

			if (line < LINE)
				line++;

			while (clock() - time < 1000)
			{
				if (kbhit())
				{
					skip = getch();

					if (skip == 's')
						break;
				}
			}
		}
	}
}

void Play::Game()
{
	int time = clock();
	char input;
	int totalScore = 0;
	int Delay = DELAY;

	while (m_iLife > 0)
	{

		if (clock() - time >= DelayCheck(Delay))
		{
			AddWord();
			m_iLife -= DropWord();

			time = clock();
		}

		if (kbhit() && !m_bStun)
		{
			input = getch();

			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'A'))
				m_strInput += input;
			else if (m_strInput != "")
			{
				if (input == 8)
					m_strInput[m_strInput.length() - 1] = NULL;
				else if (input == 13) // ENTER
					WordCheck(CheckWord(m_strInput));
			}
		}

		EffectCheck();

		if (m_bStun && clock() - m_iStunTime >= STUN)
		{
			m_bStun = false;
		}
		if (m_iScore >= SCOREMAX - ((m_iStage - 1) * LVSCORE))
		{
			totalScore += m_iScore;
			m_iScore = 0;
			m_iStage++;
		}
	}
}

void Play::Goal(int len)
{
	m_iScore += len * SCORE;
}

void Play::WordCheck(EFFECT check)
{
	if (check != EFFECT_NULL)
	{
		switch (check)
		{
		case EFFECT_FAST:
		case EFFECT_SLOW:
		case EFFECT_PAUSE:
		case EFFECT_HIDE:
			m_Effect = check;
			break;
		case EFFECT_CLEAR:
			Goal(Clear());
			break;
		}
		Goal(m_strInput.length());
	}
	else
	{
		m_bStun = true;
		m_iStunTime = clock();
	}

	m_strInput = "";
}

int Play::DelayCheck(int delay)
{
	switch (m_Effect)
	{
	case EFFECT_FAST:
		delay /= 2;
		break;
	case EFFECT_SLOW:
		delay *= 2;
		break;
	case EFFECT_PAUSE:
		delay *= 100;
		break;
	}
	return delay;
}

void Play::EffectCheck()
{
	if (m_Effect != EFFECT_NORMAL)
	{
		switch (m_Effect)
		{
		case EFFECT_FAST:
		case EFFECT_SLOW:
		case EFFECT_PAUSE:
			if (clock() - m_iEffectTime >= 3000)
				m_Effect = EFFECT_NORMAL;
			break;
		case EFFECT_HIDE:
			if (clock() - m_iEffectTime >= 1500)
				m_Effect = EFFECT_NORMAL;
			break;
		}
	}
}

void Play::Init()
{
	m_strName = "? ? ?";
	m_iScore = 0;
	m_iLife = LIFE;
	m_iStage = 1;
	m_bStun = false;
	m_Effect = EFFECT_NORMAL;


	for (int i = 0; i < LINE; i++)
		m_strStory[i] = "";

	WordInit();
}

Play::~Play()
{
}
