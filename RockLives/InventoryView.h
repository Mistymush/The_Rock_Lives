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

class InventoryView : public df::Object{

private:

	//Wanderer with an inventory
	

public:

	//Will take a pointer to the current wanderer
	InventoryView();

	~InventoryView();

	int eventHandler(const df::Event *p_e);

	void draw();
	

};



#endif /!_Inventory_View_