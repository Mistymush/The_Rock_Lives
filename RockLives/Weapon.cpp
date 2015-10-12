/*
File which defines method bodys of the weapon class
Author: August Beers
*/

#include "Weapon.h"

Weapon::Weapon(int y){

	Item::setIcon('/');
	Item::setColor(df::CYAN);
	Item::setDescription("Spear");
	


	df::Object::setType("Weapon");
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

	if (!this->getEquipped()){
		if (current_wanderer->getAttack() > 0){
			OutputView &output_view = OutputView::getInstance();
			output_view.setOutput("The Wanderer can only hold one weapon at a time.");
			return;
		}
		this->setEquipped(true);
		current_wanderer->setAttack(damage);
		current_wanderer->setRange(range);
	}
	else{
		this->setEquipped(false);
		current_wanderer->setAttack(0);
		current_wanderer->setRange(0);
	}
	
}