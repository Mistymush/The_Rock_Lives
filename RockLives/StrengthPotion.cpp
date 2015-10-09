/*
File which defines the method bodys of a StrengthPotion
Author: August Beers
*/

#include "StrengthPotion.h"

StrengthPotion::StrengthPotion(df::Position position){

	Item::setIcon('!');
	Item::setColor(df::BLUE);
	Item::setDescription("Strength Potion");


	df::Object::setPosition(position);
	value = 2;

}

StrengthPotion::~StrengthPotion(){

}

/*
apply potion to the wanderer
*/
void StrengthPotion::apply(const ApplyEvent *p_apply_event){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	ApplyEvent event = *p_apply_event;
	Wanderer *current_wanderer = event.getCurrentWaderer();
	current_wanderer->setStrength(current_wanderer->getStrength() + value);
	world_manager.markforDelete(this);
}