#pragma once
#include "Level.h"
#include "Boss.h"
#include "Key.h"

class Graveyard :
	public Level
{
public:

	Graveyard();
	Graveyard(GraphicManager* g, Warrior* wa);
	Graveyard(GraphicManager* g, Warrior* wa, Archer* ar);
	~Graveyard();

	void Setup();
	void Execute();

	void Update();
	void Draw();
	void Change();
};

