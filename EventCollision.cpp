/*
File which defines memeber funtioncs of the EventCOllision object
*/

#include "EventCollision.h"

using namespace df;

/*
Creates a collision event with pos (0,0) and NULL object pointers
*/
EventCollision::EventCollision(){
	
	pos = Position(0, 0);
	
	p_obj1 = NULL;

	p_obj2 = NULL;

	Event::setType(COLLISION_EVENT);
}

/*
Constructs a colision between 01 and 02 at given posistion p
Object 01 is the moving object that caused the collision
*/
EventCollision::EventCollision(Object *p_o1, Object *p_o2, Position p){
	pos = p;

	p_obj1 = p_o1;

	p_obj2 = p_o2;

	Event::setType(COLLISION_EVENT);
}

/*
Destructs Oobjects
*/
EventCollision::~EventCollision(){

}

//Getters and Setters --

/*
getter and setter for object that cuased collison
*/
Object *EventCollision::getObject() const{
	return p_obj1;
}

void EventCollision::setObject(Object *p_new_o1){
	p_obj1 = p_new_o1;
}

/*
getter and setter for object that was hit
*/
Object *EventCollision::getHitObject() const{
	return p_obj2;
}

void EventCollision::setHitObject(Object *p_new_o2){
	p_obj2 = p_new_o2;
}

/*
getters and setters for the position of the collision
*/
Position EventCollision::getPosition() const{
	return pos;
}

void EventCollision::setPosition(Position new_pos){
	pos = new_pos;
}