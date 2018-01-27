#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "controller.h"
#include "ScreenSize.h"

class Player
{
public:
	Player();
	~Player();
	
	void update(Controller & t_controller);
	void render(sf::RenderWindow & t_window);

private:

	void calculateAngle();

	void handleControllerInput(Controller & t_controller);

	void determineDirection(Controller & t_controller);

	void movement(Controller & t_controller);

	void boundaryCheck();

	float radiansToDegrees(float t_radianAngle);
	
	sf::Vector2f m_topLeftBoundary;
	sf::Vector2f m_bottomRightBoundary;

	sf::Vector2f velocity;

	sf::Vector2f position;

	sf::Vector2f direction;


	float rotationAngle;

	sf::RectangleShape playerShape;
};


#endif // !PLAYER_H