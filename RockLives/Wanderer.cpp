//Game includes
#include "EventTurn.h"
#include "Wanderer.h"
#include "OutputView.h"
#include "Wall.h"
#include "Monster.h"
#include "Level.h"
//Engine includes
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "GameManager.h"
#include "ResourceManager.h"

Wanderer::Wanderer() {

	icon = '@';
	color = df::MAGENTA;

	setType("Wanderer");
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::Position pos(21, (graphics_manager.getVertical() / 2)-2);
	setPosition(pos);
	setAltitude(4);

	setStrength(5);
	setMaxHunger(192);
	current_hunger = 192;
	

	setMaxHp(10);
	current_hp = max_hp;
	inventory = df::ObjectList();

	setExp(0);
	setLevel(1);
	setSightRadius(50);
	setVisibleArea();
	setAttack(0);
	setRange(0);

	musicPlaying = true;
}

int Wanderer::eventHandler(const df::Event *p_e) {
	if (p_e->getType() == df::_KEYBOARD_EVENT) {
		const df::EventKeyboard *p_keyboard_event = static_cast <const df::EventKeyboard *> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	if (p_e->getType() == df::COLLISION_EVENT){
		const df::EventCollision *p_collision_event = dynamic_cast<const df::EventCollision *>(p_e);
		hit(p_collision_event);
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
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD2: //down
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, 1);
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD3: //down-right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, 1);
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD4: //left
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(-1, 0);
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD6: //right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, 0);
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD7: //up-left
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(-1, -1);
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD8: //up
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, -1);
			setVisibleArea();
			//output_view.setOutput("");
		}
		break;
	case df::Keyboard::NUMPAD9: //up-right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, -1);
			setVisibleArea();
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
			setVisibleArea();
		}
		break;
	case df::Keyboard::RIGHTARROW: //move right with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(1, 0);
			setVisibleArea();
		}
		break;
	case df::Keyboard::UPARROW:  //move up with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, -1);
			setVisibleArea();
		}
		break;
	case df::Keyboard::DOWNARROW:  //move down with arrow key
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			move(0, 1);
			setVisibleArea();
		}
		break;


	case df::Keyboard::Q: //change level
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED) {
			df::WorldManager &world_manager = df::WorldManager::getInstance();
			df::ObjectListIterator li(&world_manager.getAllobjects());
			for (li.first(); !li.isDone(); li.next()) {
				if (li.currentObject()->getType() == "Level") {
					Level *p_l = dynamic_cast <Level *> (li.currentObject());
					p_l->changeRoom(1);
				}
			}
		}
		break;

	case df::Keyboard::M: //Toggle Music
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED){
			df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
			df::Music *music = resource_manager.getMusic("game_music");
			if (musicPlaying){
				musicPlaying = false;
				music->stop();
			}
			else if (!musicPlaying){
				musicPlaying = true;
				music->play();
			}
		}
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

void Wanderer::hit(const df::EventCollision *p_c){
	df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	OutputView &ov = OutputView::getInstance();
	Monster *m;

	//If Monster on Wanderer, do damage
	if ((p_c->getObject()->getType() == "Monster") && (p_c->getObject()->getType() != "Wanderer")){
		m = dynamic_cast<Monster *>(p_c->getObject());
		
		int weapon_damage = 0;
		weapon_damage = getStrength() + getAttack() + rand() % getRange();
		ov.setOutput("You swing at the " + m->getType());
		m->hurt(weapon_damage);

		//play sound 
		df::Sound *s =  resource_manager.getSound("hit");
		s->play();
		
		
	}

}

void Wanderer::setVisibleArea() {
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::ObjectList ol = world_manager.getAllobjects();
	df::ObjectListIterator li(&ol);
	for (li.first(); !li.isDone(); li.next()) {
		if (li.currentObject()->getType() == "Mountain") {
			if ((pow(li.currentObject()->getPosition().getX() - getPosition().getX(), 2) + pow(li.currentObject()->getPosition().getY() - getPosition().getY(), 2)) <= (sight_radius ^ 2)) {
				Wall *p_w = dynamic_cast <Wall *> (li.currentObject());
				p_w->setSeen(true);
			}
		}
	}
}

void Wanderer::turn(){
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	if (current_hunger > 0){
		current_hunger--;
		
	}  
	else {
		hurt(1);
		
	}

	EventTurn turn;
	if (current_hp > 0 && current_hp < max_hp){
		current_hp++;
	}

	world_manager.onEvent(&turn);//sends a turn event to the world so the monsters can move
}

void Wanderer::hurt(int damage){
	OutputView &output_view = OutputView::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::GameManager &game_manager = df::GameManager::getInstance();
	df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	if (damage > 0){
		current_hp = current_hp - damage;
		if (current_hp <= 0){
			df::Music *music = resource_manager.getMusic("game_music");
			music->stop();
			df::Sound *sound = resource_manager.getSound("game_over");
			sound->play();
			output_view.setOutput("Game Over! press space to quit.");
			world_manager.markforDelete(this);
			
		}
	
	}
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
	df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	df::Sound *s = resource_manager.getSound("heal");
	if (new_hunger < 0){
		return;
	}

	if (new_hunger <= max_hunger - current_hunger){
		current_hunger = current_hunger + new_hunger;
		s->play();
	}
	else{
		current_hunger = max_hunger;
		s->play();
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

void Wanderer::setSightRadius(int new_sight_radius) {
	sight_radius = new_sight_radius;
}

int Wanderer::getSightRadius() {
	return sight_radius;
}

void Wanderer::draw() {
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	graphics_manager.drawCh(getPosition(), icon, color);
}

Wanderer::~Wanderer() {
	df::GameManager &game_manager = df::GameManager::getInstance();
	game_manager.getGameOver();
}


//some more getters and setters
int Wanderer::getAttack(){
	return weapon_attack;
}
void Wanderer::setAttack(int new_attack){
	if (new_attack > 0){
		weapon_attack = new_attack;
	}
}
int Wanderer::getRange(){
	return weapon_range;
}
void Wanderer::setRange(int new_range){
	if (new_range > 0){
		weapon_range = new_range;
	}
}