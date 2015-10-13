/*
Header file which defines the LevelGoal class
Author: Richard Hayes
*/

#ifndef __Level_Goal_H__
#define __Level_Goal_H__

#include "Object.h"
#include "EventCollision.h"
#include "WorldManager.h"
#include "Level.h"

class LevelGoal : public df::Object {

private:
	//Graphical representation of this Item
	char icon;
	//color of the icon
	df::Color color;
	bool seen;
	Level *level;

public:

	//Construct the Level Goal with a pointer to the Level
	LevelGoal(Level *level_pointer);

	int eventHandler(const df::Event *p_e);
	void draw();

	void setIcon(char new_icon);
	void setColor(df::Color new_color);
	void setSeen(bool is_seen);
};
#endif // __LEVEL_GOAL_H__