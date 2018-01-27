#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include <SFML\Graphics.hpp>

#include "game.h"
#include "Wall.h"
#include "Player.h"
#include "button.h"
#include "pressurePlates.h"

class Game;

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

	static const int NUMBER_OF_PLAYERS = 2;

	Player m_player[NUMBER_OF_PLAYERS];

	bool player1Active{ true };

	Controller m_controller;

	void handleControllerInput();

	sf::Texture wallSpriteSheet[2];
	sf::Texture buttonTexture[2];
	sf::Texture plateTexture[2];

	Wall m_wall;

	button m_button;
	pressurePlates m_plate;
};

#endif // !GAMEPLAYSCREEN_H