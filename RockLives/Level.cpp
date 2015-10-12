//System includes
#include <iostream>
#include <sstream>
#include <string>
//Engine includes
#include "GraphicsManager.h"
//Game includes
#include "Level.h"
#include "Mountain.h"
#include "Monster.h"
#include "Weapon.h"

Level::Level() {
	setType("Level");

	setPosition(df::Position(21, 0));

	setWidth(92);
	setHeight(19);

	max_path_width = 12;
	min_path_width = 3;

	start_pos = df::Position(0, height / 2);
	end_pos = df::Position(getPosition().getX(), width-1);

	generateLevel();
}

/* Generates a brand new level layout, creating a character array representing the level and populating the
*  level based on that character array.
*/
void Level::generateLevel() {
	// The starting and ending x and y positions of the path that will be carved out
	int start_x = start_pos.getX();
	int start_y = start_pos.getY();
	int end_x = end_pos.getX();
	int end_y = end_pos.getY();
	// The x and y values that update as the algorithm traverses level grid
	int x = start_pos.getX();
	int y = start_pos.getY();

	// Fill the level grid with mountain characters
	level_grid = new char*[height]; // Initialize an the level grid as an array of char arrays
	for (int i = 0; i < height; ++i) { // For each row of the grid...
		level_grid[i] = new char[width]; // Initialize an array of chars
		for (int j = 0; j < width; j++) { // For each column entry in that row...
			level_grid[i][j] = 'A'; // Set the entry to the 'A' character, for a mountain
		}
	}

	// Start traversing the level_grid using x and y, carving out a randomly wide path as you go
	for (int i = 0; i < width; i++) {
		int half_width = -(rand() % (max_path_width / 2)); // Randomize the amount of path carved out above the x,y location
		int path_width = abs(half_width) + (rand() % (max_path_width / 2)) + min_path_width; // Randomize the amount of path carved out below the x,y location
		for (int j = 0; j < path_width; j++) {
			if (j > 0 && j < height) { // Don't carve the path of place an item on the vertical boundaries
				int item_chance = rand() % 300; // Item spawn rate
				int monster_chance = rand() % 200; // Monster spawn rate 
				if (item_chance == 0) {
					level_grid[y + half_width][x] = '/';
				}
				else if (monster_chance == 0) {
					level_grid[y + half_width][x] = 'M';
				}
				else {
					level_grid[y + half_width][x] = ' ';
				}
			}
			half_width++; // Carve one block further down next iteration
		}
		x++; // Carve one block further to the right next iteration
	}

	// Traverse the level_grid and spawn objects based on the character in each coordinate on the grid
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; j++) {
			if (level_grid[i][j] == 'A') {
				Mountain *m = new Mountain();
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				m->setPosition(p);
				levelObjects.insert(m);
			}
			else if (level_grid[i][j] == '/') {
				Weapon *w = new Weapon(0);
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				w->setPosition(p);
				levelObjects.insert(w);
			}
			else if (level_grid[i][j] == 'M') {
				//Monster *m = new Monster();
				//df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				//m->setPosition(p);
				//levelObjects.insert(m);
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

void Level::changeRoom(int direction) {
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::ObjectListIterator li(&levelObjects);
	df::Position new_hero_pos;

	for (li.first(); !li.isDone(); li.next()) {
		world_manager.markforDelete(li.currentObject());
	}
	levelObjects.clear();
	df::ObjectList allObjects = world_manager.getAllobjects();
	df::ObjectListIterator all_iter(&allObjects);
	for (all_iter.first(); all_iter.isDone(); all_iter.next()) {
		if (li.currentObject()->getType() == "Wanderer"){
			Wanderer *p_w = dynamic_cast <Wanderer *> (li.currentObject());
			if (direction > 0) {
				new_hero_pos.setX(0);//getPosition().getX());
			}
			else if (direction < 0) {
				new_hero_pos.setX(getPosition().getX() + getWidth()-1);
			}
			else {
				new_hero_pos.setX((graphics_manager.getHorizontal()) / 2 + getPosition().getX());
				new_hero_pos.setY((graphics_manager.getVertical() / 2) - 2);
			}
			p_w->setPosition(new_hero_pos);
		}
	}
	generateLevel();
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