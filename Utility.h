/*
Class which contsins utility functions
*/

#ifndef UTILITY_H
#define UTILITY_H

//System includes
#include <stdio.h>
#include <time.h>
#include <string>
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

		//A-star
		//Should return a string of direction digits
		std::string pathFind(const int &x_start, const int &y_start, const int &x_finish, const int &y_finish);
	};


}

#endif // UTILITY_H