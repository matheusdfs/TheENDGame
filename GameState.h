#pragma once
#include "State.h"
#include "stdafx.h"

class Game;

class GameState :
	public State
{
protected:

	Game* game;

public:

	GameState() {
		game = NULL;
	}
	~GameState() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Change() = 0;
};