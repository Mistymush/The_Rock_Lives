/*
File which defines EventMouse mehtods
*/

#include "EventMouse.h"

using namespace df;

//default constructor
EventMouse::EventMouse(){
	mouse_action = UNDEFINED_MOUSE_ACTION;

	mouse_button = UNDEFINED_MOUSE_BUTTON;

	Event::setType(df::_MOUSE_EVENT);
}

//getters and setters
void EventMouse::setMouseAction(EventMouseAction new_mouse_action){
	mouse_action = new_mouse_action;
}

EventMouseAction EventMouse::getMouseAction() const{
	return  mouse_action;
}

void EventMouse::setMouseButton(EventMouseButton new_mouse_button){
	mouse_button = new_mouse_button;
}

EventMouseButton EventMouse::getMouseButton() const{
	return mouse_button;
}

void EventMouse::setMousePosition(Position new_mouse_xy){
	mouse_xy = new_mouse_xy;
}

Position EventMouse::getMousePosition() const{
	return mouse_xy;
}