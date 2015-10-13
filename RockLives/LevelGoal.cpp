/*
File which defines method bodys of the LevelGoal class
Author: Richard Hayes
*/

#include "LevelGoal.h"

LevelGoal::LevelGoal(Level *level_pointer){
	setIcon('>');
	setColor(df::YELLOW);
	setType("LevelGoal");
	level = level_pointer;
	setSolidness(df::SOFT);
}

void LevelGoal::setIcon(char new_icon) {
	icon = new_icon;
}

void LevelGoal::setColor(df::Color new_color) {
	color = new_color;
}

void LevelGoal::setSeen(bool is_seen) {
	seen = is_seen;
}

int LevelGoal::eventHandler(const df::Event *p_e){
	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision *p_collision_event = dynamic_cast <const df::EventCollision *> (p_e);
		if (p_collision_event->getObject()->getType() == "Wanderer") {
			level->changeRoom(1);
		}
		return 1;
	}
	return -1;
}

void LevelGoal::draw() {
	//if (seen) {
		df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
		graphics_manager.drawCh(getPosition(), icon, color);
	//}
}