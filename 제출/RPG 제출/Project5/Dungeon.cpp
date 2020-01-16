#include "Dungeon.h"



Dungeon::Dungeon()
{
	m_strPick[BATTLE_NONE] = "";
	m_strPick[BATTLE_SCISSOR] = "가위";
	m_strPick[BATTLE_ROCK] = "바위";
	m_strPick[BATTLE_PAPER] = "보";
}

bool Dungeon::Menu(Character* player, Character Monster[], int MonsterNum)
{
	int Margin = 2;
	int Select = 0;
	int line;
	bool alive = true;
	while (Select != MonsterNum + 1 && alive == true)
	{
		line = 0;

		DrawManager.ClearWindow();

		DrawManager.DrawMidText("=====던전 입구=====", WIDTH, HEIGHT / 5);

		for (int i = 0; i < MonsterNum; i++)
		{
			DrawManager.DrawMidText(to_string(i + 1) + "층 던전 : [" + Monster[i].GetName() + "]", WIDTH, HEIGHT / 3 + (Margin*line++));
		}

		DrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT / 3 + (Margin*line++));

		Select = DrawManager.MenuSelectCursor(MonsterNum + 1, Margin, WIDTH / 4, HEIGHT / 3);

		if (Select != MonsterNum + 1)
			alive = Stage(player, &Monster[Select - 1]);
	}
	return alive;
}

bool Dungeon::Stage(Character* player, Character* Monster)
{
	int status = PLAY_BATTLE;
	DrawManager.ClearWindow();
	BattleInterface(player, Monster);
	while (status == PLAY_BATTLE)
	{
		status = Battle(player, Monster);

		BattleInterface(player, Monster);
	}

	getch();

	Monster->Recovery();

	switch (status)
	{
	case PLAY_P1WIN:
		player->Win(Monster);
		break;
	case PLAY_P2WIN:
		Monster->Win(player);
		DrawManager.ClearWindow();
		RED
			DrawManager.DrawMidText("Game Over", WIDTH, HEIGHT / 2);
		ORIGINAL
			getch();
		return false;
	}
	getch();
	return true;
}

PLAY Dungeon::Battle(Character* player, Character* Monster)
{
	switch (Monster->GetStatus())
	{
	case STATUS_STUN:
		m_MonsterPick = BATTLE_NONE;
		DrawManager.DrawMidText("기절함!", WIDTH, HEIGHT / 2 + 6);
		break;
	case STATUS_SHOCK:
		DrawManager.DrawMidText("마비됨!", WIDTH, HEIGHT / 2 + 6);
		break;
	case STATUS_BLEEDING:
		DrawManager.DrawMidText("출혈 데미지 " + to_string(Monster->Bleeding()) + "발생!", WIDTH, HEIGHT / 2 + 6);
		Shuffle();
		break;
	case STATUS_POISON:
		DrawManager.DrawMidText("느려짐!", WIDTH, HEIGHT / 2 + 6);
		Shuffle();
		DrawManager.DrawMidText("간파됨 - " + m_strPick[m_MonsterPick], WIDTH, HEIGHT / 2 + 7);
		break;
	case STATUS_NORMAL:
		Shuffle();
		break;
	}

	Monster->DurationCheck();

	int Select = BATTLE_NONE;
	while (!(Select == '1' || Select == '2' || Select == '3'))
		Select = getch();

	switch (Select)
	{
	case '1':
		Select = BATTLE_SCISSOR;
		break;
	case '2':
		Select = BATTLE_ROCK;
		break;
	case '3':
		Select = BATTLE_PAPER;
		break;
	}

	DrawManager.ClearWindow();

	YELLOW
		DrawManager.DrawMidText(m_strPick[Select], WIDTH, HEIGHT / 2 - 3);
	ORIGINAL
		DrawManager.DrawMidText(m_strPick[m_MonsterPick], WIDTH, HEIGHT / 2 + 4);

	if (m_MonsterPick == Select)
	{
		Result(PLAY_BATTLE);
	}
	else
	{
		switch (Select)
		{
		case BATTLE_SCISSOR:
			if (m_MonsterPick == BATTLE_ROCK)
			{
				Monster->Attack(player);
				Result(PLAY_P2WIN);

				if (player->GetHealth() <= 0)
					return PLAY_P2WIN;
			}
			else
			{
				player->Attack(Monster);
				Result(PLAY_P1WIN);

				if (Monster->GetHealth() <= 0)
					return PLAY_P1WIN;
			}
			break;
		case BATTLE_ROCK:
			if (m_MonsterPick == BATTLE_PAPER)
			{
				Monster->Attack(player);
				Result(PLAY_P2WIN);

				if (player->GetHealth() <= 0)
					return PLAY_P2WIN;
			}
			else
			{
				player->Attack(Monster);
				Result(PLAY_P1WIN);

				if (Monster->GetHealth() <= 0)
					return PLAY_P1WIN;
			}
			break;
		case BATTLE_PAPER:
			if (m_MonsterPick == BATTLE_SCISSOR)
			{
				Monster->Attack(player);
				Result(PLAY_P2WIN);

				if (player->GetHealth() <= 0)
					return PLAY_P2WIN;
			}
			else
			{
				player->Attack(Monster);
				Result(PLAY_P1WIN);

				if (Monster->GetHealth() <= 0)
					return PLAY_P1WIN;
			}
			break;
		}

	}
	return PLAY_BATTLE;
}

void Dungeon::BattleInterface(Character* player, Character* Monster)
{
	YELLOW
		player->ShowInfo(HEIGHT / 7);
	DrawManager.TextDraw("가위 :1	바위 : 2	보 : 3", WIDTH / 2, HEIGHT / 3);
	ORIGINAL

		Monster->ShowInfo(HEIGHT - 7);
	RED
		DrawManager.DrawMidText("-------------------------- vs --------------------------", WIDTH, HEIGHT / 2);
	ORIGINAL
}

void Dungeon::Result(PLAY result)
{
	switch (result)
	{
	case PLAY_BATTLE:
		RED
			DrawManager.DrawMidText("Draw", WIDTH, HEIGHT / 2 - 2);
		DrawManager.DrawMidText("Draw", WIDTH, HEIGHT / 2 + 3);
		ORIGINAL
		break;
	case PLAY_P1WIN:
		RED
			DrawManager.DrawMidText("Win", WIDTH, HEIGHT / 2 - 2);
		DrawManager.DrawMidText("Lose", WIDTH, HEIGHT / 2 + 3);
		ORIGINAL
		break;
	case PLAY_P2WIN:
		RED
			DrawManager.DrawMidText("Lose", WIDTH, HEIGHT / 2 - 2);
		DrawManager.DrawMidText("Win", WIDTH, HEIGHT / 2 + 3);
		ORIGINAL
		break;
	}
}

void Dungeon::Shuffle()
{
	m_MonsterPick = (BATTLE)(rand() % 3 + 1);
}

Dungeon::~Dungeon()
{
}
