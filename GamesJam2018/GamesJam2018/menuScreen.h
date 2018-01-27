#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML\Graphics.hpp>
#include "game.h"
#include "controller.h"
class menuScreen
{
public:
	menuScreen(currentScreen &t_curScreen);
	~menuScreen();

	void update();
	void render(sf::RenderWindow & t_window);
	void processEvents(sf::Event & t_event);
	void loadTextures();
	void handleControllerInput();
private:
	sf::Sprite m_menuSprite;
	sf::Texture m_menuTextureA;
	sf::Texture m_menuTextureB;
	currentScreen &m_currentScreen;

	int m_timer;
	

	Controller m_controller;
};


#endif // !MENUSCREEN_H

