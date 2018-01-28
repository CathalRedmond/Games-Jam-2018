#include "pressurePlates.h"


/// <summary>
/// @brief basic constructor
/// </summary>
pressurePlates::pressurePlates()
{
}

/// <summary>
/// @brief basic destructor
/// </summary>
pressurePlates::~pressurePlates()
{
}

/// <summary>
/// @breif renders plate onto the screen
/// </summary>
/// <param name="t_window">renderwindow used</param>
void pressurePlates::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_plateSprite);
}

/// <summary>
/// @brief sets the textures of the plate
/// </summary>
/// <param name="plateTextureOn">texture used for plate on</param>
/// <param name="plateTextureOff">texture used for plate off</param>
void pressurePlates::setTexture(sf::Texture const plateTextureOn, sf::Texture const plateTextureOff)
{
	m_plateTexture[PLATE_ON] = plateTextureOn;
	m_plateTexture[PLATE_OFF] = plateTextureOff;
	setUpSprite();
}

/// <summary>
/// @brief returns plate sprite
/// </summary>
/// <returns>plate sprite</returns>
sf::Sprite pressurePlates::getSprite()
{
	return m_plateSprite;
}

/// <summary>
/// @brief check collsion between plate and players turns on if touching 
/// turns off if not touching
/// </summary>
/// <param name="t_playersOne">first player</param>
/// <param name="t_playersTwo">second player</param>
void pressurePlates::collsion(Player & t_playersOne, Player & t_playersTwo)
{
	if ((m_plateSprite.getGlobalBounds().intersects(t_playersOne.getSprite().getGlobalBounds())) || (m_plateSprite.getGlobalBounds().intersects(t_playersTwo.getSprite().getGlobalBounds())))
	{
		plateOn = true;
		m_plateSprite.setTexture(m_plateTexture[PLATE_ON]);
		m_plateSprite.setOrigin(m_plateSprite.getGlobalBounds().width / 2.0f, m_plateSprite.getGlobalBounds().height / 2.0f);
		m_plateSprite.setPosition(m_platePosition);


	}
	if ((!m_plateSprite.getGlobalBounds().intersects(t_playersOne.getSprite().getGlobalBounds())) && (!m_plateSprite.getGlobalBounds().intersects(t_playersTwo.getSprite().getGlobalBounds())))
	{
		plateOn = false;
		m_plateSprite.setTexture(m_plateTexture[PLATE_OFF]);
		m_plateSprite.setOrigin(m_plateSprite.getGlobalBounds().width / 2.0f, m_plateSprite.getGlobalBounds().height / 2.0f);
		m_plateSprite.setPosition(m_platePosition);


	}
}

/// <summary>
/// @breif returns if plate is active
/// </summary>
/// <returns>plate</returns>
bool pressurePlates::getPlateState()
{
	return plateOn;
}

/// <summary>
/// @brief sets position of the plate
/// </summary>
/// <param name="t_platePosition">new position of the plate</param>
void pressurePlates::setPosition(sf::Vector2f t_platePosition)
{
	m_platePosition = t_platePosition;
}

/// <summary>
/// @breif sets up sprite used
/// </summary>
void pressurePlates::setUpSprite()
{
	m_plateSprite.setTexture(m_plateTexture[PLATE_OFF]);
	m_plateSprite.setOrigin(m_plateSprite.getGlobalBounds().width / 2.0f, m_plateSprite.getGlobalBounds().height / 2.0f);
	m_plateSprite.setPosition(m_platePosition);
}

