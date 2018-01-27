#include "pressurePlates.h"



pressurePlates::pressurePlates()
{
}


pressurePlates::~pressurePlates()
{
}

void pressurePlates::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_plateSprite);
}

void pressurePlates::setTexture(sf::Texture const plateTextureOn, sf::Texture const plateTextureOff)
{
	m_plateTexture[PLATE_ON] = plateTextureOn;
	m_plateTexture[PLATE_OFF] = plateTextureOff;
	setUpSprites();
}

sf::Sprite pressurePlates::getSprite()
{
	return m_plateSprite;
}

void pressurePlates::collsion(Player & t_player, Player & t_player2)
{
	if ((m_plateSprite.getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds())) || (m_plateSprite.getGlobalBounds().intersects(t_player2.getSprite().getGlobalBounds())))
	{
		m_plateSprite.setTexture(m_plateTexture[PLATE_ON]);
		m_plateSprite.setOrigin(m_plateSprite.getGlobalBounds().width / 2.0f, m_plateSprite.getGlobalBounds().height / 2.0f);
		m_plateSprite.setPosition(1500, 600);
	}
	if ((!m_plateSprite.getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds())) && (!m_plateSprite.getGlobalBounds().intersects(t_player2.getSprite().getGlobalBounds())))
	{
		m_plateSprite.setTexture(m_plateTexture[PLATE_OFF]);
		m_plateSprite.setOrigin(m_plateSprite.getGlobalBounds().width / 2.0f, m_plateSprite.getGlobalBounds().height / 2.0f);
		m_plateSprite.setPosition(1500, 600);
	}
}

bool pressurePlates::getState()
{
	return plateOn;
}

void pressurePlates::setUpSprites()
{
	m_plateSprite.setTexture(m_plateTexture[PLATE_OFF]);
	m_plateSprite.setOrigin(m_plateSprite.getGlobalBounds().width / 2.0f, m_plateSprite.getGlobalBounds().height / 2.0f);
	m_plateSprite.setPosition(1000, 200);
}

