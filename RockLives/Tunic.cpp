//Tunic source file
//Author: Marco Duran

#include "Tunic.h"

Tunic::Tunic(df::Position position){
	Item::setIcon('a');
	Item::setColor(df::GREEN);
	Item::setDescription("Tunic");

	value = 1;
	this->setEquipped(false);
	setPosition(position);
}

Tunic::~Tunic(){

}

//Apply the tunic 
void Tunic::apply(const ApplyEvent*p_apply_event){
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