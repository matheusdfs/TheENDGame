#include "Button.h"
Button::Button() :
	is_select(false),
	pressed(false)
{
	font.loadFromFile("Resources/font.ttf");
	texture.loadFromFile("Textures/Button.png");
	sprite.setTexture(texture);
	txt.setFont((font));
	txt.setCharacterSize(38);
	txt.setFillColor(sf::Color::White);
}
Button::~Button()
{

}
void Button::IsSelect()
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*(graphic->getWindow()));
	if (localPosition.x > sprite.getPosition().x&& localPosition.x < (sprite.getPosition().x + sprite.getLocalBounds().width))
	{
		if (localPosition.y > sprite.getPosition().y&& localPosition.y < (sprite.getPosition().y + sprite.getLocalBounds().height))
		{
			is_select = true;
		}
		else
			is_select = false;
	}
	else
		is_select = false;
}
void Button::Pressed()
{
	if (is_select == true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			pressed = true;
		}
		else
			pressed = false;
	}
	
}
void Button::Execute()
{
	IsSelect();
	Pressed();
	if (is_select == true)
	{
		txt.setFillColor(sf::Color::Red);
	}
	else
		txt.setFillColor(sf::Color::White);

}
void Button::Print()
{
	graphic->Draw(sprite);
	graphic->Draw(txt);
}