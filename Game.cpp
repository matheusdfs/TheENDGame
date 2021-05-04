#pragma once
#include "Game.h"
#include "GameState.h"

Game::Game()
{
	Setup();
}
Game::~Game()
{
	while (!states.empty())
		PopState();
}
void Game::Setup()
{
	MS_PER_UPDATE = sf::seconds(1.0f / 60.0f);
	PushState(new Menu(this));
	Execute();
}
Warrior* Game::CreateWarrior()
{
	warrior = new Warrior();
	return warrior;
}
Archer* Game::CreateArcher()
{
	archer = new Archer();
	return archer;
}
void Game::Execute()
{
	sf::Clock clock;
	sf::Time previous = clock.getElapsedTime();
	sf::Time lag = sf::seconds(0);
	while (graphic.getWindow()->isOpen())
	{
		sf::Time current = clock.getElapsedTime();
		sf::Time elapsed = current - previous;
		previous = current;
		lag += elapsed;

		//CurrentState()->HandleInput();

		while (lag >= MS_PER_UPDATE)
		{
			graphic.Update();
			CurrentState()->Update();
			lag -= MS_PER_UPDATE;
		}
		graphic.StartDraw();
		CurrentState()->Draw();
		graphic.EndDraw();
		CurrentState()->Change();
		if (CurrentState()->getQuit())
		{
			if(!states.empty())
				PopState();
			graphic.RestoreView();
		}
	}
}
GameState* Game::CurrentState()
{
	if (states.empty())
		return nullptr;
	else
		return states.back();
}
void Game::PushState(GameState* state)
{
	states.push_back(state);
}
void Game::PopState()
{
	states.back();
	delete states.back();
	states.pop_back();
}