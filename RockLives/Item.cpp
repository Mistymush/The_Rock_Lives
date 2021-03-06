/*
File which define the method bodys of the item class
Author: August Beers
*/

#include "Item.h"
#include "LogManager.h"

/*
Default constructor
*/
Item::Item(){

	setSolidness(df::Solidness::SOFT);
	//default object
	icon = 'x';
	//defaul color
	color = df::RED;
	inInventory = false;
	description = "Undfined";
	is_equipped = false;
	setSeen(false);
}

/*
Default destructor
*/
Item::~Item(){

}

/*
Method which applys an item in some way
*/
void Item::apply(){
	df::LogManager &log_manager = df::LogManager::getInstance();
	log_manager.WriteMessage("Attempted to apply an undefined item!");
}

void Item::move(){

}

void Item::setSeen(bool is_seen) {
	seen = is_seen;
}

//see if someone is trying to pick up this item
int Item::eventHandler(const df::Event *p_e){
	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision *p_collision_event = dynamic_cast <const df::EventCollision *> (p_e);
		pickUp(p_collision_event);
		return 1;
	}
	if (p_e->getType() == DROP_EVENT) {
		const DropEvent *p_drop_event = dynamic_cast <const DropEvent *> (p_e);
		drop(p_drop_event);
		return 1;
	}
	if (p_e->getType() == APPLY_EVENT) {
		const ApplyEvent *p_apply_event = dynamic_cast <const ApplyEvent *> (p_e);
		apply(p_apply_event);
		return 1;
	}
	
	return -1;
}

void Item::draw(){
	if (seen || inInventory) {
		df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
		graphics_manager.drawCh(Object::getPosition(), icon, color);
		if (inInventory){
			df::Position tmp = Object::getPosition();
			if (is_equipped){
				df::Position tmp2 = Object::getPosition();
				tmp2.setX(Object::getPosition().getX() + 1);
				graphics_manager.drawCh(tmp2, 'e', df::GREEN);
			}

			tmp.setX(Object::getPosition().getX() + 2);
			graphics_manager.drawString(tmp, description, df::LEFT_JUSTIFIED, color);
		}
	}
}

//set icon to given char
void Item::setIcon(char x){
	icon = x;

}
//set description to given string
void Item::setDescription(std::string tag){
	df::LogManager &log_mangager = df::LogManager::getInstance();
	if (tag.length() < 18){
		description = tag;
	}
	else
		log_mangager.WriteMessage("Item tag is to long, func: Item Constructor");
}

//set color to given color
void Item::setColor(df::Color new_color){
	color = new_color;
}

/*
Method which detects if the object trying to interact with it is
allowed to pick it up.
*/
void Item::pickUp(const df::EventCollision *p_collision_event){
	df::LogManager &log_manager = df::LogManager::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	
	if (p_collision_event->getObject()->getType() == "Wanderer"){

		df::Position list_head_position(2, 9);

		for (int i = 0; i < 10; i++){
			df::ObjectList collision = world_manager.isCollision(this, list_head_position);
			if (collision.isEmpty()){
				world_manager.moveObject(this, list_head_position);
				inInventory = true;
				return;
			}
			else{
				list_head_position.setY(list_head_position.getY() + 1);
			}
		}
	}
	
}

void Item::drop(const DropEvent *p_drop_event){
	DropEvent event = *p_drop_event;
	OutputView &ov = OutputView::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	inInventory = false;
	if (is_equipped){
		if (this->getType() == "Weapon"){
			setEquipped(false);
			event.getCurrentWaderer()->setAttack(0);
			event.getCurrentWaderer()->setRange(0);
			ov.setOutput("Wanderer attack = 0");
		}

		else if (this->getType() == "Armor"){
			setEquipped(false);
			event.getCurrentWaderer()->setDefence(0);
			ov.setOutput("Wanderer defence = 0");
		}
	}

	df::ObjectList allObjects = world_manager.getAllobjects();
	df::ObjectListIterator li(&allObjects);
	while (!li.isDone()){
		if (Level *p_l = dynamic_cast<Level *>(li.currentObject())){
			p_l->addToRoom(this);
		}
		li.next();
	}
	
	df::Object::setPosition(event.getCurrentWaderer()->getPosition());
		
}

void Item::apply(const ApplyEvent *p_apply_event){
	//this shouldn not run
}


void Item::setEquipped(bool new_value){
	is_equipped = new_value;
}

bool Item::getEquipped(){
	return is_equipped;
}

bool Item::getInInventory(){
	return inInventory;
}