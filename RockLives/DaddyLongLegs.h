/******************************
Header file for the monster
Author: @Marco Duran
*******************************/
#ifndef _DADDYLONGLEGS_H_
#define _DADDYLONGLEGS_H_
//System includes
#include <string>


#include "Monster.h"
#include "Position.h"
#include "Wanderer.h"


class DaddyLongLegs : public Monster{
private:
	df::Position pos;
	std::string type;
	char icon;
	int curr_health;
	int exp;
	int strength;
	df::Position wanderer_pos;
	Wanderer *wanderer;
	bool seen;


public:
	DaddyLongLegs();
	~DaddyLongLegs();
	void move(int new_dir);
	int eventHandler(const df::Event *p_e);
	void draw();
	void hit(const df::EventCollision *p_c);
	void hurt(int damage);
	void setSeen(bool is_seen);

	//name
	std::string getType(void);
	void setType(std::string new_type);
	//icon
	char getIcon(void);
	void setIcon(char new_icon);
	//health
	int getHealth();
	void setHealth(int new_health);
	//speed
	int getExp();
	void setExp(int new_exp);
	//strength
	int getStrength();
	void setStrength(int new_strength);
	//Position
	df::Position getPosition();
	void setPosition(df::Position new_position);


};
#endif