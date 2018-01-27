#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include "Player.h"

class button 
{
public:
	button();
	~button();

	void render(sf::RenderWindow & t_window);
	void setTexture(sf::Texture const buttonTextureOn, sf::Texture const buttonTextureOff);
	sf::Sprite getSprite();
	bool collsion(Player & t_player);
private:
	void setUpSprite();

	bool buttonOn{ false };
	void turnButtonOn();
	static const int BUTTON_ON = 0; 
	static const int BUTTON_OFF = 1;

	sf::Sprite m_buttonSprite;

	sf::Texture m_buttonTexture[2];
};


#endif // !BUTTON_H