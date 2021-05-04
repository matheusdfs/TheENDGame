#include "Plataform.h"

Plataform::Plataform()
{
}
Plataform::Plataform(float x, float y)
{
	image.loadFromFile("Textures/block1.png");

	texture.loadFromImage(image);
	sprite.setTexture(texture);
	
	sf::IntRect r(static_cast<int>(x), static_cast<int>(y), static_cast<int>(image.getSize().x), static_cast<int>(image.getSize().y));
	body = r;

	sprite.setPosition(sf::Vector2f(x, y));
}
Plataform::~Plataform()
{
}
void Plataform::Execute()
{
}
