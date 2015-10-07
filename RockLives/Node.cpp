//A-star source file
//Author: Marco Duran
#include "Node.h"
std::string pathFind(const df::Position &posStart, const df::Position &posFinish);
//constructor
Node::Node(df::Position new_pos, int dist, int pri){
	pos = new_pos;
	dist_traveled = dist;
	priority = pri;
}

//getters
//Position 
df::Position Node::getPosition(){
	return pos;
}
//Distance
int Node::getDistance(){
	return dist_traveled;
}
//Priority
int Node::getPriority(){
	return priority;
}

//end getters

//Method to update the priority
void Node::updatePriority(const df::Position &new_pos){
	priority = dist_traveled + estimate(new_pos) * 10;//A*
}

//Give more priority to going straight
void Node::changeDist(const int &i){
	dist_traveled += (dir == 4 ? (i % 2 == 0 ? 10 : 14) : 10);
}

//Estimation function for the remaining distance to goal
const int &Node::estimate(const df::Position &new_pos) const{
	static df::Position posd;
	static int d;
	posd = df::Position((new_pos.getX() - pos.getX()),(new_pos.getY() - pos.getY()));

	//Euclidian distance
	d = static_cast<int>(sqrt((posd.getX() * posd.getX()) + (posd.getY()*posd.getY())));

	return(d);
}

//Determine the priority
/*bool operator<(const Node &a, const Node &b){
	return a.getPriority() > b.getPriority();
}
*/
//A-star
//Should return a string of direction digits
std::string pathFind(const df::Position &posStart, const df::Position &posFinish){
	return "";
}
