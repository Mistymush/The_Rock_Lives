#ifndef __WANDERER_H__
#define __WANDERER_H__

#include "ObjectListIterator.h"
#include "EventKeyboard.h"
#include "EventCollision.h"
#include "Color.h"

class Wanderer : public df::Object {

private:

	//Pointer to the wanderer's equiped weapon

	//the wanderer's equiped armor bonus
	int defence;

	int strength; // The Wanderer's strength stat
	int weapon_attack;
	int weapon_range;

	int current_hunger; // The Wanderer's current hunger level
	int max_hunger; // The Wanderer's max hunger level (Not hungry at all)
	int current_hp; // The Wanderer's current health points
	int max_hp; // The Wanderer's max health
	df::ObjectList inventory; // The inventory of items the Wanderer is carrying
	char icon; // Character icon that represents the Wanderer
	df::Color color; // Color to draw the character icon
	int exp; // The Wanderer's current amount of experience
	int level; // The Wanderer's current level
	int sight_radius;

	void kbd(const df::EventKeyboard *p_keyboard_event);
	void move(int dx, int dy);
	void turn();
	void hit(const df::EventCollision *p_c);

public:
	//add health to the wandere
	void addHp(int new_hp);
	void feed(int new_hunger);
	void hurt(int damage);

	Wanderer();
	void setStrength(int new_strength);
	int getStrength();
	
	int getHunger();
	void setMaxHunger(int new_max_hunger);
	int getMaxHunger();
	
	int getHp();
	void setMaxHp(int new_max_hp);
	int getMaxHp();
	void setExp(int new_exp);
	int getExp();
	void setLevel(int new_level);
	int getLevel();
	void setDefence(int new_defence);
	int getDefence();

	int getAttack();
	void setAttack(int new_attack);
	int getRange();
	void setRange(int new_range);

	df::ObjectList getInventory();
	char getIcon();
	int eventHandler(const df::Event *p_e);
	void draw();
	void setSightRadius(int new_sight_radius);
	int getSightRadius();
	void setVisibleArea();
	~Wanderer();

};

#endif // __WANDERER_H__