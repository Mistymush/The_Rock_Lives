/*
Header file which define a mouse event
*/

#ifndef EVENT_MOUSE
#define EVENT_MOUSE

#include <SFML/graphics.hpp>
#include "Event.h"
#include "Position.h"


namespace df{

	const std::string _MOUSE_EVENT = "df::mouse";

	enum EventMouseButton {
		UNDEFINED_MOUSE_BUTTON = -1,
		LEFT,
		RIGHT,
		MIDDLE,
	};

	// Set of mouse actions recognized by Dragonfly.
	enum EventMouseAction {
		UNDEFINED_MOUSE_ACTION = -1,
		CLICKED,
		PRESSED,
		MOVED,
	};


	class EventMouse : public Event {

	private:

		EventMouseAction mouse_action;

		EventMouseButton mouse_button;

		Position mouse_xy; 

	public:
		//public constructor
		EventMouse();

		//getters and setters
		void setMouseAction(EventMouseAction new_mouse_action);

		EventMouseAction getMouseAction() const;

		void setMouseButton(df::EventMouseButton new_mouse_button);

		EventMouseButton getMouseButton() const;

		void setMousePosition(Position new_mouse_xy);

		Position getMousePosition() const;


	};//!EventKeyboard

}//!df


#endif //!EVENT_MOUSE