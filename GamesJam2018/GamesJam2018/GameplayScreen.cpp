#include "GameplayScreen.h"


/// <summary>
/// @brief basic constructor
/// </summary>
GameplayScreen::GameplayScreen()
{
	loadTextures();

	m_player[0].setPosition(sf::Vector2f(200, 200));
	m_player[1].setPosition(sf::Vector2f(1800, 1300));
	setWallsValues();
	m_button.setPosition(sf::Vector2f(ScreenSize::s_width * 5/8,ScreenSize::s_height));
	m_plate.setPosition(sf::Vector2f(ScreenSize::s_width * 1/8, (ScreenSize::s_height/ 2.0f) - 100));

	m_player[0].setTexture(playerTexture[0]);
	m_player[1].setTexture(playerTexture[1]);
	
	m_button.setTexture(buttonTexture[0], buttonTexture[1]);
	m_plate.setTexture(plateTexture[0], plateTexture[1]);
	m_bPhone.setTexture(m_bPhoneTexture);
	m_bPhone.setPosition(sf::Vector2f(500, 1125));
	m_bPhone.setOrigin(m_bPhone.getGlobalBounds().width / 2.0f, m_bPhone.getGlobalBounds().height / 2.0f);
	m_gPhone.setTexture(m_gPhoneTexture);
	m_gPhone.setPosition(sf::Vector2f(1500, 375));
	m_gPhone.setOrigin(m_gPhone.getGlobalBounds().width / 2.0f, m_gPhone.getGlobalBounds().height / 2.0f);


	m_winButton[0].setTexture(m_winButtonTexture);
	m_winButton[1].setTexture(m_winButtonTexture);

	m_winButton[0].setPosition(sf::Vector2f(ScreenSize::s_width * 3 / 8, (ScreenSize::s_height / 2.0f) - 300));
	m_winButton[1].setPosition(sf::Vector2f(ScreenSize::s_width * 5 / 8, (ScreenSize::s_height / 2.0f) + 100));

	m_text.setCharacterSize(64);
	m_text.setFont(m_font);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);

	m_text.setPosition(ScreenSize::s_width / 2.0f, ScreenSize::s_height / 2.0f);
	m_text.setFillColor(sf::Color::White);
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
		for (int index2 = 0; index2 < NUMBER_OF_WALLS; index2++)
		{
			if (m_player[index].collisionDetection(m_wall[index2]))
			{
				index2 = 10000;
			}
		}
	
		if (m_button.collsion(m_player[index]))
		{
			m_wall[10].setValues((wallTexture), (sf::Vector2f(15000, 11250)), (sf::Vector2f(0.05, 1.875)));

		}
	}
	m_plate.collsion(m_player[0], m_player[1]);

	// updates controller
	m_controller.update();


	if (m_plate.getPlateState())
	{
		m_wall[11].setValues((wallTexture), (sf::Vector2f(15000, 11250)), (sf::Vector2f(0.05, 1.875)));
	}
	else
	{
		m_wall[11].setValues((wallTexture), (sf::Vector2f(1500, 1125)), (sf::Vector2f(0.05, 1.875)));
	}

	if (m_winButton[0].getGlobalBounds().intersects(m_player[0].getSprite().getGlobalBounds()) && m_winButton[1].getGlobalBounds().intersects(m_player[1].getSprite().getGlobalBounds()))
	{
		m_text.setString("YOU WIN");
		m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
	}

	

}

/// <summary>
/// @brief renders objects onto the screen
/// </summary>
/// <param name="t_window">renderwindow used</param>
void GameplayScreen::render(sf::RenderWindow & t_window)
{
	for (int index = 0; index < NUMBER_OF_WALLS; index++)
	{
		m_wall[index].render(t_window);
	}
	m_button.render(t_window);
	m_plate.render(t_window);
	for (int index = 0; index < NUMBER_OF_PLAYERS; index++)
	{
		m_player[index].render(t_window);
		t_window.draw(m_winButton[index]);
	}
	t_window.draw(m_text);
	t_window.draw(m_bPhone);
	t_window.draw(m_gPhone);
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
	if (!m_font.loadFromFile("./ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "Error Loading Menu Texture" << std::endl;
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
	
	if (!m_gPhoneTexture.loadFromFile("./ASSETS/IMAGES/GirlTexture1.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;	
	}
	if (!m_bPhoneTexture.loadFromFile("./ASSETS/IMAGES/BoyTexture1.png"))
	{
		std::cout << "Error Loading Texture" << std::endl;
	}
	if (!m_winButtonTexture.loadFromFile("./ASSETS/IMAGES/Reciever.png"))
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

void GameplayScreen::setWallsValues()
{


	m_wall[0].setValues((wallTexture), (sf::Vector2f(25, 25)), (sf::Vector2f(0.125, 0.125)));
	m_wall[1].setValues((wallTexture), (sf::Vector2f(25, 1475)), (sf::Vector2f(0.125, 0.125)));
	m_wall[2].setValues((wallTexture), (sf::Vector2f(1975, 25)), (sf::Vector2f(0.125, 0.125)));
	m_wall[3].setValues((wallTexture), (sf::Vector2f(1975, 1475)), (sf::Vector2f(0.125, 0.125)));
	m_wall[4].setValues((wallTexture), (sf::Vector2f(1000, 25)), (sf::Vector2f(4.75, 0.125)));
	m_wall[5].setValues((wallTexture), (sf::Vector2f(1000, 1475)), (sf::Vector2f(4.75, 0.125)));
	m_wall[6].setValues((wallTexture), (sf::Vector2f(25, 750)), (sf::Vector2f(0.125, 3.5)));
	m_wall[7].setValues((wallTexture), (sf::Vector2f(1975, 750)), (sf::Vector2f(0.125, 3.5)));
	m_wall[8].setValues((wallTexture), (sf::Vector2f(1000, 750)), (sf::Vector2f(4.75, 0.125)));
	m_wall[9].setValues((wallTexture), (sf::Vector2f(1000, 750)), (sf::Vector2f(0.125, 3.5)));
	m_wall[10].setValues((wallTexture), (sf::Vector2f(500, 375)), (sf::Vector2f(0.05, 1.875)));
	m_wall[11].setValues((wallTexture), (sf::Vector2f(1500, 1125)), (sf::Vector2f(0.05, 1.875)));

}
