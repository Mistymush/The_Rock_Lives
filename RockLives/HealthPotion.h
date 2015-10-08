/*
Header file which defines the health potion class
Author: August Beers
*/

#ifndef _HEALTH_POTION_
#define _HEALTH_POTION_


#include "Item.h"

class HealthPotion : public Item {

private:
	int value;

public:
	//Initialize weapon with its inventory tag
	HealthPotion(df::Position position);

	~HealthPotion();

	void apply(const ApplyEvent *p_apply_event);

};

#endif // !_HEALTH_POTION_