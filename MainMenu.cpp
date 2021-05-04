#include "MainMenu.h"
#include "Menu.h"
#include "PickMenu.h"

MainMenu::MainMenu(Menu* m)
{
	menu = m;
	play = false;
	graphic = menu->GetGraphic();
	Setup();
}
MainMenu::MainMenu()
{
	menu = NULL;
	play = false;
}
MainMenu::~MainMenu()
{
}
void MainMenu::Setup()
{
	texture.loadFromFile("Textures/Menu.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	bPlay.setGraphic(graphic);
	bPlay.getTxt()->setString("Play");
	bPlay.getTxt()->setPosition(130, 110);
	bPlay.getSprite()->setPosition(100, 100);

	bLoadgame.setGraphic(graphic);
	bLoadgame.getTxt()->setString("LoadGame");
	bLoadgame.getTxt()->setPosition(130, 210);
	bLoadgame.getSprite()->setPosition(100, 200);

	bRankings.setGraphic(graphic);
	bRankings.getTxt()->setString("Rankings");
	bRankings.getTxt()->setPosition(130, 310);
	bRankings.getSprite()->setPosition(100, 300);

	bQuitgame.setGraphic(graphic);
	bQuitgame.getTxt()->setString("Quit");
	bQuitgame.getTxt()->setPosition(130, 510);
	bQuitgame.getSprite()->setPosition(100, 500);

	button_list.push_back(&bPlay);
	button_list.push_back(&bLoadgame);
	button_list.push_back(&bRankings);
	button_list.push_back(&bQuitgame);

	play = false;
	done = false;
}
void MainMenu::Change()
{
	if(play)
	{
		std::cout << play;
		play = false;
		menu->PushState(new PickMenu(menu));
	}
}
void MainMenu::Execute()
{
	if (bPlay.getPressed())
	{
		bPlay.setPressed(false);
		play = true;
	}
	if (bQuitgame.getPressed())
	{
		graphic->getWindow()->close();
	}
}