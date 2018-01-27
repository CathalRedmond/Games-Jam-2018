#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "controller.h"
#include "ScreenSize.h"
#include "Wall.h"

class Player
{
public:
	Player();
	~Player();
	
	void update(Controller & t_controller);
	void render(sf::RenderWindow & t_window);

	void collisionDetection(Wall & m_wall);
private:

	void calculateAngle();

	void handleControllerInput(Controller & t_controller);

	void determineDirection(Controller & t_controller);

	void movement(Controller & t_controller);

	void boundaryCheck();
	sf::Vector2f previousePosition;

	float radiansToDegrees(float t_radianAngle);
	
	sf::Vector2f m_topLeftBoundary;
	sf::Vector2f m_bottomRightBoundary;

	sf::Vector2f velocity;

	sf::Vector2f position;

	sf::Vector2f direction;

	bool hit{ false };
	float rotationAngle;

	sf::RectangleShape playerShape;
};


#endif // !PLAYER_H