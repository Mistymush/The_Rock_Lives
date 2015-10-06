/*
Header file which defines the event class
*/

#ifndef EVENT
#define EVENT


//System includes
#include <string>

namespace df{

	const std::string UNDEFINED_EVENT = "df::undefined";

class Event{

	private:
		//type of the event
		std::string event_type;

	public:

		//Constructor
		Event();

		//Destructore
		virtual ~Event();

		//set event time
		void setType(std::string new_type);

		//Get event type
		std::string getType() const;

};



} //end df


#endif //end EVENT