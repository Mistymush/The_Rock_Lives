/*
File which defines the methods of the object class
*/

#include "Object.h"
#include "WorldManager.h"
#include "LogManager.h"

using namespace df;

Object::Object(){
	
	static int id_counter = 0;
	id = id_counter;
	id_counter++;

	//object is inittially has no type
	type = "Undifined Object";

	//object position is inititaill the top left corner of the screen
	pos = Position();
	//initialize velopcity to 0;
	x_velocity = 0;
	x_velocity_countdown = 0;
	y_velocity = 0;
	y_velocity_countdown = 0;

	altitude = 0;

	solidness = df::HARD;

	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.insertObject(this);

}


//virtual destructor, should not be used
Object::~Object(){


}



/*
Geters and setters
*/

//Set Object id
void Object::setID(int new_id){
	id = new_id;
}

//get object id
int Object::getId() const{
	return id;
}

//set type
void Object::setType(std::string new_type){
	type = new_type;
}

//get object ype
std::string Object::getType(){
	return type;
}

//Set position object
void Object::setPosition(Position new_pos){
	pos = new_pos;
}

//Get position of object
Position Object::getPosition() const{
	return pos;
}

//Generic Event Handler
int Object::eventHandler(const df::Event *p_e){

	LogManager &log_manager = LogManager::getInstance();
	log_manager.WriteMessage(p_e->getType().c_str());
	if (p_e->getType() == df::COLLISION_EVENT){
		const df::EventCollision *p_collision_event =
			static_cast <const df::EventCollision *> (p_e);
		if (p_collision_event->getObject()->getId() == id){
			x_velocity = -1 * x_velocity;
			y_velocity = -1 * y_velocity;
		}
		return 0;
	}
	return 0;
}


//set altitude, any value greater than MAX_Altitude is regected
int Object::setAltitude(int new_altitude){
	if (new_altitude < MAX_ALTTITUDE){
		altitude = new_altitude;
		return 0;
	}
	else{
		return -1;
	}
}

//Return object altitude
int Object::getAltitude() const{
	return altitude;
}

void Object::setXVelocity(float new_x_velocity){
	x_velocity = new_x_velocity;
	x_velocity_countdown = 1;

}

float Object::getXVelocity() const{
	return x_velocity;
}

void Object::setYVelocity(float new_y_velocity){
	y_velocity = new_y_velocity;
	y_velocity_countdown = 1;
}

float Object::getYVelocity() const{
	return y_velocity;
}

//Method which advances the velocity counter and then detrmines if an object should move this frame
int Object::getXVelocityStep(){
	if (x_velocity == 0){
		return 0;
	}

	x_velocity_countdown = x_velocity_countdown - fabs(x_velocity);
	if (x_velocity_countdown > 0){
		return 0;
	}

	//Time to move
	int spaces = (int)floor(1 - x_velocity_countdown);
	x_velocity_countdown = (float)(1 + fmod((int)x_velocity_countdown, 1));

	//Return number of spaces to move
	if (x_velocity > 0){
		return spaces;
	}
	else
		return -1 * spaces;

}

//y component of Velocity step
int Object::getYVelocityStep(){
	if (y_velocity == 0){
		return 0;
	}

	y_velocity_countdown = y_velocity_countdown - fabs(y_velocity);
	if (y_velocity_countdown > 0){
		return 0;
	}

	//Time to move
	int spaces = (int)floor(1 - y_velocity_countdown);
	y_velocity_countdown = (float)(1 + fmod(y_velocity_countdown, 1));

	//Return number of spaces to move
	if (y_velocity > 0){
		return spaces;
	}
	else
		return -1 * spaces;
}

bool Object::isSolid(){
	if (solidness == HARD || solidness == SOFT){
		return true;
	}
	else
		return false;
}

int Object::setSolidness(Solidness new_solid){
	if (new_solid == HARD || new_solid == SOFT || new_solid == SPECTRAL){
		solidness = new_solid;
		return 0;
	}
	else{
		return -1;
	}
}

Solidness Object::getSolidness() const{
	return solidness;
}

void Object::draw(){
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();
	graphics_manager.drawCh(pos, 'X' , df::GREEN);
}

