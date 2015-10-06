/*
header file which defines the StatsView class
*/

#ifndef _STATS_VIEW_
#define _STATS_VIEW_

#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

class StatsView : public df::Object{

private:

	//Wanderer with an inventory


public:

	StatsView();

	~StatsView();

	int eventHandler(const df::Event *p_e);

	void draw();


};



#endif /!_STATS_VIEW_