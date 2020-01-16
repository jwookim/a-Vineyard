#include "Game.h"

Game::Game()
{

}
 
void Game::MainPage() // WHEN START GAME
{
	int iSelect;
	bool bState = false;
	while (!bState)
	{
		DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
		DrawManager.DrawMidText("★★ TEXT RPG GAME ★★", WIDTH, HEIGHT * 0.3);
		DrawManager.DrawMidText("1. New Game ", WIDTH, HEIGHT * 0.4);
		DrawManager.DrawMidText("2. Load Game", WIDTH, HEIGHT * 0.5);
		DrawManager.DrawMidText(" 3. Detail Game", WIDTH, HEIGHT * 0.6);
		DrawManager.DrawMidText("4. Game Exit", WIDTH, HEIGHT * 0.7);
		iSelect = DrawManager.MenuSelectCursor(4, 3, 10, HEIGHT*0.4);
		switch (iSelect)
		{
		case MAIN_NEW:
			NewGame();
			break;
		case MAIN_LOAD:
			LoadGame();
			break;
		case MAIN_DETAIL:
			DetailGame();
			break;
		case MAIN_EXIT:
			bState = true;
			return;
		default:
			break;
		}
	}
}
void Game::MenuPage()
{
	int iSelect;
	bool bState = false;
	while (!bState)
	{
		system("cls");
		DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
		DrawManager.DrawMidText("★★ MENU ★★", WIDTH, HEIGHT * 0.2);
		DrawManager.DrawMidText("DONGEON ", WIDTH, HEIGHT * 0.3);
		DrawManager.DrawMidText("PLAYER INFO", WIDTH, HEIGHT * 0.4);
		DrawManager.DrawMidText("MONSTER INFO", WIDTH, HEIGHT * 0.5);
		DrawManager.DrawMidText("WEAPON SHOP", WIDTH, HEIGHT * 0.6);
		DrawManager.DrawMidText("SAVE", WIDTH, HEIGHT * 0.7);
		DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.8);
		iSelect = DrawManager.MenuSelectCursor(6, 3, 10, HEIGHT*0.3);

		switch (iSelect)
		{
		case MENU_DONGEON:
			DongeonPage();
			break;
		case MENU_PINFO:
			PInfo();
			break;
		case MENU_MINFO:
			MInfo();
			break;
		case MENU_WEAPONSHOP:
			WeaponePage();
			break;
		case MENU_SAVE:
			Character.Save();
			break;
		case MENU_EXIT:
			bState = true;
			return;
		default:
			break;
		}
	}
}
void Game::PInfo()
{
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	Character.ShowPlayerDetail();
	system("pause");
}
void Game::MInfo()
{
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	Character.ShowMonsterDetail();
	system("pause");
}
void Game::DongeonPage()
{ 
	Character.Fight(Character.EnemySelect());
}
void Game::NewGame()
{
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	DrawManager.DrawMidText("Player Name Set : ", WIDTH, HEIGHT * 0.5);
	Character.SetPlayerName();
	Character.SetDefault();
	MenuPage();
}
void Game::LoadGame()
{
	if (Character.Load() == 1)
		MenuPage();
}
void Game::DetailGame()
{
	system("cls");
	DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	RED
	DrawManager.DrawMidText("====== 게임 설명 ======", WIDTH, HEIGHT*0.2);
	DrawManager.DrawMidText(">> 던전에서의 싸움은 가위바위보로 진행함", WIDTH, HEIGHT*0.3);
	DrawManager.DrawMidText(">> 무기 구입 시 공격력 상승 효과가 있음 ", WIDTH, HEIGHT*0.4);
	DrawManager.DrawMidText(">> 무기 구입 시 랜덤 확률로 추가 공격력 획득", WIDTH, HEIGHT*0.5);
	DrawManager.DrawMidText(">> 몬스터를 처치하면 골드를 얻을 수 있음", WIDTH, HEIGHT*0.6);
	DrawManager.gotoxy(0, 33);
	ORIGINAL
	system("pause");
}
void Game::WeaponePage()
{
	Character.BuyWeapon();	
}

Game::~Game()
{
}
