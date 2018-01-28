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
	void setValues(sf::Texture const & t_wallTexture, sf::Vector2f const & t_wallPosition, sf::Vector2f const & t_scale);
	sf::Sprite getShape();
private:

	// position of the wall
	sf::Vector2f m_wallPosition;

	// wall sprite
	sf::Sprite m_wallSprite;

	// wall texture
	sf::Texture m_wallTexture;

	// scale of wall;
	sf::Vector2f m_wallScale;

	sf::RectangleShape m_shape;

};

#endif // !WALL_H