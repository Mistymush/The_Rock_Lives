/*
File which defines the method bodus of the health potion class
Author: August Beers
*/

#include "HealthPotion.h"

HealthPotion::HealthPotion(df::Position position){

	Item::setIcon('!');
	Item::setColor(df::RED);
	Item::setDescription("Health Potion");


	df::Object::setPosition(position);
	value = 32;

}

HealthPotion::~HealthPotion(){

}

/*
apply potion to the wanderer
*/
void HealthPotion::apply(const ApplyEvent *p_apply_event){
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	ApplyEvent event = *p_apply_event;
	Wanderer *current_wanderer = event.getCurrentWaderer();
	current_wanderer->addHp(value);
	world_manager.markforDelete(this);
}