/*
Headr file which defines the StrengthPotion class
Author: August Beers
*/


#ifndef _STRENGTH_POTION_
#define _STRENGTH_POTION_


#include "Item.h"

class StrengthPotion : public Item {

private:
	int value;

public:
	//Initialize weapon with its inventory tag
	StrengthPotion(df::Position position);

	~StrengthPotion();

	void apply(const ApplyEvent *p_apply_event);

};

#endif // !_STRENGTH_POTION_