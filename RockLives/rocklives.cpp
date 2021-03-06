/*
File whic contains main entry funtion of rock lives
*/


#include <math.h>

//Engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

//Game includes
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

	//Load in sounds
	df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	resource_manager.loadSound("sounds/hit_sound.wav" , "hit");
	resource_manager.loadSound("sounds/healing_sound.wav" , "heal");
	resource_manager.loadSound("sounds/pickup_sound.wav" , "pickup");
	resource_manager.loadSound("sounds/game_over.wav" , "game_over");

	//Load in background music
	resource_manager.loadMusic("sounds/rock_lives_bgm.wav" , "game_music");
	
	//Instantiate objects
	populateGameWorld();

	//Run the game
	game_manager.run();

	//Shut down the game
	game_manager.shutDown();
}


void populateGameWorld(){
	OutputView &ov = OutputView::getInstance();
	df::ResourceManager &resource_manager = df::ResourceManager::getInstance();
	df::Music *music = resource_manager.getMusic("game_music");
	music->play();
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
	new Armor(df::Position(56, 10));

	ov.setOutput("Welcome Wanderer to the mountains of Aggoroth! Many like you have entered this place but few have returned unscathed. Use the num pad or arrow keys to move and interact, press space to wait. Try to survive as long as you can!");
	
	
	

}
