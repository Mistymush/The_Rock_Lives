#include "Wall.h"
#include "WorldManager.h"
#include "GraphicsManager.h"


Wall::Wall() {
	setType("Wall");
	setIcon('W');
	setColor(df::WHITE);
}

void Wall::setIcon(char new_icon) {
	icon = new_icon;
}

char Wall::getIcon() {
	return icon;
}

void Wall::setColor(df::Color new_color) {
	color = new_color;
}

df::Color Wall::getColor() {
	return color;
}

void Wall::draw() {
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	graphics_manager.drawCh(getPosition(), icon, color);
}