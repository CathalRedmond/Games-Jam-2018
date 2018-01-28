#include "button.h"


/// <summary>
/// @brief basic constructor
/// </summary>
button::button( )
{
}

/// <summary>
/// @brief basic destructor
/// </summary>
button::~button()
{
}

/// <summary>
/// @brief renders the button sprite onto the screen
/// </summary>
/// <param name="t_window">sf::renderwindow used</param>
void button::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_buttonSprite);
}

/// <summary>
/// @brief function that sets the texture of the button textures
/// </summary>
/// <param name="buttonTextureOn">texture for when button is on</param>
/// <param name="buttonTextureOff">texture for when the button is off</param>
void button::setTexture(sf::Texture const buttonTextureOn, sf::Texture const buttonTextureOff)
{
	m_buttonTexture[BUTTON_ON] = buttonTextureOn;
	m_buttonTexture[BUTTON_OFF] = buttonTextureOff;
	setUpSprite();
}

/// <summary>
/// @brief returns the sprite of the button
/// </summary>
/// <returns>button sprite</returns>
sf::Sprite button::getSprite()
{
	return m_buttonSprite;
}

/// <summary>
/// @brief checks for collision with the player and if it collides button turns on
/// </summary>
/// <param name="t_player">player in the game</param>
/// <returns>true if collides with player , else false</returns>
bool button::collsion(Player &t_player)
{
	if (!buttonOn)
	{
		if (m_buttonSprite.getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds()))
		{
			buttonOn = true;
			turnButtonOn();
		}
		else
		{
			buttonOn = false;
		}
	}
    return buttonOn;
}

/// <summary>
/// @brief sets position of the button
/// </summary>
/// <param name="t_buttonPosition">buttons new position</param>
void button::setPosition(sf::Vector2f t_buttonPosition)
{
	m_buttonPosition = t_buttonPosition;
}

/// <summary>
/// @brief sets up values for the buton sprite
/// </summary>
void button::setUpSprite()
{
	m_buttonSprite.setTexture(m_buttonTexture[BUTTON_OFF]);
	m_buttonSprite.setOrigin(m_buttonSprite.getGlobalBounds().width / 2.0f, m_buttonSprite.getGlobalBounds().height / 2.0f);
	m_buttonSprite.setPosition(m_buttonPosition);
}

/// <summary>
/// @brief changes the buttons texture to that of the button on texture
/// </summary>
void button::turnButtonOn()
{
	m_buttonSprite.setTexture(m_buttonTexture[BUTTON_ON]);
	m_buttonSprite.setOrigin(m_buttonSprite.getGlobalBounds().width / 2.0f, m_buttonSprite.getGlobalBounds().height / 2.0f);
}
