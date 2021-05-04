#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GraphicManager
{
private:

	sf::RenderWindow window;
	sf::View camera;
	sf::Vector2u window_size;
	std::string window_title;

	bool window_done;

	void Setup(const std::string titulo, const sf::Vector2u& tamanho);
	void Create();
	void Destroy();


public:

	GraphicManager();
	GraphicManager(const std::string& title, const sf::Vector2u& size);
	~GraphicManager();

	bool WindowIsOpen();

	void Update();
	void StartDraw();
	void EndDraw();
	void setDone(bool done);
	void updateView(float x, float y);
	void Draw(sf::Drawable& l_drawable);
	void setView() { window.setView(camera); }
	void setCamera(sf::Vector2f position) { camera.setCenter(position); }
	void RestoreView();

	void setCameraSize(float x, float y) { camera.setSize(x, y); }
	sf::RenderWindow* getWindow() { return &window; }
	sf::View* getCamera() { return &camera; }
};