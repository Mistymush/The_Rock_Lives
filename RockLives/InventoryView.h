/*
header file which defines the InventoryView class
Author: August Beers
*/

#ifndef _Inventory_View_
#define _Inventory_View_

#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "Position.h"
#include "EventKeyboard.h"
#include "Wanderer.h"
#include "DropEvent.h"
#include "ApplyEvent.h"

class InventoryView : public df::Object{

private:
	
	//Wanderer with an inventory
	Wanderer *my_wanderer;

public:

	//Will take a pointer to the current wanderer
	InventoryView(Wanderer *new_wanderer);

	~InventoryView();

	int eventHandler(const df::Event *p_e);

	void draw();
	
	void keyHandle(const df::EventKeyboard *p_keyboard_event);

	// Move up or down.
	void move(int dy);

	void drop();

	void apply();

	

};



#endif /!_Inventory_View_