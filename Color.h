#ifndef _COLOR_H_
#define _COLOR_H_
//Colors Dragonfly recognizes
namespace df{
	enum Color{
		BLACK = 0,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE,
	};
}
//If color not specified, will use this.
const df::Color COLOR_DEFAULT = df::WHITE;
#endif