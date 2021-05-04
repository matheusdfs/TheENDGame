#pragma once
#include "stdafx.h"
#include "GraphicManager.h"

class Entity {
protected:
	GraphicManager* graphic;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect body;

public:

	Entity();
	~Entity();

	virtual void Print();
	virtual void Execute() = 0;

	sf::Sprite* getSprite()
	{
		return &sprite;
	}
	void setGraphic(GraphicManager* g)
	{
		graphic = g;
	}
	sf::IntRect* getBody()
	{
		return &body;
	}
};