#include "BaseMenu.h"
#include "Menu.h"
BaseMenu::BaseMenu(Menu* m)
{
	menu = m;
}
BaseMenu::BaseMenu()
{
	menu = NULL;
}
BaseMenu::~BaseMenu()
{
}
void BaseMenu::Update()
{
	for (auto it = button_list.begin(); it != button_list.end(); ++it)
	{
		(*it)->Execute();
	}
	Execute();
}
void BaseMenu::Draw()
{
	graphic->Draw(sprite);
	for (auto it = button_list.begin(); it != button_list.end(); ++it)
	{
		(*it)->Print();
	}
}
void BaseMenu::Change()
{
}