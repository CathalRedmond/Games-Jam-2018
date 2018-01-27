#include "GameplayScreen.h"



GameplayScreen::GameplayScreen()
{

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
	m_controller.update();
	handleControllerInput();
}

void GameplayScreen::render(sf::RenderWindow & t_window)
{
	for (int index = 0; index < NUMBER_OF_PLAYERS; index++)
	{
		m_player[index].render(t_window);
	}
}

void GameplayScreen::processEvents(sf::Event & t_event)
{
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
