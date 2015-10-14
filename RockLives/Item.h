/*
Header file which defines a virtual item calss
Author: August Beers
*/


#ifndef _ITEM_
#define _ITEM_

#include "Object.h"
#include "EventCollision.h"
#include "WorldManager.h"
#include "DropEvent.h"
#include "ApplyEvent.h"
#include "OutputView.h"
#include "Level.h"

class Item : public df::Object {

private:
	//Graphical representation of this Item
	char icon;
	//color of the icon
	df::Color color;
	//is item equipped
	bool is_equipped;

	//is this item in the inventory
	bool inInventory;

	//has the item been seen by the Wanderer?
	bool seen;

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
	void setSeen(bool is_seen);

	void pickUp(const df::EventCollision *p_collision_event);

	void drop(const DropEvent *p_drop_event);

	virtual void apply(const ApplyEvent *p_apply_event);

	void setEquipped(bool new_value);
	bool getEquipped();

	bool getInInventory();
};

#endif // !_ITEM_
