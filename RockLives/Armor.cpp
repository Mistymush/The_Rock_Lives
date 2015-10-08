/*
File which defines the method bodys of the armor class
*/

#include "Armor.h"

Armor::Armor(df::Position position){

	Item::setIcon('a');
	Item::setColor(df::RED);
	Item::setDescription("Suit of Armor");


	df::Object::setPosition(position);
	

}

Armor::~Armor(){

}

/*
apply potion to the wanderer
*/
void Armor::apply(const ApplyEvent *p_apply_event){
	ApplyEvent event = *p_apply_event;
	Wanderer *current_wanderer = event.getCurrentWaderer();
	current_wanderer->setDefence(value);
}