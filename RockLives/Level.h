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

public:
	Level();
	~Level();
	void generateLevel();
	void setWidth(int new_width);
	int getWidth();
	void setHeight(int new_height);
	int getHeight();
	void freeGrid();
	void draw();
};

#endif // __LEVEL_H__