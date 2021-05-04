#include "Arrow.h"

Arrow::Arrow()
{
}
Arrow::Arrow(float posX, float posY, float dirX)
{
	image.loadFromFile("Textures/Arrow.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(posX, posY, static_cast<int>(image.getSize().x), static_cast<int>(image.getSize().y));
	body = r;

	sprite.setPosition(sf::Vector2f(posX, posY));

	sf::IntRect s(0, 0, image.getSize().x, image.getSize().y);
	rectBaseSprite = s;
	sprite.setTextureRect(rectBaseSprite);

	directionX = dirX;

	if (dirX < 0)
	{
		directionX = -12;
		rectBaseSprite.width = -rectBaseSprite.width;
		rectBaseSprite.left = 36;
	}
	else
		directionX = 12;
	lifetime = 0;
	destroy = false;
}
Arrow::~Arrow()
{
}
void Arrow::Execute()
{
	body.left += directionX;
	sprite.setPosition(body.left, body.top);
	lifetime++;
	if (lifetime >= 60)
	{
		destroy = true;
	}
}
