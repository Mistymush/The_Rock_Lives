#include <iostream>
#include <sstream>
#include <string>
#include "Level.h"
#include "GraphicsManager.h"
#include "Mountain.h"

Level::Level() {
	setType("Level");

	setPosition(df::Position(21, 0));

	setWidth(92);
	setHeight(19);

	max_path_width = 12;
	min_path_width = 3;

	start_pos = df::Position(0, height / 2);
	end_pos = df::Position(getPosition().getX(), width-1);

	level_grid = new char*[height];
	for (int i = 0; i < height; ++i) {
		level_grid[i] = new char[width];
		for (int j = 0; j < width; j++) {
			level_grid[i][j] = 'A';
		}
	}

	generateLevel();
}

void Level::generateLevel() {
	int start_x = start_pos.getX();
	int start_y = start_pos.getY();
	int end_x = end_pos.getX();
	int end_y = end_pos.getY();
	int x = start_pos.getX();
	int y = start_pos.getY();

	for (int i = 0; i < width; i++) {
		int half_width = -(rand() % (max_path_width / 2));
		int path_width = abs(half_width) + (rand() % (max_path_width / 2)) + min_path_width;
		for (int j = 0; j < abs(path_width); j++) {
			level_grid[y+half_width][x] = ' ';
			half_width++;
		}
		x++;
	}

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; j++) {
			switch (level_grid[i][j]) {
			case ('A') :
				Mountain *m = new Mountain();
				df::Position p = df::Position(j+getPosition().getX(), i+getPosition().getY());
				m->setPosition(p);
			}
		}
	}
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
	/*df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::Position p(getPosition().getX(), getPosition().getY());
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (j == 0 || j == width) {
				graphics_manager.drawCh(p, (char)(level_grid[i][j]), df::WHITE);
			}
			graphics_manager.drawCh(p, (char)(level_grid[i][j]), df::WHITE);
			p.setX(p.getX() + 1);
		}
		p.setX(getPosition().getX());
		p.setY(p.getY() + 1);
	}*/
}

Level::~Level() {
	freeGrid();
}