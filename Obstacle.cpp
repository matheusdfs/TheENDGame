#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(float x, float y)
{
	sprite.setColor(sf::Color::White);
	sprite.setPosition(x, y);
}

Obstacle::~Obstacle()
{
}

void Obstacle::Execute()
{
}
