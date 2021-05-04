#pragma once
#include "BaseMenu.h"
#include "Button.h"

class Menu;

class MainMenu :
	public BaseMenu
{

private:

	bool play;
	Button bPlay, bRankings, bLoadgame, bQuitgame;

public:

	MainMenu(Menu* m);
	MainMenu();
	~MainMenu();

	void Setup();

	void Change();
	void Execute();
};


