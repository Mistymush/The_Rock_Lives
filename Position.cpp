/*
File which deffine the methods of the Position class
*/

#include "Position.h"
using namespace df;

/*
Constructor for a position object
arg1: x position
arg2: y position
*/
Position::Position(int init_x, int init_y){
	x = init_x;
	y = init_y;
}

/*
Default constructor, sets values eqault to top left corner
*/
Position::Position(){
	x = 0;
	y = 0;
}

/*
Seters and gettes
*/

int Position::getX() const{
	return x;
}

int Position::getY() const{
	return y;
}

void Position::setX(int newValue){
	x = newValue;
}

void Position::setY(int newValue){
	y = newValue;
}

void Position::setXY(int new_X, int new_Y){
	x = new_X;
	y = new_Y;
}
