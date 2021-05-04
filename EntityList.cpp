#include "EntityList.h"

EntityList::EntityList() {}
EntityList::~EntityList() {}
void EntityList::Add(Entity* info) {
	entity_list.Add(info);
}
void EntityList::Draw() {

	entity_list.setAtual(entity_list.getPrim());
	while (entity_list.getAtual() != NULL)
	{
		entity_list.getAtual()->getInfo()->Print();
		entity_list.setAtual(entity_list.getAtual()->getNext());
	}
}
void EntityList::Update()
{
	entity_list.setAtual(entity_list.getPrim());
	while (entity_list.getAtual() != NULL)
	{
		entity_list.getAtual()->getInfo()->Execute();
		entity_list.setAtual(entity_list.getAtual()->getNext());
	}
}
void EntityList::Clean() {
	entity_list.Clean();
}
void EntityList::setGraphic(GraphicManager* gm)
{
	entity_list.setAtual(entity_list.getPrim());

	while (entity_list.getAtual() != NULL) {
		entity_list.getAtual()->getInfo()->setGraphic(gm);
		entity_list.setAtual(entity_list.getAtual()->getNext());
	}
}

void EntityList::deleteEntity(Entity* pe)
{
	entity_list.setAtual(entity_list.getPrim());
	while (entity_list.getAtual() != NULL)
	{
		if (entity_list.getAtual()->getInfo() == pe)
		{
			if (entity_list.getAtual() != entity_list.getLast())
			{
				entity_list.getAtual()->getNext()->setBefore(entity_list.getAtual()->getBefore());
				entity_list.getAtual()->getBefore()->setNext(entity_list.getAtual()->getNext());
				delete (entity_list.getAtual()->getInfo());
				delete (entity_list.getAtual());
				break;
			}
			else
			{
				entity_list.setLast(entity_list.getAtual()->getBefore());
				entity_list.getAtual()->getBefore()->setNext(NULL);
				delete (entity_list.getAtual()->getInfo());
				delete (entity_list.getAtual());
				break;
			}
		}
		entity_list.setAtual(entity_list.getAtual()->getNext());
	}
}