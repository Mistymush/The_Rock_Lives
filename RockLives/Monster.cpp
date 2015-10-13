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
#include "Monster.h"
#include "Node.h"


Monster::Monster(){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	setType("Monster");
	setSolidness(df::Solidness::HARD);
	setAltitude(3);
	type = "Monster";
	//set object type to monster
	df::Object::setType("Monster");
	icon = 'm';
	curr_health = 3;
	speed = 1;
	strength = 2;
	setSeen(false);
	
}
//Author: Marco Duran
Monster::~Monster(){
		
}

//Gets the name of the monster
std::string Monster::getType(){
	return type;
}
//Sets the name of the monster
void Monster::setType(std::string new_type){
	type = new_type;
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

void Monster::setSeen(bool is_seen) {
	seen = is_seen;
}

void Monster::move(int new_dir){
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
	case Direction::RIGHT :
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
			if(world_manager.moveObject(this, newPosition) == 0)
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
int Monster::eventHandler(const df::Event *p_e){
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
		dir = atoi((u.pathFind(pos.getX(), pos.getY(), wanderer_pos.getX(), wanderer_pos.getY()).substr(0,1)).c_str());
		//dir = atoi((u.pathFind(pos.getX(),pos.getY(), wanderer_pos.getX(), wanderer_pos.getY())).c_str());
		move(dir);
		return 1;
	}

	return 0;
}
//draws the monster to the screen
void Monster::draw(){
	if (seen) {
		df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
		graphics_manager.drawCh(getPosition(), getIcon(), df::GREEN);
	}
}

void Monster::hit(const df::EventCollision *p_c){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	OutputView &ov = OutputView::getInstance();
	Wanderer *wanderer;
	
	//If Monster on Wanderer, do damage
	if ((p_c->getHitObject()->getType() == "Wanderer") && curr_health > 0){
		wanderer = dynamic_cast<Wanderer *>(p_c->getHitObject());
		ov.setOutput("The " + getType() +  " attacks!");
		wanderer->hurt(getStrength());

	}
}

/*
method which damages a monster
Author: august beers
*/
void Monster::hurt(int damage){
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
				p_w->setExp(10);
			}
			li.next();
		}
		world_manager.markforDelete(this);
	}
}