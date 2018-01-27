#include "button.h"



button::button()
{
}


button::~button()
{
}

void button::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_buttonSprite);
}

void button::setTexture(sf::Texture const buttonTextureOn, sf::Texture const buttonTextureOff)
{
	m_buttonTexture[BUTTON_ON] = buttonTextureOn;
	m_buttonTexture[BUTTON_OFF] = buttonTextureOff;
	setUpSprite();
}

sf::Sprite button::getSprite()
{
	return m_buttonSprite;
}

bool button::collsion(Player &t_player)
{
	if (!buttonOn)
	{
		if (m_buttonSprite.getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds()))
		{
			std::cout << "BUTTON" << std::endl;
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

void button::setUpSprite()
{
	m_buttonSprite.setTexture(m_buttonTexture[BUTTON_OFF]);
	m_buttonSprite.setOrigin(m_buttonSprite.getGlobalBounds().width / 2.0f, m_buttonSprite.getGlobalBounds().height / 2.0f);
	m_buttonSprite.setScale(0.3f, 0.3f);
	m_buttonSprite.setPosition(1000, 200);
}

void button::turnButtonOn()
{

	m_buttonSprite.setTexture(m_buttonTexture[BUTTON_ON]);
	m_buttonSprite.setOrigin(m_buttonSprite.getGlobalBounds().width / 2.0f, m_buttonSprite.getGlobalBounds().height / 2.0f);
	m_buttonSprite.setPosition(1000, 200);

}
