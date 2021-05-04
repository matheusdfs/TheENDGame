#pragma once
#include "Entity.h"
class Button :
	public Entity
{
private:

	sf::Text txt;
	sf::Font font;

	bool is_select;
	bool pressed;

public:

	Button();
	~Button();


	void Execute();
	void Print();

	sf::Text* getTxt() { return &txt; }
	
	void IsSelect();
	void setSelect(bool a) { is_select = a; }
	bool getSelect() const { return is_select; }

	void Pressed();
	void setPressed(bool a) { pressed = a; }
	bool getPressed() const { return pressed; }
};