/*
File which defines the drop event constructor
*/

#include "DropEvent.h"

DropEvent::DropEvent(Wanderer *wanderer){
	Event::setType(DROP_EVENT);
	current_wanderer = wanderer;
}

Wanderer *DropEvent::getCurrentWaderer(){
	return current_wanderer;
}