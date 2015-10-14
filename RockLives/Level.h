#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "ObjectListIterator.h"

class Level : public df::Object{

private:
	int width;
	int height;
	int max_path_width;
	int min_path_width;
	char** level_grid;
	df::Position start_pos;
	df::Position end_pos;
	df::ObjectList levelObjects;

public:
	Level();
	~Level();
	void generateLevel();
	void setWidth(int new_width);
	int getWidth();
	void setHeight(int new_height);
	int getHeight();
	df::ObjectList getLevelObjects();
	void freeGrid();
	void addToRoom(Object *p_o);
	/* Change to a new randomly generated room, moving the player to the appropriate location.
	*  Direction is based on which side of the screen the player moved out of before the room change.
	*  If direction is less than 0, the player should be moved to the right side of the screen in the new room.
	*  If direction is greater than 0, the player should be moved to the left side of the screen in the new room.
	*  If direction is equal to 0, the player should be moved to the center of the room.
	*/
	void changeRoom(int direction);
	void draw();
};

#endif // __LEVEL_H__