/*
File which defines the display of a users inventory
*/

#include "InventoryView.h"

/*
Constructor of inventory view object
*/
InventoryView::InventoryView(){
	setType("InventoryView");
	//Set starting location
	df::GraphicsManager &g_m = df::GraphicsManager::getInstance();
	df::Position pos(7, g_m.getVertical() / 2);
	setPosition(pos);
}


/*
Destructor of inventory veiw
*/
InventoryView::~InventoryView(){

}

/*
eventHandler
*/
int InventoryView::eventHandler(const df::Event *p_e){
	return 0;
}

/*
Draw method
*/
void InventoryView::draw(){
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	//df::Position position(0, 10);
	//df::Position position2(10, 10);
	
	graphics_manager.drawString(getPosition(), "-----------" , df::RIGHT_JUSTIFIED, df::RED);

}