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
void Wall::setTexture(sf::Texture const & t_wallTexture)
{
	m_wallTexture = t_wallTexture;
 	setUpSprites();
}


/// <summary>
/// @brief returns wall sprite
/// </summary>
/// <returns>wall sprite</returns>
sf::Sprite Wall::getSprite()
{
	return m_wallSprite;
}

/// <summary>
/// @brief sets wall position
/// </summary>
/// <param name="t_wallPosition">new wall position</param>
void Wall::setPosition(sf::Vector2f t_wallPosition)
{
	m_wallPosition = t_wallPosition;
	m_wallSprite.setPosition(m_wallPosition);
}

/// <summary>
/// @brief sets up sprites position
/// </summary>
void Wall::setUpSprites()
{
		m_wallSprite.setTexture(m_wallTexture);
		m_wallSprite.setOrigin(m_wallSprite.getGlobalBounds().width / 2.0f, m_wallSprite.getGlobalBounds().height / 2.0f);
		m_wallSprite.setPosition(m_wallPosition);	
}
