#ifndef __WANDERER_H__
#define __WANDERER_H__

#include "ObjectListIterator.h"
#include "EventKeyboard.h"
#include "Color.h"

class Wanderer : public df::Object {

private:
	int strength; // The Wanderer's strength stat
	int current_hunger; // The Wanderer's current hunger level
	int max_hunger; // The Wanderer's max hunger level (Not hungry at all)
	int current_hp; // The Wanderer's current health points
	int max_hp; // The Wanderer's max health
	df::ObjectList inventory; // The inventory of items the Wanderer is carrying
	char icon; // Character icon that represents the Wanderer
	df::Color color; // Color to draw the character icon
	//Weapon weapon; // The current weapon the Wanderer has equipped
	//Armor armor; // The current armor the Wanderer has equipped
	int exp; // The Wanderer's current amount of experience
	int level; // The Wanderer's current level

	void kbd(const df::EventKeyboard *p_keyboard_event);
	void move(int dx, int dy);

public:
	Wanderer();
	void setStrength(int new_strength);
	int getStrength();
	void setHunger(int new_hunger);
	int getHunger();
	void setMaxHunger(int new_max_hunger);
	int getMaxHunger();
	void setHp(int new_hp);
	int getHp();
	void setMaxHp(int new_max_hp);
	int getMaxHp();
	void setExp(int new_exp);
	int getExp();
	void setLevel(int new_level);
	int getLevel();
	df::ObjectList getInventory();
	char getIcon();
	int eventHandler(const df::Event *p_e);
	void draw();
	~Wanderer();

};

#endif // __WANDERER_H__