/*
File which defines the apply event constructor
*/

#include "ApplyEvent.h"

//Construct a drop event with a given wandere pointer
ApplyEvent::ApplyEvent(Wanderer *wanderer){
	df::Event::setType(APPLY_EVENT);
	current_wanderer = wanderer;
}


Wanderer *ApplyEvent::getCurrentWaderer(){
	return current_wanderer;
}