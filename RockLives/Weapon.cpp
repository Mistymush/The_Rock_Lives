/*
File which defines method bodys of the weapon class
Author: August Beers
*/

#include "Weapon.h"

Weapon::Weapon(int y){

	Item::setIcon('/');
	Item::setColor(df::CYAN);
	Item::setDescription("Spear");

	
	df::Object::setPosition(df::Position(y, 10));
	damage = 3;
	range = 2;

}

Weapon::~Weapon(){

}

/*
apply this weapon to the wanderer
*/
void Weapon::apply(const ApplyEvent *p_apply_event){
	ApplyEvent event = *p_apply_event;
	Wanderer *current_wanderer = event.getCurrentWaderer();
	current_wanderer->setStrength(damage);
}