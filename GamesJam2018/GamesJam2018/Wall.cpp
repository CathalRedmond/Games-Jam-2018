#include "Wall.h"

/// <summary>
/// @brief basic constructor
/// </summary>
Wall::Wall()
	
{
	
}

/// <summary>
/// @brief basic destrcutor
/// </summary>
Wall::~Wall()
{
}

/// <summary>
/// @brief renders wall onto screen
/// </summary>
/// <param name="t_window">renderwindow used</param>
void Wall::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_wallSprite);
}

/// <summary>
/// @brief sets the texture of the wall
/// </summary>
/// <param name="t_wallTexture">wall texture</param>
void Wall::setValues(sf::Texture const & t_wallTexture, sf::Vector2f const & t_wallPosition, sf::Vector2f const & t_scale)
{

	m_wallSprite.setTexture(t_wallTexture);
	m_wallSprite.setScale(t_scale);
	m_wallSprite.setOrigin(sf::Vector2f(m_wallSprite.getTexture()->getSize().x * 0.5f, m_wallSprite.getTexture()->getSize().y * 0.5f));
	m_wallSprite.setPosition(t_wallPosition);

}


/// <summary>
/// @brief returns wall sprite
/// </summary>
/// <returns>wall sprite</returns>
sf::Sprite Wall::getShape()
{
	return m_wallSprite;
}


