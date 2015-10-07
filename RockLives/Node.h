//A_star header file
//Author: Marco Duran
//System includes
#include <queue.h>
#include <string.h>
//Engine includes
#include "Position.h"
#include "Object.h"

const int horiz_world = 106;//amount of characters that can fit horizontally across the screen
const int vert_world = 24;//amount of characters that can fit 
static int map[horiz_world][vert_world];
static int closed_node_map[horiz_world][vert_world];//map of already tried nodes
static int open_node_map[horiz_world][vert_world];//map of not yet tried nodes
static int dir_node_map[horiz_world][vert_world];//map of directions
const int dir = 4; //number of possible directions the monster can go from anywhere
static int dx[dir] = { 1, 0, -1, 0 };
static int dy[dir] = { 0, 1, 0 - 1 };

class Node{
	
	private:
		//Current position 
		df::Position pos;
		//total distance traveled to reach node
		int dist_traveled;
		//priority level
		int priority;

	public:
		//constructor
		Node(df::Position pos, int dist, int pri);

		//getters
		//Position 
		df::Position getPosition();
		//Distance
		int getDistance();
		//Priority
		int getPriority();

		//end getters

		//Method to update the priority
		void updatePriority(const df::Position &new_pos);

		//Give more priority to going straight
		void changeDist(const int &i);

		//Estimation function for the remaining distance to goal
		const int &estimate(const df::Position &new_pos) const;

};

