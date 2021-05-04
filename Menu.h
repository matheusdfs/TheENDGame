#pragma once
#include "GameState.h"
#include "GraphicManager.h"

class Game;
class BaseMenu;

class Menu :
	public GameState
{
private:

	std::vector<BaseMenu*> menu_states;

public:

	Menu(Game* g);
	Menu();
	~Menu();


	void AddState(GameState* state);
	
	Game* getGame() { return game; }

	void PushState(BaseMenu* state);
	void PopState();
	BaseMenu* CurrentState();

	void Update();
	void Draw();
	void Change();

	GraphicManager* GetGraphic();
};