#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <SFML\Graphics.hpp>

class menuScreen
{
public:
	menuScreen();
	~menuScreen();

	void update();
	void render(sf::RenderWindow & t_window);
	void processEvents(sf::Event & t_event);
};


#endif // !MENUSCREEN_H

