#include "Field.h"



Field::Field()
{
}


Field::~Field()
{
}

void Field::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_fieldSprite);
}

void Field::setTexture(sf::Texture const & t_fieldTexture)
{
	m_fieldTexture = t_fieldTexture;
	setUpSprites();
}

sf::Sprite Field::getSprite()
{
	return m_fieldSprite;
}

void Field::setPosition(sf::Vector2f t_fieldPosition)
{
	m_fieldPosition = t_fieldPosition;
	m_fieldSprite.setPosition(m_fieldPosition);
}

void Field::setScale(float x, float y)
{
	m_fieldSprite.setScale(sf::Vector2f(x, y));
}

void Field::setUpSprites()
{
	m_fieldSprite.setTexture(m_fieldTexture);
	m_fieldSprite.setPosition(m_fieldPosition);
}





