#include "Ruby.h"

Ruby::Ruby()
{
}

Ruby::Ruby(float x, float y)
{
	image.loadFromFile("Textures/Etc.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(480, 384, 32, 32);
	rectBaseSprite = r;
	sprite.setTextureRect(rectBaseSprite);

	sf::IntRect s(x, y, 32, 32);
	body = s;

	sprite.setPosition(sf::Vector2f(x, y));
	identificator = 7;
}
Ruby::~Ruby()
{
}
void Ruby::Execute()
{
}
