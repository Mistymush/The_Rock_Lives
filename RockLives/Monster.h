/******************************
	Header file for the monster
	Author: @Marco Duran
*******************************/
#ifndef _MONSTER_H_
#define _MONSTER_H_
//System includes
#include <string>

//Engine includes
#include "ObjectList.h"
#include "Position.h"
#include "Wanderer.h"
//Game includes

class Monster : public df::Object{
	private:
		df::Position pos;
		std::string name;
		char icon;
		int curr_health;
		int speed;
		int strength;
		df::ObjectList inventory;
		df::Position wanderer_pos;
		Wanderer *wanderer;
		

	public:
		Monster();
		~Monster();
		void move(int new_dir);
		int eventHandler(const df::Event *p_e);
		void draw();
		void hit(const df::EventCollision *p_c);

		//name
		std::string getName(void);
		void setName(std::string new_name);
		//icon
		char getIcon(void);
		void setIcon(char new_icon);
		//health
		int getHealth();
		void setHealth(int new_health);
		//speed
		int getSpeed();
		void setSpeed(int new_speed);
		//strength
		int getStrength();
		void setStrength(int new_strength);
		//Position
		df::Position getPosition();
		void setPosition(df::Position new_position);

		
};
#endif