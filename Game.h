#ifndef GAME_H
#define GAME_H

#pragma once
#include "GraphicManager.h"
#include "stdafx.h"
#include "Menu.h"
#include "GameState.h"
#include "Warrior.h"
#include "Archer.h"

class GameState;
class MenuStates;

class Game
{
private:

	Archer* archer;
	Warrior* warrior;
	GraphicManager graphic;
	sf::Time MS_PER_UPDATE;

	std::vector<GameState*> states;

public:

	Game();
	~Game();

	void Setup();

	void PushState(GameState* state);
	void PopState();
	GameState* CurrentState();

	void Execute();

	GraphicManager* getGraphic() { return &graphic; }

	Warrior* CreateWarrior();
	Warrior* getWarrior() { return warrior; }

	Archer* CreateArcher();
	Archer* getArcher() { return archer; }
};
#endif
