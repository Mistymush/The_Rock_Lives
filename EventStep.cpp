/*
File which defines the methods of the EventStep class
*/

//engine includes
#include "EventStep.h"

using namespace df;

/*
Default Constuctor
*/
EventStep::EventStep(){
	
	setType(STEP_EVENT);

	step_count = 0;

}

/*
Constructor with initial count
*/
EventStep::EventStep(int init_step_count){

	setType(STEP_EVENT);

	step_count = init_step_count;

}


EventStep::~EventStep(){

}

/*
Setters and Getters
*/

void EventStep::setStepCount(int new_set_count){
	step_count = new_set_count;
}

int EventStep::getStepCount() const{
	return step_count;
}

