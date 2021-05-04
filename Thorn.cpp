#include "Thorn.h"
Thorn::Thorn()
{
	identificator = 3;
}
Thorn::Thorn(float x, float y)
{
	image.loadFromFile("Textures/spikes1.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(static_cast<int>(x), static_cast<int>(y), static_cast<int>(image.getSize().x), static_cast<int>(image.getSize().y));
	body = r;

	sprite.setPosition(sf::Vector2f(x, y));
	identificator = 3;
}
Thorn::~Thorn()
{
}
void Thorn::Execute()
{
}