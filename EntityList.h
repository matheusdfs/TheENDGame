#pragma once
#include "List.h"
#include "Entity.h"

class EntityList {
private:

	List < Entity > entity_list;

public:

	EntityList();
	~EntityList();

	void Add(Entity* info);
	void Draw();
	void Update();
	void Clean();
	void setGraphic(GraphicManager* gm);
	void deleteEntity(Entity* pe);
};