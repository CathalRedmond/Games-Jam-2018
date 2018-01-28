#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include <SFML\Graphics.hpp>

#include "game.h"
#include "Wall.h"
#include "Player.h"
#include "Field.h"
#include "button.h"
#include "pressurePlates.h"

/// <summary>
/// @brief class for the gameplay screen
/// </summary>
class GameplayScreen
{
public:
	GameplayScreen();
	~GameplayScreen();

	void update();
	void render(sf::RenderWindow & t_window);
	void processEvents(sf::Event & t_event);

private:
	void loadTextures();
	void handleControllerInput();
	void setWallsValues();


	// const for the numnber of players on screen
	static const int NUMBER_OF_PLAYERS = 2;

	// instance of two players 
	Player m_player[NUMBER_OF_PLAYERS];

	// boll that determines which player is the one being controlled
	bool player1Active{ true };

	// instance of the controller used in the game
	Controller m_controller;

	// texture for the wall class
	sf::Texture wallTexture;

	// textures for the button class
	sf::Texture buttonTexture[2];

	// textures for the pressurePlate class
	sf::Texture plateTexture[2];

	// textures for the player class
	sf::Texture playerTexture[2];
	static const int NUMBER_OF_WALLS = 12;

	sf::Texture fieldTexture;

	// instance of wall class
	Wall m_wall[NUMBER_OF_WALLS];

	// instance of button class
	button m_button;

	// instance of pressure plate class
	pressurePlates m_plate;

	Field m_field;

	sf::Sprite m_winButton[2];
	sf::Texture m_winButtonTexture;
	sf::Text m_text;
	sf::Font m_font;
	sf::Sprite m_bPhone;
	sf::Sprite m_gPhone;
	sf::Texture m_bPhoneTexture;
	sf::Texture m_gPhoneTexture;
};

#endif // !GAMEPLAYSCREEN_H