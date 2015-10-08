/*
File which defines the drop event constructor
*/

#include "DropEvent.h"

//Construct a drop event with a given wandere pointer
DropEvent::DropEvent(Wanderer *wanderer){
	Event::setType(DROP_EVENT);
	current_wanderer = wanderer;
}


Wanderer *DropEvent::getCurrentWaderer(){
	return current_wanderer;
}