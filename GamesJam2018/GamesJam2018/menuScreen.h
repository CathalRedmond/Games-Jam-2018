#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML\Graphics.hpp>
#include "game.h"
#include "controller.h"

enum class currentScreen;

class menuScreen
{
public:
	menuScreen(currentScreen &t_curScreen);
	~menuScreen();

	void update();
	void render(sf::RenderWindow & t_window);
	void processEvents(sf::Event & t_event);
	void loadTexturesAndFonts();
	void handleControllerInput();
private:
	sf::Sprite m_menuSprite;
	sf::Texture m_menuTextureA;
	sf::Texture m_menuTextureB;
	currentScreen &m_currentScreen;

	int m_timer;
	sf::Font m_font;

	sf::Text m_text;

	Controller m_controller;
};


#endif // !MENUSCREEN_H

