#include "GameplayScreen.h"



GameplayScreen::GameplayScreen()
{
	loadTextures();
	m_wall.setTexture(wallSpriteSheet[0], wallSpriteSheet[1]);
	m_button.setTexture(buttonTexture[0], buttonTexture[1]);
	m_plate.setTexture(plateTexture[0], plateTexture[1]);
}


GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::update()
{
	if (player1Active)
	{
		m_player[0].update(m_controller);
	}
	else
	{
		m_player[1].update(m_controller);

	}

	for (int index = 0; index < NUMBER_OF_PLAYERS; index++)
	{
		m_player[index].collisionDetection(m_wall);
		m_button.collsion(m_player[index]);

	}
	m_controller.update();
	m_plate.collsion(m_player[0], m_player[1]);

	handleControllerInput();
}

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

void GameplayScreen::processEvents(sf::Event & t_event)
{
}

void GameplayScreen::loadTextures()
{
	if (!wallSpriteSheet[0].loadFromFile("./ASSETS/IMAGES/wall1.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}
	if (!wallSpriteSheet[1].loadFromFile("./ASSETS/IMAGES/wall2.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	} 

	if (!buttonTexture[0].loadFromFile("./ASSETS/IMAGES/SwitchOn.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}
	if (!buttonTexture[1].loadFromFile("./ASSETS/IMAGES/SwitchOff.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}


	if (!plateTexture[0].loadFromFile("./ASSETS/IMAGES/PadOn.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}
	if (!plateTexture[1].loadFromFile("./ASSETS/IMAGES/PadOff.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}
}

void GameplayScreen::handleControllerInput()
{
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
