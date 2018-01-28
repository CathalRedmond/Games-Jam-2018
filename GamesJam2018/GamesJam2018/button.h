#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include "Player.h"

/// <summary>
/// @brief class for the button used in the game
/// </summary>
class button 
{
public:
	button();
	~button();

	void render(sf::RenderWindow & t_window);
	void setTexture(sf::Texture const buttonTextureOn, sf::Texture const buttonTextureOff);
	sf::Sprite getSprite();
	bool collsion(Player & t_player);
	void setPosition(sf::Vector2f t_buttonPosition);
private:
	void setUpSprite();
	void turnButtonOn();


	// bool for if the button is on or off
	bool buttonOn{ false };

	// consts for the position in the texture array
	static const int BUTTON_ON = 0; 
	static const int BUTTON_OFF = 1;

	// button sprite
	sf::Sprite m_buttonSprite;

	// the two textures the button has - one for when it's off one for when it's on
	sf::Texture m_buttonTexture[2];

	// position of the button on screen
	sf::Vector2f m_buttonPosition;
};


#endif // !BUTTON_H