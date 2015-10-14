/*
File which defines the display of a users inventory
Author: August Beers
*/

#include "InventoryView.h"
#include "ResourceManager.h"
#include "Color.h"

/*
Constructor of inventory vieww object
*/
InventoryView::InventoryView(Wanderer *new_wanderer){
	setType("InventoryView");

	my_wanderer = new_wanderer;
	//Set starting location
	df::GraphicsManager &g_m = df::GraphicsManager::getInstance();
	df::Position pos(0,9);
	setPosition(pos);
}


/*
Destructor of inventory view
*/
InventoryView::~InventoryView(){

}

/*
eventHandler
*/
int InventoryView::eventHandler(const df::Event *p_e){

	if (p_e->getType() == df::_KEYBOARD_EVENT) {
		const df::EventKeyboard *p_keyboard_event = dynamic_cast <const df::EventKeyboard *> (p_e);
		keyHandle(p_keyboard_event);
		return 1;
	}

	return 0;
}

/*
Draw method
*/
void InventoryView::draw(){
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::Position position(0, 4);
	df::Position position2(0, graphics_manager.getVertical() - 5);
	
	graphics_manager.drawString(position, "---------------------", df::LEFT_JUSTIFIED, df::RED);
	graphics_manager.drawString(position2, "---------------------", df::LEFT_JUSTIFIED, df::RED);

	df::Position tmp_position(20, 4);
	for (int i = 5; i < graphics_manager.getVertical()- 5; i++){
		tmp_position.setY(i);
		graphics_manager.drawCh(tmp_position, '|' , df::RED);
	}

	df::Position title(0, 5);
	graphics_manager.drawString(title, "Inventory, Press w/s", df::LEFT_JUSTIFIED, df::RED);
	title.setY(6);
	graphics_manager.drawString(title, "Press d to drop", df::LEFT_JUSTIFIED, df::RED);
	title.setY(7);
	graphics_manager.drawString(title, "Press a to apply", df::LEFT_JUSTIFIED, df::RED);
	title.setY(8);
	graphics_manager.drawString(title, "--------------------", df::LEFT_JUSTIFIED, df::RED);

	//draw reticle
	graphics_manager.drawString(getPosition(), "=>", df::LEFT_JUSTIFIED, df::RED);

}

void InventoryView::keyHandle(const df::EventKeyboard *p_keyboard_event) {
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	switch (p_keyboard_event->getKey()) {
	case df::Keyboard::W:			// up
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			move(-1);
		break;
	case df::Keyboard::S:			// down
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			move(+1);
		break;
	case df::Keyboard::D:			// drop
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			drop();
		break;
	case df::Keyboard::A:			// apply
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			apply();
		break;
	}
}



// Move up or down.
void InventoryView::move(int dy) {
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::Position new_pos(getPosition().getX(), getPosition().getY() + dy);

	// If stays on screen, allow move.
	if ((new_pos.getY() >= 9) && (new_pos.getY() < graphics_manager.getVertical() - 5)){
		world_manager.moveObject(this, new_pos);
	}
}


/*
Select to drop an item from the inventory by pressing d
*/
void InventoryView::drop(){
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	df::Position tmp = df::Object::getPosition();
	tmp.setX(tmp.getX() + 2);
	df::ObjectList item = world_manager.isCollision(this, tmp);

	if (!item.isEmpty()){
		df::ObjectListIterator item_list = df::ObjectListIterator(&item);
		DropEvent event = DropEvent(my_wanderer);
		item_list.currentObject()->eventHandler(&event);
	}
}

/*
Selt an item to apply
*/
void InventoryView::apply(){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	//df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	
	df::Position tmp = df::Object::getPosition();
	tmp.setX(tmp.getX() + 2);
	df::ObjectList item = world_manager.isCollision(this, tmp);

	if (!item.isEmpty()){
		df::ObjectListIterator item_list = df::ObjectListIterator(&item);

		ApplyEvent event = ApplyEvent(my_wanderer);
		item_list.currentObject()->eventHandler(&event);
	}
}