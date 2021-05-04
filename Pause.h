#pragma once
#include "GameState.h"
#include "Entity.h"
#include "Button.h"
#include "Play.h"

class Pause :
	public GameState, public Entity
{
private:

	Button bResume, bQuit;

	bool resume;
	bool quit;
	Play* play;

public:

	Pause(Play* p, Game* ga, GraphicManager* g);
	Pause();
	~Pause();

	void Update();
	void Draw();
	void Change();
	void Execute();
};

