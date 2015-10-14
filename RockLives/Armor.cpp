/*
File which defines the method bodys of the armor class
*/

#include "Armor.h"

Armor::Armor(df::Position position){

	
	Item::setColor(df::RED);

	df::Object::setPosition(position);
	df::Object::setType("Armor");
	
	char armorArray[10] = { 't', 't', 't', 't', 't', 'a', 'a', 'a', 'c', 'c' };
	std::string descriptionArray[10] = {"Tunic","Tunic","Tunic","Tunic","Tunic","Suit of Armor","Suit of Armor","Suit of Armor","Chestguard","Chestguard"};
	int valueArray[10] = { 1, 1, 1, 1, 1, 2, 2, 2, 5, 5 };

	int floor = 0, ceiling = 9, range = (ceiling - floor);//range for the random number 
	int rand_range = floor + int((range * rand()) / (RAND_MAX + 1.0));
	int arrayValue = rand_range;

	Item::setIcon(armorArray[arrayValue]);
	Item::setDescription(descriptionArray[arrayValue]);
	value = valueArray[arrayValue];
	this->setEquipped(false);
}

Armor::~Armor(){

}

/*
apply armor to the wanderer
*/
void Armor::apply(const ApplyEvent *p_apply_event){
	ApplyEvent event = *p_apply_event;
	Wanderer *current_wanderer = event.getCurrentWaderer();
	OutputView &ov = OutputView::getInstance();

	if (!this->getEquipped()){
		if (current_wanderer->getDefence() > 0){
			ov.setOutput("The Wanderer may only wear one suit of armor at a time. Re-apply to remove armor");
			return;
		}
		this->setEquipped(true);

		std::string defenceS;
		std::ostringstream defence_convert;
		defence_convert << value;
		defenceS = defence_convert.str();

		std::string output = "Wanderer defense = " + defenceS;
		ov.setOutput(output);
		current_wanderer->setDefence(value);
	}
	else{
		this->setEquipped(false);
		current_wanderer->setDefence(0);
		ov.setOutput("Wanderer defense = 0");
	}
	
}