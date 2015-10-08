#ifndef __WALL_H__
#define __WALL_H__

#include "GraphicsManager.h"
#include "Color.h"
#include "Object.h"

class Wall : public df::Object {

private:
	char icon;
	bool seen;
	df::Color color;

public:
	Wall();
	void setIcon(char new_icon);
	char getIcon();
	void setColor(df::Color new_color);
	void setSeen(bool is_seen);
	bool getSeen();
	df::Color getColor();
	void draw();
};

#endif // __WALL_H__