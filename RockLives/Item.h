/*
Header file which defines a virtual item calss
Author: August Beers
*/


#ifndef _ITEM_
#define _ITEM_

#include "Object.h"
#include "EventCollision.h"
#include "WorldManager.h"

class Item : public df::Object {

private:
	//Graphical representation of this Item
	char icon;
	//color of the icon
	df::Color color;

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

	void setIcon(char x);
	void setDescription(std::string tag);
	void setColor(df::Color new_color);

	void pickUp(const df::EventCollision *p_collision_event);
};

#endif // !_ITEM_
