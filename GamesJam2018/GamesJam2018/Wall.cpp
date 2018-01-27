#include "Wall.h"

Wall::Wall(sf::Texture & t_wallTexture1, sf::Texture & t_wallTexture2)
	
{
	wallTexture[BOTTOM_PART] = t_wallTexture1;
	wallTexture[TOP_PART] = t_wallTexture2;
	setUpSprites();
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

void Wall::setUpSprites()
{
	wallRect[BOTTOM_PART] = { 0,0,100,50 };
	wallRect[TOP_PART] = { 0,0,90,40 };
	for (int index = 0; index < NUMBER_OF_PARTS_OF_THE_WALL; index++)
	{
		wallSprite[index].setTexture(wallTexture[index]);
		wallSprite[index].setTextureRect(wallRect[index]);
	}
}
