#pragma once
#include "State.h"
#include "Entity.h"
#include "Button.h"

class Menu;

class BaseMenu :
	public Entity, public State
{

protected:

	std::vector<Button*> button_list;
	bool done;
	Menu* menu;

public:

	BaseMenu(Menu* m);
	BaseMenu();
	~BaseMenu();

	virtual void Update();
	virtual void Draw();
	virtual void Change();

	virtual void Execute() = 0;

	std::vector<Button*>* getlist()
	{
		return &button_list;
	}
	void setDone(bool a) { done = a; }
	bool getDone(){ return done; }
};