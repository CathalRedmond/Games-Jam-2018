#include "menuScreen.h"



menuScreen::menuScreen(currentScreen &t_curScreen) : m_currentScreen{t_curScreen}
{
	loadTextures();
	m_menuSprite.setTexture(m_menuTextureA);
	m_menuSprite.setPosition(100, 100);
	m_timer = 0;
}


menuScreen::~menuScreen()
{
}

void menuScreen::update()
{
	if (m_timer < 550)
	{
		/// <summary>
		///  side two
		/// </summary>
		m_timer++;
	}
	if (m_timer > 300)
	{
		m_menuSprite.setTexture(m_menuTextureB);
	}
	if (m_controller.m_currentState.A && m_timer > 300)
	{
		std::cout << "TO HERE?";
		m_currentScreen = currentScreen::Gameplay;
	}
	m_controller.update();
}

void menuScreen::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_menuSprite);
}

void menuScreen::processEvents(sf::Event & t_event)
{
}

void menuScreen::loadTextures()
{
	if (!m_menuTextureA.loadFromFile("./ASSETS/IMAGES/menuTexture0.png"))
	{
		std::cout << "Error Loading Menu Texture" << std::endl;
	}
	if (!m_menuTextureB.loadFromFile("./ASSETS/IMAGES/menuTexture1.png"))
	{
		std::cout << "Error Loading Menu Texture" << std::endl;
	}
}

void menuScreen::handleControllerInput()
{
}
