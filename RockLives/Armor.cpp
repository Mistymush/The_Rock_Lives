/*
File which defines the method bodys of the armor class
*/

#include "Armor.h"

Armor::Armor(df::Position position){

	Item::setIcon('a');
	Item::setColor(df::RED);
	Item::setDescription("Suit of Armor");


	df::Object::setPosition(position);
	
	value = 2;
}

Armor::~Armor(){

}

/*
apply armor to the wanderer
*/
void Armor::apply(const ApplyEvent *p_apply_event){
	ApplyEvent event = *p_apply_event;
	OutputView &output_view = OutputView::getInstance();
	Wanderer *current_wanderer = event.getCurrentWaderer();

	if (!this->getEquipped()){
		if (current_wanderer->getDefence() > 0){		
			output_view.setOutput("The Wanderer can only wear one suit of armor at a time.");
			return;
		}
		this->setEquipped(true);
		current_wanderer->setDefence(value);
		
	}
	else{
		this->setEquipped(false);
		current_wanderer->setDefence(0);
	}
}