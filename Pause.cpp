#include "Pause.h"
#include "Game.h"

Pause::Pause(Play* p, Game* ga, GraphicManager* g)
{
	play = p;
	game = ga;
	graphic = g;

	quit = false;
	resume = false;

	graphic->setCameraSize(800, 640);
	graphic->RestoreView();

	texture.loadFromFile("Textures/Pause.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);

	bResume.setGraphic(graphic);
	bResume.getTxt()->setString("Resume");
	bResume.getTxt()->setPosition(330, 210);
	bResume.getSprite()->setPosition(300, 200);

	bQuit.setGraphic(graphic);
	bQuit.getTxt()->setString("Quit");
	bQuit.getTxt()->setPosition(330, 310);
	bQuit.getSprite()->setPosition(300, 300);
}
Pause::Pause()
{

}
Pause::~Pause()
{
}
void Pause::Update()
{
	Execute();
}
void Pause::Draw()
{
	Print();
	bResume.Print();
	bQuit.Print();
}
void Pause::Change()
{
	if (resume == true)
	{
		game->PopState();
	}
	if (quit == true)
	{
		play->setQuit(true);
		game->PopState();
	}
}
void Pause::Execute()
{
	bResume.Execute();
	bQuit.Execute();

	if (bResume.getPressed())
	{
		resume = true;
	}
	if (bQuit.getPressed())
	{
		quit = true;
	}
}
