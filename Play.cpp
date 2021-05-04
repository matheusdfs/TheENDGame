#include "Play.h"
#include "Game.h"
#include "Pause.h"

Play::Play(){
	game = NULL;
}
Play::Play(Game* ga, int n_p, int n_l) {
	
	game = ga;
	n_players = n_p;
	n_level = n_l;
	create_nextlevel = false;

	warrior = game->CreateWarrior();
	if (n_players == 2)
	{
		archer = game->CreateArcher();
	}
	CreateLevel(n_level);
}
Play::~Play() {
	for (auto it = lvstates.begin(); it != lvstates.end(); ++it)
	{
		delete(*it);
	}
	lvstates.clear();
}
void Play::CreateLevel(int n)
{
	if (n == 1)
	{
		if (n_players == 1)
		{
			PushState(new Dungeon(game->getGraphic(), warrior));
		}
		else if (n_players == 2)
		{
			PushState(new Dungeon(game->getGraphic(), warrior, archer));
		}
	}
	else if (n == 2)
	{
		if (n_players == 1)
		{
			PushState(new Graveyard(game->getGraphic(), warrior));
		}
		else if (n_players == 2)
		{
			PushState(new Graveyard(game->getGraphic(), warrior, archer));
		}
	}
	CurrentState()->setPlay(this);
}
void Play::Update()
{
	CurrentState()->Update();
}
void Play::Draw()
{
	CurrentState()->Draw();
}
void Play::Change()
{
	CurrentState()->Change();
	if (CurrentState()->getQuit() == true)
	{
		PopState();
		if (create_nextlevel == true)
		{
			create_nextlevel = false;
			CreateLevel(2);
		}
		else
		{
			quit = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		game->PushState(new Pause(this, game, game->getGraphic()));
	}
}
Level* Play::CurrentState()
{
	if (lvstates.empty())
		return nullptr;
	else
		return lvstates.back();
}
void Play::PushState(Level* state)
{
	lvstates.push_back(state);
}
void Play::PopState()
{
	lvstates.back();
	delete lvstates.back();
	lvstates.pop_back();
}