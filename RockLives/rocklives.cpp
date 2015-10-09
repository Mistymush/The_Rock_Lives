/*
File whic contains main entry funtion of rock lives
*/


#include <math.h>


#include "GameManager.h"
#include "LogManager.h"
#include "InventoryView.h"
#include "Monster.h"
#include "StatsView.h"
#include "Wanderer.h"
#include "OutputView.h"
#include "Level.h"
#include "Weapon.h"
#include "Armor.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "FoodRation.h"



void populateGameWorld();

int main(int argc, char *argv[]) {
	df::LogManager &log_manager = df::LogManager::getInstance();
	srand(time(NULL));

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
	p_m->setPosition(df::Position(68, 12));
	p_m->draw();

	Wanderer *wanderer = new Wanderer();
	//create an inventory view
	new InventoryView(wanderer);
	new StatsView(wanderer);
	new Level;

	new Weapon(49);
	new Weapon(50);
	new Weapon(51);

	new Armor(df::Position( 52, 10));
	new HealthPotion(df::Position(53, 10));
	new StrengthPotion(df::Position(54, 10));
	new FoodRation(df::Position(55, 10));

	
	
	

}
