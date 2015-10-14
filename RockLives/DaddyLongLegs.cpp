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
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "OutputView.h"
//Game includes
#include "DaddyLongLegs.h"
#include "Node.h"


DaddyLongLegs::DaddyLongLegs(){
	int floor = 15, ceiling = 20, range = (ceiling - floor);//range for the random number 
	int strength_range = floor + int((range * rand()) / (RAND_MAX + 1.0));
	

	setSolidness(df::Solidness::HARD);
	setAltitude(3);
	type = "DaddyLongLegs";
	//set object type to monster
	df::Object::setType(type);
	icon = 'H';
	curr_health = 60;
	exp = 150;
	strength = strength_range;
	setSeen(false);

}
//Author: Marco Duran
DaddyLongLegs::~DaddyLongLegs(){
	//Show game over and prompt player to quit
	OutputView &ov = OutputView::getInstance();
	ov.setOutput("Congratulations, you have beaten the Infamous Daddy Long Legs, you can continue exploring or quit with Q.");
}

//Gets the name of the monster
std::string DaddyLongLegs::getType(){
	return type;
}
//Sets the name of the monster
void DaddyLongLegs::setType(std::string new_type){
	type = new_type;
}
//Gets the icon of the monster
char DaddyLongLegs::getIcon(){
	return icon;
}
//Sets the icon of the monster
void DaddyLongLegs::setIcon(char new_icon){
	icon = new_icon;
}
//Gets the health of the monster
int DaddyLongLegs::getHealth(){
	return curr_health;
}
//Sets the health of the monster
void DaddyLongLegs::setHealth(int new_health){
	curr_health = new_health;
}
//Gets the experience worth of the monster
int DaddyLongLegs::getExp(){
	return exp;
}
//Sets the experience worth of the monster
void DaddyLongLegs::setExp(int new_exp){
	exp = new_exp;
}
//Gets the strength of the monster
int DaddyLongLegs::getStrength(){
	return strength;
}
//Sets the strength of the monster
void DaddyLongLegs::setStrength(int new_strength){
	strength = new_strength;
}
//Gets the position of the monster
df::Position DaddyLongLegs::getPosition(){
	return pos;
}
//Sets the position of the monster
void DaddyLongLegs::setPosition(df::Position new_position){
	pos = new_position;
}

void DaddyLongLegs::setSeen(bool is_seen) {
	seen = is_seen;
}

void DaddyLongLegs::move(int new_dir){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	//Create all the possible positions to move the monster
	df::Position right = df::Position(1, 0);
	df::Position upRight = df::Position(1, 1);
	df::Position up = df::Position(0, 1);
	df::Position upLeft = df::Position(-1, 1);
	df::Position left = df::Position(-1, 0);
	df::Position downLeft = df::Position(-1, -1);
	df::Position down = df::Position(0, -1);
	df::Position downRight = df::Position(1, -1);
	df::Position newPosition;




	//make a switch case for the direction recived from the pathfind string
	switch (new_dir){
	case Direction::RIGHT:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + right.getX(), getPosition().getY() + right.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	case Direction::UPRIGHT:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + upRight.getX(), getPosition().getY() + upRight.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	case Direction::UP:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + up.getX(), getPosition().getY() + up.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	case Direction::UPLEFT:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + upLeft.getX(), getPosition().getY() + upLeft.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	case Direction::LEFT:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + left.getX(), getPosition().getY() + left.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7)){
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		}

		break;
	case Direction::DOWNLEFT:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + downLeft.getX(), getPosition().getY() + downLeft.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	case Direction::DOWN:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + down.getX(), getPosition().getY() + down.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	case Direction::DOWNRIGHT:
		//if the monster is within the game world, allow move
		newPosition = df::Position(getPosition().getX() + downRight.getX(), getPosition().getY() + downRight.getY());
		if ((newPosition.getY() >= 0) && (newPosition.getY() < graphics_manager.getVertical() - 5)
			&& (newPosition.getX() >= 22) && (newPosition.getX() < graphics_manager.getHorizontal() + 7))
			if (world_manager.moveObject(this, newPosition) == 0)
				setPosition(newPosition);
		break;
	}
}
//handles the monster event
int DaddyLongLegs::eventHandler(const df::Event *p_e){
	df::LogManager & log_manager = df::LogManager::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	OutputView &ov = OutputView::getInstance();

	df::Utility u;
	int dir = 0;



	if (p_e->getType() == df::COLLISION_EVENT){
		const df::EventCollision *p_collision_event = dynamic_cast<const df::EventCollision *>(p_e);
		hit(p_collision_event);
		return 1;
	}
	if (p_e->getType() == TURN_EVENT){

		const EventTurn *p_turn_event = dynamic_cast<const EventTurn *>(p_e);
		df::ObjectList allObjects = world_manager.getAllobjects();
		df::ObjectListIterator *li = new df::ObjectListIterator(&allObjects);
		while (!li->isDone()){
			if (li->currentObject()->getType() == "Wanderer"){
				wanderer_pos = li->currentObject()->getPosition();
			}
			li->next();
		}
		dir = atoi((u.pathFind(pos.getX(), pos.getY(), wanderer_pos.getX(), wanderer_pos.getY()).substr(0, 1)).c_str());
		move(dir);
		return 1;
	}

	return 0;
}
//draws the monster to the screen
void DaddyLongLegs::draw(){
	if (seen) {
		df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
		graphics_manager.drawCh(getPosition(), getIcon(), df::GREEN);
	}
}

void DaddyLongLegs::hit(const df::EventCollision *p_c){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	OutputView &ov = OutputView::getInstance();
	Wanderer *wanderer;

	//If Monster on Wanderer, do damage
	if ((p_c->getHitObject()->getType() == "Wanderer") && curr_health > 0){
		wanderer = dynamic_cast<Wanderer *>(p_c->getHitObject());
		ov.setOutput("The " + getType() + " attacks!");
		wanderer->hurt(getStrength());

	}
}

/*
method which damages a monster
Author: august beers
*/
void DaddyLongLegs::hurt(int damage){
	OutputView &ov = OutputView::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	if (curr_health - damage > 0){
		setHealth(curr_health - damage);

	}
	else{
		//Monster was defeated
		setHealth(0);
		ov.setOutput("The " + getType() + " was slain!");
		//Give the wanderer experience
		df::ObjectList allObjects = world_manager.getAllobjects();
		df::ObjectListIterator li(&allObjects);
		Wanderer *p_w;
		while (!li.isDone()){//Find the wanderer
			if (li.currentObject()->getType() == "Wanderer"){
				p_w = dynamic_cast<Wanderer *>(li.currentObject());
				p_w->setExp(exp);
			}
			li.next();
		}
		world_manager.markforDelete(this);
	}
}