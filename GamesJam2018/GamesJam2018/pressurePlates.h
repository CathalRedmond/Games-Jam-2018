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

	void setTexture(sf::Texture const t_plateTextureOn, sf::Texture const t_plateTextureOff);
	sf::Sprite getSprite();
	void collsion(Player & t_playerOne, Player & t_playerTwo);
	bool getPlateState();
	void setPosition(sf::Vector2f t_platePosition);

private:
	void setUpSprite();

	// bool for is plate is on or off
	bool plateOn{ false };

	// const for which texture the plate is
	static const int PLATE_ON = 0;
	static const int PLATE_OFF = 1;

	// player sprite
	sf::Sprite m_plateSprite;

	// player textures
	sf::Texture m_plateTexture[2];

	// position of the plate
	sf::Vector2f m_platePosition;
};

#endif // !PRESSUREPLATES_H
