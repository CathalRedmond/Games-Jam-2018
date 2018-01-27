#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "Enums.h"
#include "GameplayScreen.h"
#include "menuScreen.h"


class GameplayScreen;
class menuScreen;

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
	
	currentScreen m_currentScreen;

	GameplayScreen *m_gameplayScreen;

	menuScreen *m_menuScreen;

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME

