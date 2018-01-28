#include "menuScreen.h"



menuScreen::menuScreen(currentScreen &t_curScreen) : m_currentScreen{t_curScreen}
{
	loadTexturesAndFonts();
	m_menuSprite.setTexture(m_menuTextureA);
	m_menuSprite.setPosition(ScreenSize::s_width / 2.0f,ScreenSize::s_height / 2.0f);
	m_menuSprite.setOrigin(m_menuSprite.getGlobalBounds().width / 2.0f, m_menuSprite.getGlobalBounds().height / 2.0f);

	m_text.setCharacterSize(64);
	m_text.setFont(m_font);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);

	m_text.setPosition(ScreenSize::s_width / 2.0f, ScreenSize::s_height / 2.0f);
	m_text.setFillColor(sf::Color::White);
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
		m_text.setString("PRESS A TO PLAY");
		m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);

	}
	if (m_controller.m_currentState.A && m_timer > 300)
	{
		m_currentScreen = currentScreen::Gameplay;
	}
	m_controller.update();
}

void menuScreen::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_menuSprite);
	t_window.draw(m_text);
}

void menuScreen::processEvents(sf::Event & t_event)
{
}

void menuScreen::loadTexturesAndFonts()
{
	if (!m_menuTextureA.loadFromFile("./ASSETS/IMAGES/menuTexture00.png"))
	{
		std::cout << "Error Loading Menu Texture" << std::endl;
	}
	if (!m_menuTextureB.loadFromFile("./ASSETS/IMAGES/menuTexture10.png"))
	{
		std::cout << "Error Loading Menu Texture" << std::endl;
	}
	if (!m_font.loadFromFile("./ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "Error Loading Menu Texture" << std::endl;
	}
}

void menuScreen::handleControllerInput()
{
}
