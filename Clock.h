/*
Header file containig the class definition of a Clock object
the clock object is used for Maintaining fps
*/


#ifndef CLOCK
#define	CLOCK
//system includes
#include <Windows.h>


namespace df{
	class Clock{

	private:
		long int previous_time; // Previous time delta() called (in microseconds)

	public:
		//Set previous_time to current time.
		Clock();

		//Return time elapsed since delta() was last called, -1 if error.
		//Units are microseconds.
		long int delta(void);

		//Return time elapsed since delta() was called, -1 if error
		//units are microseconds.
		long int split(void) const;


	};

}// END NMAESPACE DF

#endif //END CLOCK

