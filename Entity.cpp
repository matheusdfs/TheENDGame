#include "Entity.h"

Entity::Entity()
{
	graphic = NULL;
}
Entity::~Entity()
{
}
void Entity::Print()
{
	graphic->Draw(sprite);
}