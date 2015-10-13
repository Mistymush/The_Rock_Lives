/*
File which defines method bodys of the weapon class
Author: August Beers
*/

#include "Weapon.h"

Weapon::Weapon(int y){

	Item::setIcon('/');
	Item::setColor(df::CYAN);
	Item::setDescription("Spear");

	this->setEquipped(false);
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
	OutputView &ov = OutputView::getInstance();

	if (!this->getEquipped()){
		if (current_wanderer->getAttack() > 0){
			ov.setOutput("The Wanderer may only weild one weapon at a time. Re-apply to unequip");
			return;
		}
		this->setEquipped(true);
		std::string damageS;
		std::ostringstream damage_convert;
		damage_convert << damage;
		damageS = damage_convert.str();

		ov.setOutput("Wanderer attack = " + damageS);
		current_wanderer->setAttack(damage);
		current_wanderer->setRange(range);
	}
	else{
		this->setEquipped(false);
		current_wanderer->setAttack(0);
		current_wanderer->setRange(0);
		ov.setOutput("Wanderer attack = 0");

	}
}

