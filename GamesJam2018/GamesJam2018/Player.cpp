#include "Player.h"






Player::Player()
{
	position = sf::Vector2f(ScreenSize::s_width / 2.0f, ScreenSize::s_width / 2.0f);
	playerShape.setSize(sf::Vector2f(100, 100));
	playerShape.setFillColor(sf::Color::Cyan);
	playerShape.setOrigin(playerShape.getGlobalBounds().width / 2.0f, playerShape.getGlobalBounds().height / 2.0f);
	playerShape.setPosition(position);
}

Player::~Player()
{
}

void Player::update(Controller & t_controller)
{
	handleControllerInput(t_controller);

	movement(t_controller);

	position += velocity;
	boundaryCheck();

	playerShape.setPosition(position);
	playerShape.setRotation(rotationAngle);


}

void Player::render(sf::RenderWindow & t_window)
{

	t_window.draw(playerShape);
}






void Player::calculateAngle()
{
	if (direction.x == 0)
	{
		if (direction.y > 0)
		{
			rotationAngle = 90;
		}
		else
		{
			rotationAngle = 270;
		}
	}
	else
	{
		bool negativeAngle = false;
		if (direction.x < 0)
		{
			negativeAngle = true;
		}
		rotationAngle = atan((direction.y / direction.x));

		rotationAngle = radiansToDegrees(rotationAngle);

		if (negativeAngle)
		{
			rotationAngle += 180;
		}
	}
}

void Player::handleControllerInput(Controller & t_controller)
{
	determineDirection(t_controller);
}

void Player::determineDirection(Controller & t_controller)
{
	direction = sf::Vector2f(t_controller.m_currentState.LeftThumbStick.x * (90.0f/100), t_controller.m_currentState.LeftThumbStick.y* (90.0f / 100));
	calculateAngle();
}

void Player::movement(Controller & t_controller)
{
	if (t_controller.m_currentState.RTrigger > 50)
	{
		velocity = direction / 10.0f;
	}
	else
	{
		velocity = sf::Vector2f(0.0, 0.0);
	}
}

void Player::boundaryCheck()
{

}

float Player::radiansToDegrees(float t_radianAngle)
{
	return (t_radianAngle * (180.0f/ acos(-1.0f)));
}
