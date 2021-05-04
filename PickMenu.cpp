#include "PickMenu.h"
#include "Play.h"
#include "Menu.h"

PickMenu::PickMenu(Menu* m)
{
	menu = m;
	back = false;
	graphic = menu->GetGraphic();
	Setup();
}
PickMenu::PickMenu()
{
	menu = NULL;
	back = false;
}
PickMenu::~PickMenu()
{
}
void PickMenu::Setup()
{
	texture.loadFromFile("Textures/Menu.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);

	b1Player.setGraphic(graphic);
	b1Player.getTxt()->setString("1 Player");
	b1Player.getTxt()->setPosition(130, 110);
	b1Player.getSprite()->setPosition(100, 100);

	b2Players.setGraphic(graphic);
	b2Players.getTxt()->setString("2 Players");
	b2Players.getTxt()->setPosition(430, 110);
	b2Players.getSprite()->setPosition(400, 100);

	bLevel1.setGraphic(graphic);
	bLevel1.getTxt()->setString("Level 1");
	bLevel1.getTxt()->setPosition(130, 210);
	bLevel1.getSprite()->setPosition(100, 200);

	bLevel2.setGraphic(graphic);
	bLevel2.getTxt()->setString("Level 2");
	bLevel2.getTxt()->setPosition(430, 210);
	bLevel2.getSprite()->setPosition(400, 200);

	bStartGame.setGraphic(graphic);
	bStartGame.getTxt()->setString("Start");
	bStartGame.getTxt()->setPosition(130, 310);
	bStartGame.getSprite()->setPosition(100, 300);

	bBack.setGraphic(graphic);
	bBack.getTxt()->setString("Back");
	bBack.getTxt()->setPosition(130, 410);
	bBack.getSprite()->setPosition(100, 400);

	button_list.push_back(&b1Player);
	button_list.push_back(&b2Players);
	button_list.push_back(&bLevel1);
	button_list.push_back(&bLevel2);
	button_list.push_back(&bStartGame);
	button_list.push_back(&bBack);

	quit = false;
	back = false;
	n_players = 1;
	n_level = 1;
	startgame = false;
}
void PickMenu::Change()
{
	if (startgame)
	{
		startgame = false;
		menu->AddState(new Play(menu->getGame(), n_players, n_level));
	}
}
void PickMenu::Execute()
{
	if (bBack.getPressed())
	{
		quit = true;
	}
	if (bStartGame.getPressed())
	{
		quit = true;
		startgame = true;
	}
	if (b1Player.getPressed())
	{
		n_players = 1;
	}
	if (b2Players.getPressed())
	{
		n_players = 2;
	}
	if (bLevel1.getPressed())
	{
		n_level = 1;
	}
	if (bLevel2.getPressed())
	{
		n_level = 2;
	}
}