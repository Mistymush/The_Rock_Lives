/*
File which definet the methods of the input manager class
*/

#include "InputManager.h"

using namespace df;

InputManager::InputManager(){
	df::Manager::setType("InputManger");
}


//Get the singleton instance of the InputManger.
InputManager &InputManager::getInstance(){
	static InputManager single;
	return single;
}


/*
Start up the input manager, requires the the graphix manager is started
*/
int InputManager::startUp(){
	LogManager &log_manager = LogManager::getInstance();
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();

	if (!graphics_manager.isStarted()){
		log_manager.WriteMessage("Error! InputManager::startup() : graphics manager was not started");
			return -1;
	}

	sf::RenderWindow *render_window = graphics_manager.getWindow();

	render_window->setKeyRepeatEnabled(false);

	Manager::startUp();
	return 0;
}

/*
shut down the input manager
*/
void InputManager::shutDown(){
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();

	sf::RenderWindow *render_window = graphics_manager.getWindow();

	render_window->setKeyRepeatEnabled(true);

	Manager::shutDown();
}

/*
Method which gets input from the sfml window
*/
void InputManager::getInput(){
	df::GameManager &game_manager = df::GameManager::getInstance();
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();
	LogManager &log_manager = LogManager::getInstance();

	sf::RenderWindow *render_window = graphics_manager.getWindow();

	sf::Event event;
	
	while (render_window->pollEvent(event)) {
		
	
		/*
		Key pressed event
		*/
		if (event.type == sf::Event::KeyPressed){
		
 			EventKeyboard *new_event = new EventKeyboard();
			new_event->setKey(convertSFMLkeyValue(event.key.code));
			new_event->setKeyboardAction(EventKeyboardAction::KEY_PRESSED);
			 

			/*Break from game loop if In testing*/
			if (new_event->getKey() == df::Keyboard::SPACE ){
				game_manager.setGameOver(true);
			}

			onEvent(new_event);

		}//end KeyPressed

		/*
		key released event
		*/
		if (event.type == sf::Event::KeyReleased){
				EventKeyboard *new_event = new EventKeyboard();
				new_event->setKey(convertSFMLkeyValue(event.key.code));
				new_event->setKeyboardAction(EventKeyboardAction::KEY_RELEASED);

				onEvent(new_event);
			}

			/*
			Mouse moved event
			*/
			if (event.type == sf::Event::MouseMoved){
				
				EventMouse *new_event = new EventMouse();
				new_event->setMouseAction(df::MOVED);
				new_event->setMousePosition(graphics_manager.pixelsToSpaces(Position(event.mouseMove.x, event.mouseMove.y)));

				onEvent(new_event);
			}

			/*
			Button clickerd event
			*/
			if (event.type == sf::Event::MouseButtonPressed){
				EventMouse *new_event = new EventMouse();
				new_event->setMouseAction(df::CLICKED);
				new_event->setMousePosition(graphics_manager.pixelsToSpaces(Position(event.mouseButton.x, event.mouseButton.y)));
				new_event->setMouseButton(convertSFMLouseButtonValue(event.mouseButton.button));

				onEvent(new_event);
			}

	}//end while pool

	//Check if any keys are currently pressed
	for (int i = sf::Keyboard::Key::Unknown; i < sf::Keyboard::Key::KeyCount; i++) {

		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i)) {

			EventKeyboard *new_event = new EventKeyboard();
			new_event->setKey(convertSFMLkeyValue((sf::Keyboard::Key)i));
			new_event->setKeyboardAction(EventKeyboardAction::KEY_DOWN);

			onEvent(new_event);

		}

	}//end key pressed check


	//Check if any mouse buttons are currently pressed
	for (int i = sf::Mouse::Button::Left; i < sf::Mouse::Button::ButtonCount; i++) {

		if (sf::Mouse::isButtonPressed((sf::Mouse::Button)i)) {

			EventMouse *new_event = new EventMouse();

			//Set mouse attributes

			new_event->setMousePosition(graphics_manager.pixelsToSpaces(Position::Position(event.mouseButton.x, event.mouseButton.y)));
			new_event->setMouseAction(EventMouseAction::PRESSED);
			new_event->setMouseButton(convertSFMLouseButtonValue(event.mouseButton.button));

			//Send event to all objects
			onEvent(new_event);

		}

	}//end mouse button pressed check


}//end getInput

