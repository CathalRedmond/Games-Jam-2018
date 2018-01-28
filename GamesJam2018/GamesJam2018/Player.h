#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "controller.h"
#include "ScreenSize.h"
#include "Wall.h"

/// <summary>
/// @brief player class
/// </summary>
class Player
{
public:
	Player();
	~Player();
	void setTexture(sf::Texture &  t_playerTexture);
	void update(Controller & t_controller);
	void render(sf::RenderWindow & t_window);
	sf::Sprite getSprite();
	bool collisionDetection(Wall & t_wall);
	void setPosition(sf::Vector2f t_playerPosition);
private:
	void calculateAngle();
	void handleControllerInput(Controller & t_controller);
	void determineDirection(Controller & t_controller);
	void movement(Controller & t_controller);
	void setUpSprite();
	float radiansToDegrees(float t_radianAngle);

	// previous position of the player - used for when player collides with wall
	sf::Vector2f m_previousPosition;

	// velocity of the player
	sf::Vector2f m_velocity;

	// position of the player
	sf::Vector2f m_position;

	// direction player is facing
	sf::Vector2f m_direction;

	// bool for if the player has collide with a wall
	bool m_hit{ false };
	
	// angle player sprite is facing
	float m_rotationAngle;

	// player sprite
	sf::Sprite m_playerSprite;

	// player texture
	sf::Texture  m_playerTexture;
};


#endif // !PLAYER_H