/*
Header file which defines a weapon object
Author: August Beers
*/


#ifndef _WEAPON_
#define _WEAPON_

#include <sstream>

#include "Item.h"
#include "OutputView.h"

class Weapon : public Item {

private:
	int damage;
	int range;

public:
	//Initialize weapon with its inventory tag
	Weapon(int y);

	~Weapon();

	void apply(const ApplyEvent *p_apply_event);

};

#endif // !_Weapon_
