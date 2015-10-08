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



void populateMonsterMove();
/*
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
	populateMonsterMove();

	//Run the game
	game_manager.run();

	//Shut down the game
	game_manager.shutDown();
}

*/
void populateMonsterMove(){
	OutputView &ov = OutputView::getInstance();

	Wanderer *wanderer = new Wanderer;
	//create an inventory view
	new InventoryView(wanderer);
	new StatsView;

	//create a new monster
	Monster *p_m = new Monster();
	p_m->setPosition(df::Position(wanderer->getPosition().getX() + 15, wanderer->getPosition().getY()));
	//p_m->draw();
	



}