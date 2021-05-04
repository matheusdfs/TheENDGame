#include "Ghost.h"
Ghost::Ghost()
{
	pl1 = NULL;
	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 1;
	health = 10;
}
Ghost::Ghost(int posX, int posY, Player* pl)
{
	pl1 = pl;

	image.loadFromFile("Textures/Ghost.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(0, 0, image.getSize().x, image.getSize().y);
	body = r;

	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 1;
	health = 10;

	sprite.setPosition(posX, posY);
	body.left = posX;
	body.top = posY;
}
Ghost::~Ghost()
{
}
void Ghost::Execute()
{
	sf::Vector2f direction;
	direction.x = pl1->getBody()->left - sprite.getPosition().x;
	direction.y = pl1->getBody()->top - sprite.getPosition().y;

	float tam = direction.x * direction.x + direction.y * direction.y;
	tam = sqrt(tam);

	if (tam == 0)
	{
		tam = 1;
	}
	direction.x = direction.x * 2.5f/ tam;
	direction.y = direction.y * 2.5f/ tam;

	body.left = body.left + static_cast<int>(direction.x);
	body.top = body.top + static_cast<int>(direction.y);
	sprite.setPosition(static_cast<float>(body.left), static_cast<float>(body.top));
}