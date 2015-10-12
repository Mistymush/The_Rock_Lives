//A-star source file
//Author: Marco Duran
#include "Node.h"
//constructor
Node::Node(int x_p, int y_p, int dist, int pri){
	x_pos = x_p;
	y_pos = y_p;
	dist_traveled = dist;
	priority = pri;
}

//getters
//Position 
 int Node::getXPosition() const{
	return x_pos;
}

 int Node::getYPosition() const{
	 return y_pos;
 }
//Distance
int Node::getDistance() const {
	return dist_traveled;
}
//Priority
int Node::getPriority() const{
	return priority;
}

//end getters

//Method to update the priority
void Node::updatePriority(const int &x_dest, const int &y_dest){
	priority = dist_traveled + estimate(x_dest, y_dest) * 10;//A*
}

//Give more priority to going straight
void Node::changeDist(const int &i){
	dist_traveled += (dir == 4 ? (i % 2 == 0 ? 10 : 14) : 10);
}

//Estimation function for the remaining distance to goal
const int &Node::estimate(const int &x_dest, const int &y_dest) const{
	static int xd, yd;
	static int d;
	xd = x_dest - x_pos;
	yd = y_dest - y_pos;

	//Euclidian distance
	d = static_cast<int>(sqrt(xd*xd+yd*yd));

	// Manhattan distance
	//d=abs(xd)+abs(yd);

	// Chebyshev distance
	//d=max(abs(xd), abs(yd));

	return(d);
}

