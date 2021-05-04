#pragma once
#include "Level.h"
#include "Ruby.h"

class Dungeon : public Level
{
public:

	Dungeon();
	Dungeon(GraphicManager* g, Warrior* wa);
	Dungeon(GraphicManager* g, Warrior* wa, Archer* ar);
	~Dungeon();

	void Setup();
	void Execute();

	void Update();
	void Draw();
	void Change();
};