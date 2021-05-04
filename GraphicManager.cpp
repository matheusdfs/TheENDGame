#include "GraphicManager.h"

GraphicManager::GraphicManager()
{
	Setup("Jogo", sf::Vector2u(800, 640));
}
GraphicManager::GraphicManager(const std::string& title, const sf::Vector2u& size)
{
	Setup(title, size);
}
GraphicManager::~GraphicManager()
{
	Destroy();
}
bool GraphicManager::WindowIsOpen()
{
	return window.isOpen();
}
void GraphicManager::Update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}
void GraphicManager::StartDraw()
{
	window.clear(sf::Color::Black);
}
void GraphicManager::EndDraw()
{
	window.display();
}
void GraphicManager::setDone(bool done)
{
	window_done = done;
}
void GraphicManager::updateView(float x, float y)
{
	setCamera(sf::Vector2f(x, y));
	window.setView(camera);
}
void GraphicManager::Draw(sf::Drawable& l_drawable)
{
	window.draw(l_drawable);
}
void GraphicManager::Setup(const std::string title, const sf::Vector2u& size)
{
	window_title = title;
	window_size = size;
	window_done = false;
	Create();
}
void GraphicManager::Create()
{
	window.create({ window_size.x, window_size.y, 32 }, window_title);
	window.setFramerateLimit(60);
	camera.setSize(800, 640);
}
void GraphicManager::Destroy()
{
	window.close();
}
void GraphicManager::RestoreView()
{
	window.setView(window.getDefaultView());
}

