



#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include<SFML\Graphics.hpp>


/// <summary>
/// data to store current state of controller
/// </summary>
struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadLeft;
	bool DpadRight;
	bool LeftThumbStickUp;
	bool LeftThumbStickDown;
	bool LeftThumbStickLeft;
	bool LeftThumbStickRight;
	bool RightThumbStickUp;
	bool RightThumbStickDown;
	bool RightThumbStickLeft;
	bool RightThumbStickRight;
	bool Start;
	bool Back;
	bool Xbox;
	float RTrigger;
	float LTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

/// <summary>
/// Xbox contoller class to query current state of controller
/// </summary>
class Controller
{
private:
	// deadzone for the dpad
	const int dpadThreshold = 50;
public:
	// index count for multiple controllers if connected
	int sf_Joystick_index;
	// the current state of all the buttons
	GamePadState m_currentState;
	// the previous state to use to check for the moment a button is pressed
	GamePadState m_previousState;

	Controller();
	~Controller();
	void Controller::update();
	bool isConnected();
	bool connect();

};


#endif // !CONTROLLER