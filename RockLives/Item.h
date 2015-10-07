/*
Header file which defines a virtual item calss
Author: August Beers
*/


#ifndef _ITEM_
#define _ITEM_

#include "Object.h"

class Item : public df::Object {

private:
	//Graphical representation of this Item
	char icon;
	//A short description of this item, (17 char max)
	std::string description;


public:

	//Construct an item
	Item();
	//Destruct and item
	~Item();

	//Apply this item
	virtual void apply();

	void move();
	int eventHandler(const df::Event *p_e);
	void draw();
};

#endif // !_ITEM_
