#include "GameplayScreen.h"


/// <summary>
/// @brief basic constructor
/// </summary>
GameplayScreen::GameplayScreen()
{
	loadTextures();

	m_player[0].setSpawn(sf::Vector2f(900, 1100));
	m_player[1].setPosition(sf::Vector2f(1100, 1100));
	m_wall.setPosition(sf::Vector2f(200,200));
	m_button.setPosition(sf::Vector2f(1000,200));
	m_plate.setPosition(sf::Vector2f(1500, 200));

	m_player[0].setTexture(playerTexture[0]);
	m_player[1].setTexture(playerTexture[1]);
	m_wall.setTexture(wallTexture);
	m_button.setTexture(buttonTexture[0], buttonTexture[1]);
	m_plate.setTexture(plateTexture[0], plateTexture[1]);
}

/// <summary>
/// @brief basic destructor
/// </summary>
GameplayScreen::~GameplayScreen()
{
}

/// <summary>
/// @breif update function of the class
/// </summary>
void GameplayScreen::update()
{
	// only moves the player that is active
	if (player1Active)
	{
		m_player[0].update(m_controller);
	}
	else
	{
		m_player[1].update(m_controller);

	}
	// checks for collision between players and objects
	for (int index = 0; index < NUMBER_OF_PLAYERS; index++)
	{
		m_player[index].collisionDetection(m_wall);
		m_button.collsion(m_player[index]);
	}
	m_plate.collsion(m_player[0], m_player[1]);

	// updates controller
	m_controller.update();

}

/// <summary>
/// @brief renders objects onto the screen
/// </summary>
/// <param name="t_window">renderwindow used</param>
void GameplayScreen::render(sf::RenderWindow & t_window)
{
	m_button.render(t_window);
	m_plate.render(t_window);
	for (int index = 0; index < NUMBER_OF_PLAYERS; index++)
	{
		m_player[index].render(t_window);
	}
	m_wall.render(t_window);
}

/// <summary>
/// @brief process events 
/// </summary>
/// <param name="t_event">sf::event</param>
void GameplayScreen::processEvents(sf::Event & t_event)
{
	handleControllerInput();
}

/// <summary>
/// @brief loads textures into the game
/// </summary>
void GameplayScreen::loadTextures()
{
	if (!wallTexture.loadFromFile("./ASSETS/IMAGES/WallsTextureSmall.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}

	if (!buttonTexture[1].loadFromFile("./ASSETS/IMAGES/SwitchOffEmpty.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}

	if(!buttonTexture[0].loadFromFile("./ASSETS/IMAGES/SwitchOnEmpty.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}

	if (!plateTexture[0].loadFromFile("./ASSETS/IMAGES/PadOnEmpty.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}

	if (!plateTexture[1].loadFromFile("./ASSETS/IMAGES/PadOffEmpty.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}

	if (!playerTexture[0].loadFromFile("./ASSETS/IMAGES/ManEmpty.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}

	if (!playerTexture[1].loadFromFile("./ASSETS/IMAGES/WomanEmpty.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}
}

/// <summary>
/// @brief function that handles input from the controller
/// </summary>
void GameplayScreen::handleControllerInput()
{
	// when 'A' is pressed on the controller switches which player is active
	if (m_controller.m_currentState.A)
	{
		if (player1Active)
		{
			player1Active = false;
		}
		else
		{
			player1Active = true;
		}
	}
}
