/***********************
Source File for monster
Author: @Marco Duran
************************/
//Engine includes
#include "GraphicsManager.h"
//Game includes
#include "Monster.h"


Monster::Monster(){
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

void Monster::move(){}
//handles the monster event
int Monster::eventHandler(const df::Event *p_e){
	return 0;
}
//draws the monster to the screen
void Monster::draw(){
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	graphics_manager.drawCh(getPosition(), getIcon(), df::GREEN);

}