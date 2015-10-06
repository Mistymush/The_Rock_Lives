/*
Header file which defines the Out of Bounds event
*/

#ifndef EVENT_OUT
#define EVENT_OUT

#include "Event.h"
namespace df{


	const std::string OUT_EVENT = "df::out";

	class EventOut :public Event {

	public:
		EventOut();

	};

}// !df

#endif //!EVENT_OUT


