#include <iostream>
#include <sstream>
#include <string>
#include "Level.h"
#include "GraphicsManager.h"

Level::Level() {
	setType("Level");

	setPosition(df::Position(10, 10));

	setWidth(50);
	setHeight(16);

	level_grid = new char*[height];
	for (int i = 0; i < height; ++i) {
		level_grid[i] = new char[width];
		for (int j = 0; j < width; j++) {
			level_grid[i][j] = 'A';
		}
	}
	/*
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::Position p(1, 1);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			graphics_manager.drawCh(p, (char)(level_grid[i][j]), df::WHITE);
			//log_manager.writeLog("Test\n");
			p.setX(p.getX() + 1);
		}
		p.setX(1);
		p.setY(p.getY() + 1);
	}*/
}

void Level::setWidth(int new_width) {
	width = new_width;
}

int Level::getWidth() {
	return width;
}

void Level::setHeight(int new_height) {
	height = new_height;
}

int Level::getHeight() {
	return height;
}

void Level::freeGrid() {
	for (int i = 0; i < width; ++i) {
		delete[] level_grid[i];
	}
	delete[] level_grid;
}

void Level::draw() {
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::Position p(1, 1);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			graphics_manager.drawCh(p, (char)(level_grid[i][j]), df::WHITE);
			//log_manager.writeLog("Test\n");
			p.setX(p.getX() + 1);
		}
		p.setX(1);
		p.setY(p.getY() + 1);
	}
}

Level::~Level() {
	freeGrid();
}