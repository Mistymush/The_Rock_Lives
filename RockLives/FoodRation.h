/*
Header file which defines the food ration class
Author: August Beers
*/

#ifndef _FOOD_RATION_
#define _FOOD_RATION_


#include "Item.h"

class FoodRation : public Item {

private:
	int value;

public:
	//Initialize weapon with its inventory tag
	FoodRation(df::Position position);

	~FoodRation();

	void apply(const ApplyEvent *p_apply_event);

};

#endif // !_FOOD_RATION_