/*
File which defines method bodys of the weapon class
Author: August Beers
*/

#include "Weapon.h"

Weapon::Weapon(int y){

	char weaponArray[10] = { '/', '/', '/', '/', '/', '%', '%', '%', '+', '+' };
	std::string descriptionArray[10] = { "Spear", "Spear", "Spear", "Spear", "Spear", "Sword", "Sword", "Sword", "GreatAxe", "GreatAxe" };
	int damageArray[10] = {3, 3, 3, 3, 3, 6, 6, 6, 9, 9};
	int rangeArray[10] = {2, 2, 2, 2, 2, 5, 5, 5, 7, 7};

	int floor = 0, ceiling = 9, range = (ceiling - floor);//range for the random number 
	int rand_range = floor + int((range * rand()) / (RAND_MAX + 1.0));
	int arrayValue = rand_range;


	Item::setIcon(weaponArray[arrayValue]);
	Item::setColor(df::CYAN);
	Item::setDescription(descriptionArray[arrayValue]);
	damage = damageArray[arrayValue];
	range = damageArray[arrayValue];

	this->setEquipped(false);
	df::Object::setPosition(df::Position(y, 10));
	

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

