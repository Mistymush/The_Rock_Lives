/*
Header file which define the LogManager class, a manager which writes messages to the 
log file.
Author: August Beers
*/

#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H


//system includes
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>
using namespace std;

//project includes
#include "Manager.h"



namespace df{

	class LogManager : public df::Manager {

	private:
		//boolian which controlls if output is flushed or not
		bool do_flush;
		// pointer to the log file
		FILE *log;
		

		//Singleton behaivior overides
		LogManager();
		LogManager (LogManager const&); 
		void operator=(LogManager const&);

		

	public:
		//if log file is open close it.
		~LogManager();

		//Singleton access function
		static LogManager &getInstance();


		//Method which writes to log
		void WriteMessage(const char *fmt, ...);

		//Startup Manager.
		//Return 0 if ok, else negative number.
		virtual int startUp();

		//Shutdown Manager.
		virtual void shutDown();

		//Set flush of logfile after each write
		void setFlush(bool do_flush);


	};




}//end of namespace df

#endif //LOG_MANAGER