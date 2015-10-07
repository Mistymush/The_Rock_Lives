#include "Wanderer.h"
#include "OutputView.h"
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

	setStrength(0);
	setHunger(5);
	setMaxHunger(5);
	setHp(10);
	setMaxHp(10);
	inventory = df::ObjectList();
	//weapon
	//armor
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
	if ((new_pos.getY() > 0) && (new_pos.getY() < graphics_manager.getVertical() - 1)) {
		world_manager.moveObject(this, new_pos);
	}
}

void Wanderer::setStrength(int new_strength) {
	strength = new_strength;
}

int Wanderer::getStrength() {
	return strength;
}

void Wanderer::setHunger(int new_hunger) {
	current_hunger = new_hunger;
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

void Wanderer::setHp(int new_hp) {
	current_hp = new_hp;
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