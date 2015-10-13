/*
Header file whic defines the Armor class
Author: August Beers
*/

#ifndef _ARMOR_
#define _ARMOR_


#include "Item.h"
#include "OutputView.h"

class Armor : public Item {

private:
	//value of defence this armor provides
	int value;

public:
	//Initialize armor with its inventory tag
	Armor(df::Position position);
	~Armor();

	void apply(const ApplyEvent *p_apply_event);

};

#endif // !_ARMOR_