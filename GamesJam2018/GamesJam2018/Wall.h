#ifndef WALL_H
#define WALL_H

#include <SFML\graphics.hpp>



class Wall
{
public:
	Wall(sf::Texture & t_wallTexture1, sf::Texture & t_wallTexture2);
	~Wall();
	void render(sf::RenderWindow & t_window);

private:
	void setUpSprites();

	static const int NUMBER_OF_PARTS_OF_THE_WALL = 2;


	sf::Sprite wallSprite[NUMBER_OF_PARTS_OF_THE_WALL];

	sf::Texture wallTexture[NUMBER_OF_PARTS_OF_THE_WALL];

	sf::IntRect wallRect[NUMBER_OF_PARTS_OF_THE_WALL];

	static const int TOP_PART = 1;
	static const int BOTTOM_PART = 2;


	sf::Vector2f wallSize;
	sf::Vector2f wallPosition;      

};

#endif // !WALL_H