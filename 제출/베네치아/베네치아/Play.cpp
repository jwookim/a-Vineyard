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
	char skip = NULL;

	DrawMap();
	DrawAnswer();
	DrawManager.DrawMidText("Skip : s", WIDTH, 26);
	getch();

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

Play::~Play()
{
}
