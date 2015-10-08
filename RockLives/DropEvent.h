/*
head file which defines a drop event class
*/

#ifndef _DROP_EVENT_
#define _DROP_EVENT_

#include "Event.h"
#include "Wanderer.h"

const std::string DROP_EVENT = "DropEvent";

class DropEvent :public df::Event {

private:
	Wanderer *current_wanderer;

public:
		DropEvent(Wanderer *wanderer);

		Wanderer *getCurrentWaderer();
};


#endif //!EVENT_OUT