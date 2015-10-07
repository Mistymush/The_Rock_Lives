/*
Header file which defines a weapon object
*/


#ifndef _Weapon_
#define _Weapon_

#include "Item.h"

class Weapon : public Item {

private:
	int damage;
	int range;

public:
	Weapon();

	~Weapon();

	void move();
	int eventHandler(const df::Event *p_e);
	void draw();
};

#endif // !_Weapon_
