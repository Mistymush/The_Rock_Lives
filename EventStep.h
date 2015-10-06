/*
Header file which defines the EventStep class
*/

#ifndef EVENT_STEP
#define EVENT_STEP

//engine includes
#include "Event.h"



namespace df{

	const std::string STEP_EVENT = "df::step";

	class EventStep : public df::Event {

	private:
		int step_count; //Iteration number of game loop

	public:
		//Default constuctor
		EventStep();

		//Destuctor
		~EventStep();

		//Constructor with a initial setp count,
		EventStep(int init_step_count);

		//Set step count.
		void setStepCount(int new_step_count);

		//Get step count
		int getStepCount() const;

	};

}//end df


#endif // end EVENT_STEP