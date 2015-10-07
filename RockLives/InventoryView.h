/*
header file which defines the InventoryView class
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

class InventoryView : public df::Object{

private:

	//Wanderer with an inventory
	

public:

	//Will take a pointer to the current wanderer
	InventoryView();

	~InventoryView();

	int eventHandler(const df::Event *p_e);

	void draw();
	
	void keyHandle(const df::EventKeyboard *p_keyboard_event);

	// Move up or down.
	void move(int dy);

};



#endif /!_Inventory_View_