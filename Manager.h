/*
Hearder File for the Manager Superclass
A manager is a singleton which handles crucial engine tasks
Author: August Beers
*/

#ifndef MANAGER_H
#define MANAGER_H

//System includes
#include <string>

//project includes
#include "Event.h"

namespace df {

	class WorldManager;

	class Manager {

	private:
		std::string type; // String identifier of the manager.
		bool is_started;  // True when started successfully.

	

	protected:
		//Set type identifier of Manger.
		void setType(std::string type);

	public:
		

		// Get type identifier of Manager.
		std::string getType() const;

		//Startup Manager.
		//Return 0 if ok, else negative number.
		int startUp();

		//Shutdown Manager.
		void shutDown();

		//Check to see if a manager has started
		bool isStarted() const;

		//Send an event to all objects
		int onEvent(const Event *p_event) const;

	};

} // end namespace df

#endif //MANAGER