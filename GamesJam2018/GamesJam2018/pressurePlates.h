#ifndef PRESSUREPLATES_H
#define PRESSUREPLATES_H

#include <SFML\Graphics.hpp>
#include "Player.h"

class pressurePlates 
{
public:
	pressurePlates();
	~pressurePlates();



	void render(sf::RenderWindow & t_window);

	void setTexture(sf::Texture const plateTextureOn, sf::Texture const plateTextureOff);
	sf::Sprite getSprite();
	void collsion(Player & t_player, Player & t_player2);
	bool getState();

private:
	void setUpSprites();
	bool plateOn{ false };
	void changeButtonState();
	int playertouching = 0;
	bool active{ false };

	static const int PLATE_ON = 0;
	static const int PLATE_OFF = 1;

	sf::Sprite m_plateSprite;

	sf::Texture m_plateTexture[2];
};

#endif // !PRESSUREPLATES_H
