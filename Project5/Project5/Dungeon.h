#pragma once
#include"MapDraw.h"
#include"Character.h"

enum PLAY
{
	PLAY_BATTLE,
	PLAY_P1WIN,
	PLAY_P2WIN
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_SCISSOR,
	BATTLE_ROCK,
	BATTLE_PAPER
};

class Dungeon
{
private:
	BATTLE m_MonsterPick;
	string m_strPick[4];
	MapDraw DrawManager;
public:
	void Menu(Character* player, Character Monster[], int MonsterNum);
	void Stage(Character* player, Character* Monster);
	PLAY Battle(Character* player, Character* Monster);
	void BattleInterface(Character* player, Character* Monster);
	void Result(PLAY result);
	void Shuffle();
	Dungeon();
	~Dungeon();
};

