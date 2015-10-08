/*
File which defines method bodys of the Stats View Class
Author: August Beers
*/


#include "StatsView.h"
#include "Color.h"

/*
Constructor of inventory view object
*/
StatsView::StatsView(Wanderer *new_wanderer){
	setType("StatsView");

	my_wanderer = new_wanderer;
}


/*
Destructor of inventory veiw
*/
StatsView::~StatsView(){

}

/*
eventHandler
*/
int StatsView::eventHandler(const df::Event *p_e){



	return 0;
}

/*
Draw method
*/
void StatsView::draw(){
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();

	df::Position position(0, 0);
	graphics_manager.drawString(position, "Wanderer Stats", df::LEFT_JUSTIFIED, df::RED);

	df::Position tmp_position(20, 0);
	for (int i = 0; i < 5 ; i++){
		tmp_position.setY(i);
		graphics_manager.drawCh(tmp_position, '|', df::RED);
	}

	
	//Read correct information from the wanderer
	std::string hp;
	std::string hunger;
	std::string strength;
	std::ostringstream hp_convert;
	std::ostringstream hunger_convert;
	std::ostringstream strength_convert;


	hp_convert << my_wanderer->getHp();
	hunger_convert << my_wanderer->getHunger();
	strength_convert << my_wanderer->getStrength();

	hp = hp_convert.str();
	hunger = hunger_convert.str();
	strength = strength_convert.str();

	df::Position stats(0, 1);
	df::Position stats_output(8, 1);
	graphics_manager.drawString(stats, "Health: ", df::LEFT_JUSTIFIED, df::RED);
	graphics_manager.drawString(stats_output, hp, df::LEFT_JUSTIFIED, df::RED);

	stats.setY(2);
	stats_output.setXY(8,2);
	graphics_manager.drawString(stats, "Hunger: ", df::LEFT_JUSTIFIED, df::RED);
	graphics_manager.drawString(stats_output, hunger, df::LEFT_JUSTIFIED, df::RED);

	stats.setY(3);
	stats_output.setXY(10, 3);
	graphics_manager.drawString(stats, "Strength: ", df::LEFT_JUSTIFIED, df::RED);
	graphics_manager.drawString(stats_output, strength, df::LEFT_JUSTIFIED, df::RED);
	
}