#ifndef WALL_H
#define WALL_H

#include <SFML\graphics.hpp>


/// <summary>
/// @brief wall class
/// </summary>
class Wall
{
public:
	Wall();
	~Wall();
	void render(sf::RenderWindow & t_window);
	void setTexture(sf::Texture const & t_wallTexture);
	sf::Sprite getSprite();
	void setPosition(sf::Vector2f t_wallPosition);
private:
	void setUpSprites();

	// position of the wall
	sf::Vector2f m_wallPosition;

	// wall sprite
	sf::Sprite m_wallSprite;

	// wall texture
	sf::Texture m_wallTexture;

};

#endif // !WALL_H