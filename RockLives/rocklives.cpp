/*
File whic contains main entry funtion of rock lives
*/




#include "GameManager.h"
#include "LogManager.h"
#include "InventoryView.h"
#include "Monster.h"
#include "StatsView.h"
#include "Wanderer.h"
#include "OutputView.h"
#include "Level.h"
#include "Weapon.h"



void populateGameWorld();

int main(int argc, char *argv[]) {
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



	//Instantiate objects
	populateGameWorld();

	//Run the game
	game_manager.run();

	//Shut down the game
	game_manager.shutDown();
}


void populateGameWorld(){
	OutputView &ov = OutputView::getInstance();
	
	
	//create a new monster
	Monster *p_m = new Monster();
	p_m->setPosition(df::Position(10, 10));
	p_m->draw();

	Wanderer *wanderer = new Wanderer;
	//create an inventory view
	new InventoryView(wanderer);
	new StatsView;
	//new Level;
	new Weapon(30);
	new Weapon(31);

	new Weapon(33);
	new Weapon(34);
	new Weapon(35);
	new Weapon(36);
	new Weapon(37);
	new Weapon(38);
	new Weapon(38);
	new Weapon(39);
	new Weapon(40);
	new Weapon(41);
	
	

}