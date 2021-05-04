#include "Hamburguer.h"

Hamburguer::Hamburguer()
{
	count = 0;
	identificator = 2;
}

Hamburguer::Hamburguer(float x, float y)
{
	image.loadFromFile("Textures/food.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(static_cast<int>(x), static_cast<int>(y), static_cast<int>(image.getSize().x/5), static_cast<int>(image.getSize().y));
	body = r;

	sprite.setPosition(sf::Vector2f(x, y));

	sf::IntRect s(0, 0, 32, 32);
	rectBaseSprite = s;

	identificator = 2;
}


Hamburguer::~Hamburguer()
{
}

void Hamburguer::Execute()
{
	Animation();
}

void Hamburguer::Animation()
{
	if (count == 5) {
		rectBaseSprite.left += 32;
		if (rectBaseSprite.left > 160 - 32) {
			rectBaseSprite.left = 0;
		}
		count = 0;
		sprite.setTextureRect(rectBaseSprite);
	}
	count++;
}
