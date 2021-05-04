#pragma once
#include "Menu.h"
#include "BaseMenu.h"
#include "MainMenu.h"
#include "PickMenu.h"
#include "Game.h"

Menu::Menu(Game* g)
{
	game = g;
	PushState(new MainMenu(this));
}
Menu::Menu()
{
}
Menu::~Menu()
{
}
void Menu::AddState(GameState* state)
{
	game->PushState(state);
}
void Menu::PushState(BaseMenu* state)
{
	menu_states.push_back(state);
}
void Menu::PopState()
{
	menu_states.back();
	delete menu_states.back();
	menu_states.pop_back();
}
BaseMenu* Menu::CurrentState()
{
	if (menu_states.empty())
		return nullptr;
	else
		return menu_states.back();
}
void Menu::Update()
{
	CurrentState()->Update();
}
void Menu::Draw()
{
	CurrentState()->Draw();
}
void Menu::Change()
{
	CurrentState()->Change();
	if(CurrentState()->getQuit())
	{
		PopState();
	}
}
GraphicManager* Menu::GetGraphic()
{
	return game->getGraphic();
}
