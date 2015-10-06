/*
File containing the method definitions for class LogManager
*/


//System includes
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>
using namespace std;


//Project includes
#include "LogManager.h"
#include "Utility.h"


/*
Set manager type and initialize private variable
*/
df::LogManager::LogManager(){
	df::Manager::setType("LogManager");
	log = NULL;
	do_flush = false;





}


/*
Close log file if open

*/

df::LogManager::~LogManager(){
	if (!log == NULL){
		fclose(log);
	}





}


/*
Method which writes a message to the log file
*/
void df::LogManager::WriteMessage(const char *fmt, ...){

	if (log == NULL) perror("Error log file was not opened");
	else{
		df::Utility utility = df::Utility::Utility();
		
		fprintf(log, utility.getTimeString());
		fprintf(log, " Message: ");
		va_list args;
		va_start(args, fmt);
		vfprintf(log, fmt, args);
		va_end(args);
		fprintf(log, "\n");
		fflush(log);
	
	}

}

// Should Print game loops also
/*
Method which starts up a LogManager
*/
int df::LogManager::startUp(){
	log = fopen("log.txt", "w");
	WriteMessage("rock.log");
	fflush(log);
	
	df::Manager::startUp();
	return 0;
}

//Shutdown Manager.
void df::LogManager::shutDown(){
	fclose(log);
	Manager::shutDown();
}


//Singleton access function
df::LogManager &df::LogManager::getInstance(){
	static df::LogManager single;
	return single;

}

/*
set flush of text
*/
void df::LogManager::setFlush(bool do_flush){
	do_flush = true;
}