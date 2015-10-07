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

	setType("Monster");
	setSolidness(df::Solidness::HARD);
	//default object
	icon = 'x';
	//defaul color
	color = df::RED;

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

//see if someone is trying to pick up this item
int Item::eventHandler(const df::Event *p_e){
	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision *p_collision_event = dynamic_cast <const df::EventCollision *> (p_e);
		pickUp(p_collision_event);
		return 1;
	}
	return -1;
}

void Item::draw(){
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	graphics_manager.drawCh(Object::getPosition(), icon, color);
}

//set icon to given char
void Item::setIcon(char x){
	icon = x;

}
//set description to given string
void Item::setDescription(std::string tag){
	df::LogManager &log_mangager = df::LogManager::getInstance();
	if (tag.length() > 18){
		description = tag;
	}
	else
		log_mangager.WriteMessage("Item tag is to long, func: Item Constructor");
}

//set color to given color
void Item::setColor(df::Color new_color){
	color = new_color;
}

/*
Method which detects if the object trying to interact with it is
allowed to pick it up.
*/
void Item::pickUp(const df::EventCollision *p_collision_event){
	df::LogManager &log_manager = df::LogManager::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	static int list_head = 9;
	world_manager.moveObject(this, df::Position::Position(2 , list_head));
	list_head++;
}