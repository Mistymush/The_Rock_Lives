//A_star header file
//Author: Marco Duran
//System includes
#include <queue>
#include <string>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <ctime>
//Engine includes
#include "Position.h"
#include "Object.h"

const int horiz_world = 99;//amount of characters that can fit horizontally across the screen
const int vert_world = 24;//amount of characters that can fit 
static int node_map[horiz_world][vert_world];
static int closed_node_map[horiz_world][vert_world];//map of already tried nodes
static int open_node_map[horiz_world][vert_world];//map of not yet tried nodes
static int dir_node_map[horiz_world][vert_world];//map of directions
const int dir = 8; //number of possible directions the monster can go from anywhere
enum Direction{
	RIGHT = 0,
	UPRIGHT,
	UP,
	UPLEFT,
	LEFT,
	DOWNLEFT,
	DOWN,
	DOWNRIGHT,
};
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

class Node{
	
	private:
		//Current position 
		int x_pos;
		int y_pos;
		//total distance traveled to reach node
		int dist_traveled;
		//priority level
		int priority;

	public:
		//constructor
		Node(int xPos, int yPos, int dist, int pri);

		//getters
		//Position 
		int getXPosition() const;
		int getYPosition() const;
		//Distance
		int getDistance() const;
		//Priority
		int getPriority() const;

		//end getters

		//Method to update the priority
		void updatePriority(const int &x_dest, const int &y_dest);

		//Give more priority to going straight
		void changeDist(const int &i);

		//Estimation function for the remaining distance to goal
		const int &estimate(const int &x_dest, const int &y_dest) const;

		//Determine the priority
		friend bool operator<(const Node &a, const Node &b){
			return a.getPriority() > b.getPriority();
		}



};

