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

