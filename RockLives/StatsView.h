/*
header file which defines the StatsView class
author: August Beers
*/

#ifndef _STATS_VIEW_
#define _STATS_VIEW_

#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Position.h"
#include "Wanderer.h"

//engine includes
#include <sstream>


class StatsView : public df::Object{

private:

	//Wanderer with an inventory
	Wanderer *my_wanderer;


public:

	StatsView(Wanderer *new_wanderer);

	~StatsView();

	int eventHandler(const df::Event *p_e);

	void draw();


};



#endif /!_STATS_VIEW_