/***********************
Source File for monster
Author: @Marco Duran
************************/
//Engine includes
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "EventTurn.h"
#include "EventCollision.h"
#include "Utility.h"
//Game includes
#include "Monster.h"
#include "Node.h"


Monster::Monster(){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	setType("Monster");
	setSolidness(df::Solidness::HARD);
	name = "Monster";
	icon = 'w';
	curr_health = 1;
	speed = 1;
	strength = 1;
	
	
}

Monster::~Monster(){}

//Gets the name of the monster
std::string Monster::getName(){
	return name;
}
//Sets the name of the monster
void Monster::setName(std::string new_name){
	name = new_name;
}
//Gets the icon of the monster
char Monster::getIcon(){
	return icon;
}
//Sets the icon of the monster
void Monster::setIcon(char new_icon){
	icon = new_icon;
}
//Gets the health of the monster
int Monster::getHealth(){
	return curr_health;
}
//Sets the health of the monster
void Monster::setHealth(int new_health){
	curr_health = new_health;
}
//Gets the speed of the monster
int Monster::getSpeed(){
	return speed;
}
//Sets the speed of the monster
void Monster::setSpeed(int new_speed){
	speed = new_speed;
}
//Gets the strength of the monster
int Monster::getStrength(){
	return strength;
}
//Sets the strength of the monster
void Monster::setStrength(int new_strength){
	strength = new_strength;
}
//Gets the position of the monster
df::Position Monster::getPosition(){
	return pos;
}
//Sets the position of the monster
void Monster::setPosition(df::Position new_position){
	pos = new_position;
}

void Monster::move(int new_dir){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	//Create all the possible positions to move the monster
	df::Position right = df::Position(1, 0);
	df::Position upRight = df::Position(1, 1);
	df::Position up = df::Position(0, 1);
	df::Position upLeft = df::Position(-1, 1);
	df::Position left = df::Position(-1, 0);
	df::Position downLeft = df::Position(-1, -1);
	df::Position down = df::Position(0, -1);
	df::Position downRight = df::Position(1, -1);

	//make a switch case for the direction recived from the pathfind string
	int direction = new_dir;
	switch (direction){
	case Direction::RIGHT :
		world_manager.moveObject(this, df::Position((getPosition().getX() + right.getX()), (getPosition().getY() + right.getY())));
		break;
	case Direction::UPRIGHT:
		world_manager.moveObject(this, df::Position((getPosition().getX() + upRight.getX()), (getPosition().getY() + upRight.getY())));
		break;
	case Direction::UP:
		world_manager.moveObject(this, df::Position((getPosition().getX() + up.getX()), (getPosition().getY() + up.getY())));
		break;
	case Direction::UPLEFT:
		world_manager.moveObject(this, df::Position((getPosition().getX() + upLeft.getX()), (getPosition().getY() + upLeft.getY())));
		break;
	case Direction::LEFT:
		world_manager.moveObject(this, df::Position((getPosition().getX() + left.getX()), (getPosition().getY() + left.getY())));
		break;
	case Direction::DOWNLEFT:
		world_manager.moveObject(this, df::Position((getPosition().getX() + downLeft.getX()), (getPosition().getY() + downLeft.getY())));
		break;
	case Direction::DOWN:
		world_manager.moveObject(this, df::Position((getPosition().getX() + down.getX()), (getPosition().getY() + down.getY())));
		break;
	case Direction::DOWNRIGHT:
		world_manager.moveObject(this, df::Position((getPosition().getX() + downRight.getX()), (getPosition().getY() + downRight.getY())));
		break;
	default:
		break;
	}
}
//handles the monster event
int Monster::eventHandler(const df::Event *p_e){
	df::LogManager & log_manager = df::LogManager::getInstance();
	log_manager.WriteMessage(p_e->getType().c_str());
	df::Utility u;
	
	

	if (p_e->getType() == df::COLLISION_EVENT){
		const df::EventCollision *p_collision_event = dynamic_cast<const df::EventCollision *>(p_e);
		hit(p_collision_event);
		return 1;
	}
	if (p_e->getType() == df::TURN_EVENT){
		const df::EventTurn *p_turn_event = dynamic_cast<const df::EventTurn *>(p_e);
		wanderer_pos = wanderer->getPosition();
		int dir = atoi((u.pathFind(pos, wanderer_pos).substr(0)).c_str());
		move(dir);
		return 1;
	}

	return 0;
}
//draws the monster to the screen
void Monster::draw(){
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	graphics_manager.drawCh(getPosition(), getIcon(), df::GREEN);

}

void Monster::hit(const df::EventCollision *p_c){

}