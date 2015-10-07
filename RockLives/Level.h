#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "ObjectListIterator.h"

class Level : public df::Object{

private:
	int width;
	int height;
	char** level_grid;

public:
	Level();
	~Level();
	void setWidth(int new_width);
	int getWidth();
	void setHeight(int new_height);
	int getHeight();
	void freeGrid();
	void draw();
};

#endif // __LEVEL_H__