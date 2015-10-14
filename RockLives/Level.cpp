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
#include "Wanderer.h"
#include "LevelGoal.h"
#include "FoodRation.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "Armor.h"

Level::Level() {
	setType("Level");

	level_number = 0;

	setPosition(df::Position(21, 0));

	setWidth(92);
	setHeight(19);

	max_path_width = 12;
	min_path_width = 3;

	start_pos = df::Position(0, (height / 2));
	end_pos = df::Position(width - 1, (height / 2)+2);

	level_grid = new char*[height]; // Initialize an the level grid as an array of char arrays
	for (int i = 0; i < height; ++i) { // For each row of the grid...
		level_grid[i] = new char[width]; // Initialize an array of chars
	}
	generateLevel();
}

/* Generates a brand new level layout, creating a character array representing the level and populating the
*  level based on that character array.
*/
void Level::generateLevel() {
	level_number++;
	// The starting and ending x and y positions of the path that will be carved out
	int start_x = start_pos.getX();
	int start_y = start_pos.getY();
	int end_x = end_pos.getX();
	int end_y = end_pos.getY();
	// The x and y values that update as the algorithm traverses level grid
	int x = start_pos.getX();
	int y = start_pos.getY();

	// Fill the level grid with mountain characters
	for (int i = 0; i < height; ++i) { // For each row of the grid...
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
				if (y + half_width > 0 && y + half_width < height) {
					int item_chance = rand() % 300; // Weapon spawn rate
					int armor_chance = rand() % 300; // Armor spawn rate
					int potion_chance = rand() % 300; // Potion spawn rate
					int food_chance = rand() % 300; // Food spawn rate
					int monster_chance = rand() % 200; // Monster spawn rate
					if (y + half_width == start_y + 2 && x == start_x + 4 && level_number == 1) {
						level_grid[y + half_width][x] = 'F';
					}
					else if (y + half_width == end_y && x == end_x) {
						level_grid[y + half_width][x] = '>';
					}
					else if (item_chance == 0) {
						level_grid[y + half_width][x] = '/';
					}
					else if (armor_chance == 0) {
						level_grid[y + half_width][x] = 't';
					}
					else if (potion_chance == 0) {
						level_grid[y + half_width][x] = '!';
					}
					else if (food_chance == 0) {
						level_grid[y + half_width][x] = 'F';
					}
					else if (monster_chance == 0) {
						level_grid[y + half_width][x] = 'M';
					}
					else {
						level_grid[y + half_width][x] = ' ';
					}
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
			else if (level_grid[i][j] == '>') {
				LevelGoal *lg = new LevelGoal(this);
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				lg->setPosition(p);
				levelObjects.insert(lg);
			}
			else if (level_grid[i][j] == '/') {
				Weapon *w = new Weapon(0);
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				w->setPosition(p);
				levelObjects.insert(w);
			}
			else if (level_grid[i][j] == 't') {
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				Armor *a = new Armor(p);
				levelObjects.insert(a);
			}
			else if (level_grid[i][j] == '!') {
				int which_potion = rand() % 4;
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				if (which_potion = 0) {
					StrengthPotion *sp = new StrengthPotion(p);
					levelObjects.insert(sp);
				}
				else {
					HealthPotion *hp = new HealthPotion(p);
					levelObjects.insert(hp);
				}
			}
			else if (level_grid[i][j] == 'F') {
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				FoodRation *fr = new FoodRation(p);
				levelObjects.insert(fr);
			}
			else if (level_grid[i][j] == 'M' && j < width && j > 5) { // 5 is spaces to the right from the left side of the room; prevents monsters from spawning next to Wanderer
				Monster *m = new Monster();
				df::Position p = df::Position(j + getPosition().getX(), i + getPosition().getY());
				m->setPosition(p);
				levelObjects.insert(m);
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

int Level::getLevelNumber() {
	return level_number;
}

void Level::freeGrid() {
	for (int i = 0; i < width; ++i) {
		delete[] level_grid[i];
	}
	delete[] level_grid;
}

void Level::addToRoom(Object *p_o) {
	levelObjects.insert(p_o);
}

void Level::changeRoom(int direction) {
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	df::ObjectListIterator li(&levelObjects);
	df::Position new_hero_pos;
	df::ObjectList remove_from_room;

	for (li.first(); !li.isDone(); li.next()) {
		if (Item *p_i = dynamic_cast <Item *> (li.currentObject())) { // If an object in the room is an item...
			if (p_i->getInInventory()) { // Check if it's in the Wanderer's inventory. If it is...
				remove_from_room.insert(li.currentObject()); // Remove it from the room object list so it isn't destroyed at room switch.
			}
			else { // If it's not in the Wanderer's inventory...
				world_manager.markforDelete(li.currentObject()); // Destroy it with the room.
			}
		}
		else { // If it isn't an item, destroy it with the room.
			world_manager.markforDelete(li.currentObject());
		}
	}

	// Remove any items from the room list that must persist until the next room (Items in inventory, basically)
	df::ObjectListIterator rm_iter(&remove_from_room);
	for (rm_iter.first(); !rm_iter.isDone(); rm_iter.next()) {
		levelObjects.remove(rm_iter.currentObject());
	}

	remove_from_room.clear();
	levelObjects.clear();

	df::ObjectList allObjects = world_manager.getAllobjects();
	df::ObjectListIterator all_iter(&allObjects);
	for (all_iter.first(); !all_iter.isDone(); all_iter.next()) {
		if (all_iter.currentObject()->getType() == "Wanderer"){
			Object *p_o = all_iter.currentObject();
			new_hero_pos.setX(this->getPosition().getX());
			new_hero_pos.setY(start_pos.getY()+2);
			p_o->setPosition(new_hero_pos);
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