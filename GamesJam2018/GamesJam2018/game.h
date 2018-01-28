#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "GameplayScreen.h"
#include "menuScreen.h"
#include "Enums.h"


// forward referncing
class GameplayScreen;
class menuScreen;

/// <summary>
/// @brief class for the game
/// </summary>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	// current screen the game is in
	currentScreen m_currentScreen;

	// instance of the gameplay screen in the game
	GameplayScreen *m_gameplayScreen;

	// instance of the menu screen in the game
	menuScreen *m_menuScreen;

	// main SFML window
	sf::RenderWindow m_window; 

	// control exiting game
	bool m_exitGame; 

};

#endif // !GAME

