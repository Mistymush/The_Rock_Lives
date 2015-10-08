/*
header file which defines the apply event class
*/

#ifndef _APPLY_EVENT_
#define _APPLY_EVENT_

#include "Event.h"
#include "Wanderer.h"

const std::string APPLY_EVENT = "ApplyEvent";

class ApplyEvent :public df::Event {

private:
	Wanderer *current_wanderer;

public:
	ApplyEvent(Wanderer *wanderer);


	Wanderer *getCurrentWaderer();
};


#endif //!_APPLY_EVENT_