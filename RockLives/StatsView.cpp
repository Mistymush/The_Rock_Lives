/*
File which defines method bodys of the Stats View Class
Author: August Beers
*/


#include "StatsView.h"
#include "Color.h"

/*
Constructor of inventory view object
*/
StatsView::StatsView(){
	setType("StatsView");
	//Set starting location


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

	df::Position stats(0, 1);
	graphics_manager.drawString(stats, "Health: ", df::LEFT_JUSTIFIED, df::RED);
	stats.setY(2);
	graphics_manager.drawString(stats, "Hunger: ", df::LEFT_JUSTIFIED, df::RED);
	stats.setY(3);
	graphics_manager.drawString(stats, "Strength: ", df::LEFT_JUSTIFIED, df::RED);
	
}