/*
File whic defines the method bodys of the food ration
Author: August Beers
*/


#include "FoodRation.h"

FoodRation::FoodRation(df::Position position){

	Item::setIcon('F');
	Item::setColor(df::GREEN);
	Item::setDescription("Food Ration");


	df::Object::setPosition(position);
	value = 64;

}

FoodRation::~FoodRation(){

}

/*
apply potion to the wanderer
*/
void FoodRation::apply(const ApplyEvent *p_apply_event){
	ApplyEvent event = *p_apply_event;
	Wanderer *current_wanderer = event.getCurrentWaderer();
	current_wanderer->feed(value);
}