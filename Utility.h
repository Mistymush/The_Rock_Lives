/*
Class which contsins utility functions
*/

#ifndef UTILITY_H
#define UTILITY_H

//System includes
#include <stdio.h>
#include <time.h>
#include "Position.h"


namespace df{

	class Utility {

	public:
		Utility();
		~Utility();

		//Method which returns a string of the current time
		char *getTimeString();


		//Return true if two positions intersect, else false
		bool positionsIntersect(Position p1, Position p2);


	};


}

#endif // UTILITY_H