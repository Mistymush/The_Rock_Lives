/*
File which defines the eventKeyboard methods
*/

#include "EventKeyboard.h"

using namespace df;

//public constructor
EventKeyboard::EventKeyboard(){

	//our defined set of keys
	key_val = Keyboard::UNDEFINED_KEY;

	//catagory of keyboard event
	keyboard_action = UNDEFINED_KEYBOARD_ACTION;

	Event::setType(df::_KEYBOARD_EVENT);
}

//getters and setters
void EventKeyboard::setKey(df::Keyboard::Key new_key){
	key_val = new_key;
}

//Get key from event
Keyboard::Key EventKeyboard::getKey() const{
	return key_val;
}

//Get keyboard event action. To be used by the InputManager only!
void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action){
	keyboard_action = new_action;
}

//Get keybaord event action
EventKeyboardAction EventKeyboard::getKeyboardAction() const{
	return keyboard_action;
}