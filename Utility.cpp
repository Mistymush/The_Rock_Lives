/*
File contailing ultility method definitions
*/


//Project includes
#include "Utility.h"

/*
Constructor of utility class
*/
df::Utility::Utility(){

}


/*
Destuctor of utility class
*/
df::Utility::~Utility(){

}


/*
Method which returns the current time from  the system call time()
*/
char *df::Utility::getTimeString(){

	//Output string
	static char time_str[30];

	//System call to get time
	time_t now;
	time(&now);
	struct tm *p_time = localtime(&now);
	

	// '02' goves twp digets, %d for integers.
	sprintf(time_str, "%02d:%02d:%02d",
		p_time->tm_hour,
		p_time->tm_min,
		p_time->tm_sec);

	return time_str;


}

bool df::Utility::positionsIntersect(Position p1, Position p2){
	if ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY())){
		return true;
	}
	else
	{
		return false;
	}
}


