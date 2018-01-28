
#include "Game.h"
#include <iostream>


/// <summary>
/// @brief basic constructor for the game class
/// </summary>
Game::Game() :
	m_window( sf::VideoMode{ ScreenSize::s_width, ScreenSize::s_height, 32 }, "SFML Game"),
	m_exitGame{false} //when true game will exit
{
	m_currentScreen = currentScreen::Gameplay;
	m_gameplayScreen = new GameplayScreen;
	m_menuScreen = new menuScreen(m_currentScreen);
}


Game::~Game()
{

}

/// <summary>
/// @brief main game loop
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user 
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			
			}
		}
		switch (m_currentScreen)
		{
		case currentScreen::Gameplay:
			m_gameplayScreen->processEvents(event);
			break;
		case currentScreen::MainMenu:
			m_menuScreen->processEvents(event);
			break;
		default:
			break;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	switch (m_currentScreen)
	{
	case currentScreen::Gameplay:
		m_gameplayScreen->update();
		break;
	case currentScreen::MainMenu:
		m_menuScreen->update();
		break;
	default:
		break;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	switch (m_currentScreen)
	{
	case currentScreen::Gameplay:
		m_gameplayScreen->render(m_window);
		break;
	case currentScreen::MainMenu:
		m_menuScreen->render(m_window);
		break;
	default:
		break;
	}

	m_window.display();
}