//Converter funtion, this funtion is a massive switch statement
df::Keyboard::Key InputManager::convertSFMLkeyValue(sf::Keyboard::Key key){
	switch (key) {

	case sf::Keyboard::Key::A:

		return Keyboard::Key::A;

		break;

	case sf::Keyboard::Key::B:

		return Keyboard::Key::B;

		break;

	case sf::Keyboard::Key::C:

		return Keyboard::Key::C;

		break;

	case sf::Keyboard::Key::D:

		return Keyboard::Key::D;

		break;

	case sf::Keyboard::Key::F:

		return Keyboard::Key::F;

		break;

	case sf::Keyboard::Key::G:

		return Keyboard::Key::G;

		break;

	case sf::Keyboard::Key::H:

		return Keyboard::Key::H;

		break;

	case sf::Keyboard::Key::I:

		return Keyboard::Key::I;

		break;

	case sf::Keyboard::Key::J:

		return Keyboard::Key::J;

		break;

	case sf::Keyboard::Key::K:

		return Keyboard::Key::K;

		break;

	case sf::Keyboard::Key::L:

		return Keyboard::Key::L;

		break;

	case sf::Keyboard::Key::M:

		return Keyboard::Key::M;

		break;

	case sf::Keyboard::Key::N:

		return Keyboard::Key::N;

		break;

	case sf::Keyboard::Key::O:

		return Keyboard::Key::O;

		break;

	case sf::Keyboard::Key::P:

		return Keyboard::Key::P;

		break;

	case sf::Keyboard::Key::Q:

		return Keyboard::Key::Q;

		break;

	case sf::Keyboard::Key::R:

		return Keyboard::Key::R;

		break;

	case sf::Keyboard::Key::S:

		return Keyboard::Key::S;

		break;

	case sf::Keyboard::Key::T:

		return Keyboard::Key::T;

		break;

	case sf::Keyboard::Key::U:

		return Keyboard::Key::U;

		break;

	case sf::Keyboard::Key::V:

		return Keyboard::Key::V;

		break;

	case sf::Keyboard::Key::W:

		return Keyboard::Key::W;

		break;

	case sf::Keyboard::Key::X:

		return Keyboard::Key::X;

		break;

	case sf::Keyboard::Key::Y:

		return Keyboard::Key::Y;

		break;

	case sf::Keyboard::Key::Z:

		return Keyboard::Key::Z;

		break;

	case sf::Keyboard::Key::Num0:

		return Keyboard::Key::NUM0;

		break;

	case sf::Keyboard::Key::Num1:

		return Keyboard::Key::NUM1;

		break;

	case sf::Keyboard::Key::Num2:

		return Keyboard::Key::NUM2;

		break;

	case sf::Keyboard::Key::Num3:

		return Keyboard::Key::NUM3;

		break;

	case sf::Keyboard::Key::Num4:

		return Keyboard::Key::NUM4;

		break;

	case sf::Keyboard::Key::Num5:

		return Keyboard::Key::NUM5;

		break;

	case sf::Keyboard::Key::Num6:

		return Keyboard::Key::NUM6;

		break;

	case sf::Keyboard::Key::Num7:

		return Keyboard::Key::NUM7;

		break;

	case sf::Keyboard::Key::Num8:

		return Keyboard::Key::NUM8;

		break;

	case sf::Keyboard::Key::Num9:

		return Keyboard::Key::NUM9;

		break;

	case sf::Keyboard::Key::Space:

		return Keyboard::Key::SPACE;

		break;

	case sf::Keyboard::Key::Return:

		return Keyboard::Key::RETURN;

		break;

	case sf::Keyboard::Key::Escape:

		return Keyboard::Key::ESCAPE;

		break;

	case sf::Keyboard::Key::Tab:

		return Keyboard::Key::TAB;

		break;

	case sf::Keyboard::Key::Left:

		return Keyboard::Key::LEFTARROW;

		break;

	case sf::Keyboard::Key::Right:

		return Keyboard::Key::RIGHTARROW;

		break;

	case sf::Keyboard::Key::Up:

		return Keyboard::Key::UPARROW;

		break;

	case sf::Keyboard::Key::Down:

		return Keyboard::Key::DOWNARROW;

		break;

	case sf::Keyboard::Key::Pause:

		return Keyboard::Key::PAUSE;

		break;

	case sf::Keyboard::Key::Subtract:

		return Keyboard::Key::MINUS;

		break;

	case sf::Keyboard::Key::Add:

		return Keyboard::Key::PLUS;

		break;

	case sf::Keyboard::Key::Tilde:

		return Keyboard::Key::TILDE;

		break;

	case sf::Keyboard::Key::Period:

		return Keyboard::Key::PERIOD;

		break;

	case sf::Keyboard::Key::Comma:

		return Keyboard::Key::COMMA;

		break;

	case sf::Keyboard::Key::Slash:

		return Keyboard::Key::SLASH;

		break;

	case sf::Keyboard::Key::LControl:

		return Keyboard::Key::LEFTCONTROL;

		break;

	case sf::Keyboard::Key::RControl:

		return Keyboard::Key::RIGHTCONTROL;

		break;

	case sf::Keyboard::Key::LShift:

		return Keyboard::Key::LEFTSHIFT;

		break;

	case sf::Keyboard::Key::RShift:

		return Keyboard::Key::RIGHTSHIFT;

		break;

	case sf::Keyboard::Key::F1:

		return Keyboard::Key::F1;

		break;

	case sf::Keyboard::Key::F2:

		return Keyboard::Key::F2;

		break;

	case sf::Keyboard::Key::F3:

		return Keyboard::Key::F3;

		break;

	case sf::Keyboard::Key::F4:

		return Keyboard::Key::F4;

		break;

	case sf::Keyboard::Key::F5:

		return Keyboard::Key::F5;

		break;

	case sf::Keyboard::Key::F6:

		return Keyboard::Key::F6;

		break;

	case sf::Keyboard::Key::F7:

		return Keyboard::Key::F7;

		break;

	case sf::Keyboard::Key::F8:

		return Keyboard::Key::F8;

		break;

	case sf::Keyboard::Key::F9:

		return Keyboard::Key::F9;

		break;

	case sf::Keyboard::Key::F10:

		return Keyboard::Key::F10;

		break;

	case sf::Keyboard::Key::F11:

		return Keyboard::Key::F11;

		break;

	case sf::Keyboard::Key::F12:

		return Keyboard::Key::F12;

		break;

	default:

		return Keyboard::Key::UNDEFINED_KEY;

		break;

	}
}


//Button converter, this funtion is a slightly less massive switch funtion
df::EventMouseButton InputManager::convertSFMLouseButtonValue(sf::Mouse::Button button){
	switch (button) {

	case sf::Mouse::Button::Left:

		return EventMouseButton::LEFT;

		break;

	case sf::Mouse::Button::Right:

		return EventMouseButton::RIGHT;

		break;

	case sf::Mouse::Button::Middle:

		return EventMouseButton::MIDDLE;

		break;

	default:

		return EventMouseButton::UNDEFINED_MOUSE_BUTTON;

		break;

	}
}