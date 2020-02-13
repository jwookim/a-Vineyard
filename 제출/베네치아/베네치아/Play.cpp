#include "Play.h"



Play::Play()
{
	Init();
	char Buff[50];
	sprintf(Buff, "mode con: cols=%d lines=%d", WIDTH * 2, HEIGHT + 4);
	system(Buff);
}

void Play::Menu()
{
	int Select = 0;
	while (Select != 3)
	{
		DrawMap();
		ShowAll();

		BLUE
			DrawManager.DrawMidText("☆ ★ 베네치아 ★ ☆", WIDTH, HEIGHT / 5);
		DrawManager.DrawMidText("1. Game Start", WIDTH, HEIGHT / 3 + 3);
		DrawManager.DrawMidText("2. Rank", WIDTH, HEIGHT / 3 + 6);
		DrawManager.DrawMidText("3. Exit", WIDTH, HEIGHT / 3 + 9);

		Select = DrawManager.MenuSelectCursor(3, 3, WIDTH / 2 - 5, HEIGHT / 3 + 3);

		switch (Select)
		{
		case 1:
			Story();
			SetName();
			Game();
			break;
		case 2:
			break;
		}
	}
}

void Play::Story()
{
	ifstream load;
	int lineMax;
	int line = 0;
	int time;
	string tmp;
	char skip = NULL;

	DrawMap();
	DrawAnswer();
	BLUE
		DrawManager.DrawMidText("Skip : s", WIDTH, 26);

	load.open("베네치아_스토리.txt");

	if (load.is_open())
	{
		load >> lineMax;


		for (int i = 0; i < lineMax && skip != 's'; i++)
		{
			time = clock();

			for (int j = 0; j < LINE; j++)
			{
				if (m_strStory[j] != "")
				{
					tmp = "";
					for (int k = 0; k < m_strStory[j].length(); k++)
						tmp += "  ";
					DrawManager.DrawMidText(tmp, WIDTH, HEIGHT / 5 + j);
				}
			}

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
				DrawManager.DrawMidText(m_strStory[j], WIDTH, HEIGHT / 5 + j);
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
	ORIGINAL
}

void Play::SetName()
{
	DrawMap();
	BLUE
		DrawManager.DrawMidText("이름 입력", WIDTH, HEIGHT / 2);
	ORIGINAL
		DrawAnswer();



	while (!InputWord())
	{
	}

	m_strName = m_strInput;

	m_strInput = "";

	ShowName();
}

void Play::Game()
{
	DrawMap();
	DrawAnswer();

	int time = clock();
	int totalScore = 0;
	int Delay = DELAY;

	while (m_iLife > 0)
	{

		if (clock() - time >= DelayCheck(Delay))
		{
			m_iLife -= DropWord();
			AddWord();

			time = clock();

			ShowLife();
			DrawAnswer();
		}

		if (!m_bStun)
		{
			if (InputWord())
				WordCheck(CheckWord(m_strInput));
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
		ShowScore();
	}
	else
	{
		EraseAnswer();
		m_bStun = true;
		m_iStunTime = clock();

		RED
			DrawManager.DrawMidText("Failed Compare!!", WIDTH, 26);
		ORIGINAL
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

bool Play::InputWord()
{
	BLUE
		if (kbhit())
		{
			int input = getch();

			if (((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) && m_strInput.length() < 20)
			{
				m_strInput += input;

				EraseAnswer();
				DrawManager.DrawMidText(m_strInput, WIDTH, 26);
			}
			else if (m_strInput != "")
			{
				if (input == 8)
				{
					m_strInput.pop_back();

					EraseAnswer();
					DrawManager.DrawMidText(m_strInput, WIDTH, 26);
				}
				else if (input == 13) // ENTER
				{
					ORIGINAL
						return true;
				}
			}
		}
	ORIGINAL
		return false;
}

void Play::DrawMap()
{
	BLUE_GREEN
		DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL
}

void Play::DrawAnswer()
{
	BLUE
		DrawManager.BoxDraw(WIDTH , 24, 20, 5);
	ORIGINAL
		if (!m_bStun)
			DrawManager.DrawMidText(m_strInput, WIDTH, 26);
		else
		{
			RED
				DrawManager.DrawMidText("Failed Compare!!", WIDTH, 26);
			ORIGINAL
		}
}


void Play::ShowAll()
{
	ShowLife();
	ShowScore();
	ShowName();
}

void Play::ShowLife()
{
	RED
		EraseLife();
	string life;
	for (int i = 0; i < m_iLife; i++)
		life += "♥";
	DrawManager.TextDraw("Life : " + life, 1, HEIGHT + 1);
}

void Play::ShowScore()
{
	RED
		EraseScore();
	DrawManager.DrawMidText("Score : " + to_string(m_iScore), WIDTH, HEIGHT + 1);
}

void Play::ShowName()
{
	RED
		EraseName();

	DrawManager.TextDraw("Name : " + m_strName, 112, HEIGHT + 1);
}

void Play::EraseLife()
{
	RED
		string erase;
	for (int i = 0; i < 12; i++)
		erase += "  ";
	DrawManager.TextDraw(erase, 1, HEIGHT + 1);
}

void Play::EraseScore()
{
	RED
		string erase;
	for (int i = 0; i < 12; i++)
		erase += "  ";
	DrawManager.DrawMidText(erase, WIDTH, HEIGHT + 1);
}

void Play::EraseName()
{
	RED
		string erase;
	for (int i = 0; i < 9; i++)
		erase += "  ";
	DrawManager.TextDraw(erase, 112, HEIGHT + 1);
}

void Play::EraseAnswer()
{
	DrawManager.DrawMidText("                                    ", WIDTH, 26);
}

Play::~Play()
{
}
