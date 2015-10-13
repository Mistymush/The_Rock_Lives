//Author: Marco Duran
//Piece of armor called a chestguard 
//It is another light piece of armor

#ifndef _CHESTGUARD_
#define _CHESTGUARD_

#include "Armor.h"

class Chestguard : public Armor{
private:
	//defense value of the armor
	int value;

public:
	//Initialize tunic with its inventory tag
	Chestguard(df::Position position);

	~Chestguard();

	void apply(const ApplyEvent *p_apply_event);
};

#endif