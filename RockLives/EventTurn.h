//Event turn header
//Author: Marco Duran
#ifndef _EVENTTURN_H_
#define _EVENTTURN_H_

#include "Event.h"
#include "Object.h"


	const std::string TURN_EVENT = "df::turn";

	class EventTurn : public df::Event{
		private:
			
		public:
			
			EventTurn();
	};

#endif