/*
File which defines methods for the event object
*/
#include "Event.h"

using namespace df;


/*
Constructor for an event, initializes to undefined event
*/
Event::Event(){
	event_type = UNDEFINED_EVENT;
}

/*
Desconstructor for an event
*/
Event::~Event(){


}

void Event::setType(std::string new_type){
	event_type = new_type;
}

std::string Event::getType() const{
	return event_type;
}
