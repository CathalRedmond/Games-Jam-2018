#pragma once
#include <SFML\graphics.hpp>

class Field
{
public:
	Field();
	~Field();
	void render(sf::RenderWindow & t_window);
	void setTexture(sf::Texture const & t_fieldTexture);
	sf::Sprite getSprite();
	void setPosition(sf::Vector2f t_fieldPosition);
	void setScale(float x, float y);
private:
	void setUpSprites();

	// position of the wall
	sf::Vector2f m_fieldPosition;

	// wall sprite
	sf::Sprite m_fieldSprite;

	// wall texture
	sf::Texture m_fieldTexture;
};

