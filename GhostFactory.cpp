#include "GhostFactory.h"
#include "CollisionManager.h"
GhostFactory::GhostFactory()
{
	count2 = 0;
}
GhostFactory::GhostFactory(float x, float y, EntityList* el, CollisionManager* cl)
{
	count2 = 0;
	EnList = el;
	colision = cl;

	image.loadFromFile("Textures/Portal.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(static_cast<int>(x), static_cast<int>(y), static_cast<int>(image.getSize().x / 8), static_cast<int>(image.getSize().y/3));
	body = r;

	sprite.setPosition(sf::Vector2f(x, y));

	sf::IntRect s(0, 0, 64, 64);
	rectBaseSprite = s;
}
GhostFactory::~GhostFactory()
{
}
void GhostFactory::Execute()
{
	product();
	animate();
}
void GhostFactory::product()
{
	if (rand() % 180 == 0)
	{
		count2 = 0;
		Ghost* new_ghost = new Ghost(sprite.getPosition().x, sprite.getPosition().y, pl1);
		new_ghost->setGraphic(graphic);
		EnList->Add(static_cast<Entity*>(new_ghost));
		colision->getEnemyList()->getList()->push_back(new_ghost);
		new_ghost = NULL;
	}
	count2++;
}
void GhostFactory::animate()
{
	if (count == 15) {
		rectBaseSprite.left += 64;
		if (rectBaseSprite.left > 512 - 64) {
			rectBaseSprite.left = 0;
		}
		count = 0;
		sprite.setTextureRect(rectBaseSprite);
	}
	count++;
}