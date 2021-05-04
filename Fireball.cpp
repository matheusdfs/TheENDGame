#include "Fireball.h"

Fireball::Fireball()
{
}

Fireball::Fireball(float x, float y, float dirX, float dirY)
{

	image.loadFromFile("Textures/Projectile.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(static_cast<int>(x), static_cast<int>(y), static_cast<int>(image.getSize().x / 3), static_cast<int>(image.getSize().y));
	body = r;

	sprite.setPosition(sf::Vector2f(x, y));

	sf::IntRect s(0, 0, image.getSize().x / 3, image.getSize().y);
	rectBaseSprite = s;
	sprite.setTextureRect(rectBaseSprite);

	float tam = dirX * dirX + dirY * dirY;
	tam = sqrt(tam);

	directionX = 7 * dirX / tam;
	directionY = 7 * dirY / tam;


	if (directionX > 0)
	{
		rectBaseSprite.width = -rectBaseSprite.width;
	}

	lifetime = 0;
	destroy = false;
}
Fireball::~Fireball()
{
}
void Fireball::Execute()
{
	if (count == 1) {
		count = 0;
		rectBaseSprite.left += 34;
		sprite.setTextureRect(rectBaseSprite);
		if (rectBaseSprite.left == 68) {
			rectBaseSprite.left = -34;
		}

	}
	count++;

	body.left += directionX;
	body.top += directionY;
	sprite.setPosition(body.left, body.top);
	lifetime++;
	if (lifetime >= 60)
	{
		destroy = true;
	}
}
