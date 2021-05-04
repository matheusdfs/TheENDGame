#include "Mage.h"
#include "CollisionManager.h"

Mage::Mage()
{
	collision = NULL;
	entList = NULL;
	pl1 = NULL;
	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 2;
	health = 10;
}
Mage::Mage(float x, float y, EntityList* el, CollisionManager* cl)
{
	entList = el;
	collision = cl;
	
	image.loadFromFile("Textures/mageSprite.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(0, 0, static_cast<int>(image.getSize().x / 11), static_cast<int>(image.getSize().y));
	body = r;

	sf::IntRect s(0, 0, image.getSize().x / 11, image.getSize().y);
	rectBaseSprite = s;
	sprite.setTextureRect(rectBaseSprite);

	pl1 = NULL;
	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 2;
	health = 10;

	body.left = x;
	body.top = y;
	sprite.setPosition(x, y);
}
Mage::~Mage()
{
}
void Mage::Execute()
{
	acceleration.x = pl1->getBody()->left + 17 - sprite.getPosition().x;
	acceleration.y = pl1->getBody()->top + 20 - sprite.getPosition().y;

	float tam = acceleration.x * acceleration.x + acceleration.y * acceleration.y;
	tam = sqrt(tam);

	acceleration.x = acceleration.x * 2.5f / tam;
	acceleration.y = acceleration.y * 2.5f / tam;

	if (attacking == false && tam < 300.0f && cd > 180)
	{
		cd = 0;
		attacking = true;
		rectBaseSprite.left = 180;
	}
	cd++;
	Animate();
}
void Mage::Animate()
{
	if (count == 5)
	{
		count = 0;
		if (!attacking)
		{
			if (acceleration.x > 0)
			{
				if (rectBaseSprite.width > 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				rectBaseSprite.left = rectBaseSprite.left + 120;
				sprite.setTextureRect(rectBaseSprite);
				rectBaseSprite.left = rectBaseSprite.left - 60;
			}
			else
			{
				if (rectBaseSprite.width < 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				rectBaseSprite.left = rectBaseSprite.left + 60;
				sprite.setTextureRect(rectBaseSprite);
			}
			if (rectBaseSprite.left == 180) { // ta sempre entrando nesse loop e setando rectBaseSprite como 0 novamente
				rectBaseSprite.left = -60;
			}
		}
		else
		{
			rectBaseSprite.left = rectBaseSprite.left + 60;
			sprite.setTextureRect(rectBaseSprite);
			if (rectBaseSprite.left == 600) { // ta sempre entrando nesse loop e setando rectBaseSprite como 0 novamente
				rectBaseSprite.left = -60;
				attacking = false;
			}
			if (rectBaseSprite.left == 480) {
				Fireball* new_fireball = new Fireball(sprite.getPosition().x, sprite.getPosition().y, acceleration.x, acceleration.y);
				new_fireball->setGraphic(graphic);
				entList->Add(static_cast<Entity*> (new_fireball));
				collision->getProjectileList()->getEnemyList()->push_back(new_fireball);
			}
		}
	}
	count++;
}