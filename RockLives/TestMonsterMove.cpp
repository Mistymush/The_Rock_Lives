/*
File whic contains main entry funtion of rock lives
*/


#include <math.h>

#include "GameManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "InventoryView.h"
#include "DaddyLongLegs.h"
#include "StatsView.h"
#include "Wanderer.h"
#include "OutputView.h"
#include "Level.h"
#include "Weapon.h"



void populateMonsterMove();
/*
int main(int argc, char *argv[]) {
	srand(time(NULL));
	df::LogManager &log_manager = df::LogManager::getInstance();


	//comment this out after development
	log_manager.setFlush(true);

	//Start up game manager
	df::GameManager &game_manager = df::GameManager::getInstance();
	if (game_manager.startUp())  {
		log_manager.WriteMessage("Game manager failed to start");
		game_manager.shutDown();
		return 0;
	}

	df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	resource_manager.loadSound("sounds/hit_sound.wav", "hit");
	resource_manager.loadSound("sounds/healing_sound.wav", "heal");
	resource_manager.loadSound("sounds/pickup_sound.wav", "pickup");
	resource_manager.loadSound("sounds/game_over.wav", "game_over");

	//Load in background music
	resource_manager.loadMusic("sounds/rock_lives_bgm.wav", "game_music");

	//Instantiate objects
	populateMonsterMove();

	//Run the game
	game_manager.run();

	//Shut down the game
	game_manager.shutDown();
}
*/

void populateMonsterMove(){
	OutputView &ov = OutputView::getInstance();

	Wanderer *wanderer = new Wanderer();
	//create an inventory view
	new InventoryView(wanderer);
	new StatsView(wanderer);
	//new Level;

	//create a new daddy long legs
	DaddyLongLegs *p_d = new DaddyLongLegs();
	p_d->setPosition(df::Position(wanderer->getPosition().getX() + 15, wanderer->getPosition().getY()));
	p_d->setSeen(true);
	//p_m->draw();
	



}