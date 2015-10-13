//Chestguard source file
//Author: Marco Duran

#include "Chestguard.h"

Chestguard::Chestguard(df::Position position){
	Item::setIcon('a');
	Item::setColor(df::BLUE);
	Item::setDescription("Diamond Chestguard");

	value = 5;
	this->setEquipped(false);
	setPosition(position);
}

Chestguard::~Chestguard(){

}

//Apply the tunic 
void Chestguard::apply(const ApplyEvent*p_apply_event){
	ApplyEvent event = *p_apply_event;
	Wanderer *curr_wanderer = event.getCurrentWaderer();
	OutputView &ov = OutputView::getInstance();

	if (!this->getEquipped()){
		if (curr_wanderer->getDefence() > 0){
			ov.setOutput("The Wanderer may only wear one suit of armor at a time. Re-apply to remove armor");
			return;
		}
		this->setEquipped(true);
		std::string output = "Wanderer defense increased";
		ov.setOutput(output);
		curr_wanderer->setDefence(value);
	}
	else{
		this->setEquipped(false);
		curr_wanderer->setDefence(0);
		ov.setOutput("Wanderer defense decreased");
	}
}