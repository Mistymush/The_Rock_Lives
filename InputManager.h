/*
Header file which define the input manager class
*/

#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "Manager.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "EventMouse.h"


namespace df{

	class InputManager : public Manager{

	private:
		//Singleton behaivior
		InputManager();
		InputManager(InputManager const&);
		void operator=(InputManager const&);

	public:
		//Get the instanc of the game manager
		static InputManager &getInstance();

		//Get terminal ready to capture input
		int startUp();

		//revert to normal terminl mode
		void shutDown();

		//Getinput from the keyboard and mouse
		//pass event along to all objects
		void getInput();

		//Inpur manager utility function for dealing with key value conversions
		df::Keyboard::Key convertSFMLkeyValue(sf::Keyboard::Key key);

		//Inpur manager utility function for dealing with mouse button value conversions
		df::EventMouseButton convertSFMLouseButtonValue(sf::Mouse::Button b);

	};

}// !df

#endif // !INPUT_MANAGER
