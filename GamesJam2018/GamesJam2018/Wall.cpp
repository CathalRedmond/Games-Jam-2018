#include "Wall.h"

Wall::Wall()
	
{
	
}

Wall::~Wall()
{
}

void Wall::render(sf::RenderWindow & t_window)
{
	for (int index = 0; index < NUMBER_OF_PARTS_OF_THE_WALL; index++)
	{
		t_window.draw(wallSprite[index]);
	}
}

void Wall::setTexture(sf::Texture const & t_wallTexture1, sf::Texture const & t_wallTexture2)
{
	wallTexture[BOTTOM_PART] = t_wallTexture1;
	wallTexture[TOP_PART] = t_wallTexture2;
	setUpSprites();
}

sf::Vector2f Wall::getPosition()
{
	return wallSprite[0].getPosition();
}

sf::Sprite Wall::getSize()
{
	return wallSprite[BOTTOM_PART];
}

void Wall::setUpSprites()
{
	wallRect[BOTTOM_PART] = { 0,0,200,150 };
	wallRect[TOP_PART] = { 0,0,180,130 };
	for (int index = 0; index < NUMBER_OF_PARTS_OF_THE_WALL; index++)
	{
		wallSprite[index].setTexture(wallTexture[index]);
		wallSprite[index].setTextureRect(wallRect[index]);
		wallSprite[index].setOrigin(wallRect[index].width / 2.0f, wallRect[index].height / 2.0f);
		wallSprite[index].setPosition(200, 200);
	}
	
}
