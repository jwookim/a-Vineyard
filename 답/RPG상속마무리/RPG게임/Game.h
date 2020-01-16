#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Character.h"
#include"Shop.h"

class Game
{
private:
	MapDraw DrawManager;
	Character Character;
	Shop ShopManager;
public:
	Game();
	void MainPage(); 
	void MenuPage();
	void DongeonPage();
	void NewGame();
	void LoadGame();
	void DetailGame();
	void PInfo();
	void MInfo();
	void WeaponePage();
	~Game();
};

