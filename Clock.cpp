/*
File containing method declorations of Clock class
*/


#include "Clock.h"
	

using namespace df;


	//Sets previous_time to current time.
Clock::Clock(){
	SYSTEMTIME new_time;
	GetSystemTime(&new_time);
	previous_time = (new_time.wMinute * 60 * 1000)
		+ (new_time.wSecond * 1000)
		+ (new_time.wMilliseconds);
}

//Return time elapsed since delta() was last called, -1 if error.
//Units are microseconds.
long int Clock::delta(void){
	SYSTEMTIME new_time;
	long int delta_time;//New current time
	long int difference;//Difference between new time and previous time

	GetSystemTime(&new_time);
	delta_time = (new_time.wMinute * 60 * 1000)
		+ (new_time.wSecond * 1000)
		+ (new_time.wMilliseconds);

	difference = delta_time - previous_time;
	previous_time = delta_time;
	return difference;
}

//Return time elapsed since delta() was called, -1 if error
//units are microseconds.
long int Clock::split(void) const{
	SYSTEMTIME new_time;
	long int delta_time;//New current time
	long int difference;//Difference between new time and previous time

	GetSystemTime(&new_time);
	delta_time = (new_time.wMinute * 60 * 1000)
		+ (new_time.wSecond * 1000)
		+ (new_time.wMilliseconds);

	difference = delta_time - previous_time;
	return difference;
}