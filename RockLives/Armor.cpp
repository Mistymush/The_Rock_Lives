/*
File which defines the method bodys of the armor class
*/

#include "Armor.h"

Armor::Armor(df::Position position){

	Item::setIcon('a');
	Item::setColor(df::RED);
	Item::setDescription("Suit of Armor");

	value = 2;
	this->setEquipped(false);
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
	OutputView &ov = OutputView::getInstance();

	if (!this->getEquipped()){
		if (current_wanderer->getDefence() > 0){
			ov.setOutput("The Wanderer may only wear one suit of armor at a time. Re-apply to remove armor");
			return;
		}
		this->setEquipped(true);
		std::string output = "Wanderer defence increased";
		ov.setOutput(output);
		current_wanderer->setDefence(value);
	}
	else{
		this->setEquipped(false);
		current_wanderer->setDefence(0);
		ov.setOutput("Wanderer defence decreased");
	}
	
}