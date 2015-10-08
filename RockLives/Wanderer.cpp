//Game includes
#include "EventTurn.h"
#include "Wanderer.h"
#include "OutputView.h"
//Engine includes
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "GameManager.h"

Wanderer::Wanderer() {

	icon = '@';
	color = df::WHITE;

	setType("Wanderer");
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::Position pos(graphics_manager.getHorizontal() / 2, graphics_manager.getVertical() / 2);
	setPosition(pos);
	setAltitude(4);

	setStrength(0);
	feed(5);
	setMaxHunger(5);

	setMaxHp(10);
	current_hp = max_hp;
	inventory = df::ObjectList();

	setExp(0);
	setLevel(1);
}

int Wanderer::eventHandler(const df::Event *p_e) {
	if (p_e->getType() == df::_KEYBOARD_EVENT) {
		const df::EventKeyboard *p_keyboard_event = static_cast <const df::EventKeyboard *> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	return 0;
}

// Take the appropriate action according to key pressed
void Wanderer::kbd(const df::EventKeyboard *p_keyboard_event) {
	//OutputView &output_view = OutputView::getInstance();
	switch (p_keyboard_event->getKey()) {
	case df::Keyboard::NUMPAD1: //down-left
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(-1, 1);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD2: //down
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, 1);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD3: //down-right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, 1);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD4: //left
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(-1, 0);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD6: //right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, 0);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD7: //up-left
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(-1, -1);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD8: //up
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, -1);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD9: //up-right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, -1);
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::SLASH: //attack!
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			//output_view.setOutput("The Wanderer swings their weapon!");
		}
		break;
	case df::Keyboard::LEFTARROW:  //move left with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(-1, 0);
		}
		break;
	case df::Keyboard::RIGHTARROW: //move right with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, 0);
		}
		break;
	case df::Keyboard::UPARROW:  //move up with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, -1);
		}
		break;
	case df::Keyboard::DOWNARROW:  //move down with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, 1);
		}
		break;


	case df::Keyboard::Q: //quit
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			df::WorldManager &world_manager = df::WorldManager::getInstance();
			world_manager.markforDelete(this);
		}
		break;
	}
}

void Wanderer::move(int dx, int dy) {
	//If stays on window, allow move
	df::Position new_pos(getPosition().getX() + dx, getPosition().getY() + dy);
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	if ((new_pos.getY() >= 0) && (new_pos.getY() < graphics_manager.getVertical() - 5)
		&& (new_pos.getX() >= 22) && (new_pos.getX() < graphics_manager.getHorizontal() + 7)) {
		world_manager.moveObject(this, new_pos);
		turn();//execute a turn after you have moved
	}
}

void Wanderer::turn(){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	EventTurn turn;
	world_manager.onEvent(&turn);//sends a turn event to the world so the monsters can move
}

/*
Function which adds health to the wanderer
Author: August Beers
*/
void Wanderer::addHp(int new_hp) {
	if (new_hp < 0){
		return;
	}

	if (new_hp <= max_hp - current_hp){
		current_hp = current_hp + new_hp;
	}
	else{
		current_hp = max_hp;
	}
	
}

/*
Function which adds hunger points to the wanderer
Author: August Beers
*/
void Wanderer::feed(int new_hunger) {
	if (new_hunger < 0){
		return;
	}

	if (new_hunger <= max_hunger - current_hunger){
		current_hunger = current_hunger + new_hunger;
	}
	else{
		current_hunger = max_hunger;
	}
}

void Wanderer::setStrength(int new_strength) {
	strength = new_strength;
}

int Wanderer::getStrength() {
	return strength;
}



int Wanderer::getHunger() {
	return current_hunger;
}

void Wanderer::setMaxHunger(int new_max_hunger) {
	max_hunger = new_max_hunger;
}

int Wanderer::getMaxHunger() {
	return max_hunger;
}


int Wanderer::getHp() {
	return current_hp;
}

void Wanderer::setMaxHp(int new_max_hp) {
	max_hp = new_max_hp;
}

int Wanderer::getMaxHp() {
	return max_hp;
}

void Wanderer::setExp(int new_exp) {
	exp = new_exp;
}

int Wanderer::getExp() {
	return exp;
}

void Wanderer::setLevel(int new_level) {
	level = new_level;
}

void  Wanderer::setDefence(int new_defence){
	defence = new_defence;
}
int  Wanderer::getDefence(){
	return defence;
}

int Wanderer::getLevel() {
	return level;
}

df::ObjectList Wanderer::getInventory() {
	return inventory;
}

char Wanderer::getIcon() {
	return icon;
}

void Wanderer::draw() {
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	graphics_manager.drawCh(getPosition(), icon, color);
}

Wanderer::~Wanderer() {
	df::GameManager &game_manager = df::GameManager::getInstance();
	game_manager.getGameOver();
}