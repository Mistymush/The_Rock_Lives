#ifndef __MOUNTAIN_H__
#define __MOUNTAIN_H__

#include "Wall.h"
#include "GraphicsManager.h"
#include "Color.h"

class Mountain : public Wall {

private:
	char icon;
	df::Color color;

public:
	Mountain();
};

#endif // __MOUNTAIN_H__