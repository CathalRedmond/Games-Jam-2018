#include "Player.h"

/// <summary>
/// @brief basic constructor for the game
/// </summary>
Player::Player()
{
}

Player::Player(sf::Vector2f t_playerSpawn)
{
	m_spawnPoint = t_playerSpawn;
	m_position = m_spawnPoint;
}

/// <summary>
/// @brief basic destructor for the game
/// </summary>
Player::~Player()
{
}

/// <summary>
/// @brief sets the texture of the player
/// </summary>
/// <param name="t_playerTexture">player texture</param>
void Player::setTexture(sf::Texture &  t_playerTexture)
{
	m_playerTexture = t_playerTexture;
	setUpSprite();

}

/// <summary>
/// @brief update function for the player
/// </summary>
/// <param name="t_controller">controller in the game</param>
void Player::update(Controller & t_controller)
{
	handleControllerInput(t_controller);

	movement(t_controller);
	
	// moves normal if not touching wall
	if (!m_hit)
	{
		m_previousPosition = m_position;
		m_position += m_velocity;
		
	}
	else	// if touching wall player position changes to previous position
	{
		
		m_position = m_previousPosition;
	}


	m_playerSprite.setPosition(m_position);
	m_playerSprite.setRotation(m_rotationAngle);
}

/// <summary>
/// @brief renders player sprite onto screen
/// </summary>
/// <param name="t_window">renderwindow used on screen</param>
void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_playerSprite);
}

/// <summary>
/// @brief returns player sprite
/// </summary>
/// <returns>player sprite</returns>
sf::Sprite Player::getSprite()
{
	return (m_playerSprite);
}

/// <summary>
/// @brief checks for collsion between player and wall
/// </summary>
/// <param name="m_wall">wall in the game</param>
bool Player::collisionDetection(Wall & m_wall)
{
	if (m_playerSprite.getGlobalBounds().intersects(m_wall.getShape().getGlobalBounds()))
	{
		m_hit = true;
	}
	else
	{
		m_hit = false; 
	}
	return m_hit;
}

void Player::collisionDetection(Field & t_field)
{

	if (m_playerSprite.getGlobalBounds().intersects(t_field.getSprite().getGlobalBounds()))
	{
		m_position = m_spawnPoint;
	}
}

/// <summary>
/// @brief sets player position
/// </summary>
/// <param name="t_playerPosition">new position of player</param>
void Player::setPosition(sf::Vector2f t_playerPosition)
{
	m_position = t_playerPosition;
	m_previousPosition = m_position;
}

void Player::setSpawn(sf::Vector2f t_playerSpawn)
{
	m_spawnPoint = t_playerSpawn;
	m_position = m_spawnPoint;
}


/// <summary>
/// @brief calculates angle from direction
/// </summary>
void Player::calculateAngle()
{
	// prevents division by zero later on
	if (m_direction.x == 0)
	{
		if (m_direction.y > 0)
		{
			m_rotationAngle = 90;
		}
		else
		{
			m_rotationAngle = 270;
		}
	}
	else
	{
		bool negativeAngle = false; // checks if angle is negative and helps to output corresponding positive angle
		if (m_direction.x < 0)
		{
			negativeAngle = true;
		}
		m_rotationAngle = atan((m_direction.y / m_direction.x));

		m_rotationAngle = radiansToDegrees(m_rotationAngle);

		if (negativeAngle)
		{
			m_rotationAngle += 180;
		}
	}
}

/// <summary>
/// @ brief  handles controller input
/// </summary>
/// <param name="t_controller">controller in the game</param>
void Player::handleControllerInput(Controller & t_controller)
{
	determineDirection(t_controller);
}

/// <summary>
/// @brief gets direction of player based on movement of the left thumb stick
/// </summary>
/// <param name="t_controller">controller in the game</param>
void Player::determineDirection(Controller & t_controller)
{
	m_direction = sf::Vector2f(t_controller.m_currentState.LeftThumbStick.x * (90.0f/100), t_controller.m_currentState.LeftThumbStick.y* (90.0f / 100));
	calculateAngle();
}

/// <summary>
/// @brief sets velocity of player based on velocity
/// </summary>
/// <param name="t_controller">controller in the game</param>
void Player::movement(Controller & t_controller)
{
	if (t_controller.m_currentState.RTrigger > 50)
	{
		m_velocity = m_direction / 10.0f;
	}
	else
	{
		m_velocity = sf::Vector2f(0.0, 0.0);
	}
}


/// <summary>
/// @brief sets up sprite used for the player
/// </summary>
void Player::setUpSprite()
{
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2.0f, m_playerSprite.getGlobalBounds().height / 2.0f);
	m_playerSprite.setPosition(m_position);
}

/// <summary>
/// @brief converts radians value to degrees
/// </summary>
/// <param name="t_radianAngle">angle in radians</param>
/// <returns>angle in degrees</returns>
float Player::radiansToDegrees(float t_radianAngle)
{
	return (t_radianAngle * (180.0f/ acos(-1.0f)));
}
