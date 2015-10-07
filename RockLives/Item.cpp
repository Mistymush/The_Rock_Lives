/*
File which define the method bodys of the item class
Author: August Beers
*/

#include "Item.h"
#include "LogManager.h"

/*
Default constructor
*/
Item::Item(){
	icon = 'x';
	
	description = "Undfined";
}

/*
Default destructor
*/
Item::~Item(){

}

/*
Method which applys an item in some way
*/
void Item::apply(){
	df::LogManager &log_manager = df::LogManager::getInstance();
	log_manager.WriteMessage("Attempted to apply an undefined item!");
}

void Item::move(){

}

int Item::eventHandler(const df::Event *p_e){

	return -1;
}

void Item::draw(){

}