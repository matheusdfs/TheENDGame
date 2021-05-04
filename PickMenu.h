#pragma once
#include "BaseMenu.h"
#include "Button.h"

class Menu;

class PickMenu :
	public BaseMenu
{
private:

	bool back;
	bool startgame;
	int n_level;
	int n_players;


	Button b1Player, b2Players, bLevel1, bLevel2, bStartGame, bBack;

public:

	PickMenu(Menu* m);
	PickMenu();
	~PickMenu();

	void Setup();

	void Change();
	void Execute();
};

