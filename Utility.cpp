/*
File contailing ultility method definitions
*/


//Project includes
#include "Utility.h"
#include "Node.h"

/*
Constructor of utility class
*/
df::Utility::Utility(){

}


/*
Destuctor of utility class
*/
df::Utility::~Utility(){

}


/*
Method which returns the current time from  the system call time()
*/
char *df::Utility::getTimeString(){

	//Output string
	static char time_str[30];

	//System call to get time
	time_t now;
	time(&now);
	struct tm *p_time = localtime(&now);
	

	// '02' goves twp digets, %d for integers.
	sprintf(time_str, "%02d:%02d:%02d",
		p_time->tm_hour,
		p_time->tm_min,
		p_time->tm_sec);

	return time_str;


}

bool df::Utility::positionsIntersect(Position p1, Position p2){
	if ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY())){
		return true;
	}
	else
	{
		return false;
	}
}


//A-star
//Should return a string of direction digits
//Author: Marco Duran
std::string df::Utility::pathFind(const int &x_start, const int &y_start, const int &x_finish, const int &y_finish){
	priority_queue<Node> pq[2];
	int open_node_map[horiz_world][vert_world];
	int dir_node_map[horiz_world][vert_world];
	int pqi; //priority queue index
	Node *p_node_1;
	Node *p_node_2;
	int i, j, x, y, xdx, ydy;
	char c;
	pqi = 0;
	x = 0;
	y = 0;

	//reset the node maps
	for (y = 0; y < vert_world; y++){
		for (x = 0; x < horiz_world; x++){
			open_node_map[x][y] = 1;
		}
	}

	//create the start node and push into list of open nodes
	p_node_1 = new Node(x_start, y_start, 0, 0);
	p_node_1->updatePriority(x_finish, y_finish);
	pq[pqi].push(*p_node_1);
	open_node_map[x_start][y_start] = p_node_1->getPriority(); //mark it on the open nodes map

	//A* search
	while (!pq[pqi].empty()){
		//get the current node with the highest priority
		//from the list of open nodes
		p_node_1 = &pq[pqi].top();
		x = p_node_1->getXPosition();
		y = p_node_1->getYPosition();
		pq[pqi].pop(); //remove the node from the open list
		open_node_map[x][y] = 0;

		//Quit searching when the goal state is reached
		if (x == x_finish && y == y_finish){
			//generate the path from finish to start
			// by following the directions
			std::string path = "";
			while (!(x == x_start && y == y_start)){
				j = dir_node_map[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += dx[j];
				y += dy[j];
			}
			//empty the leftover nodes
			while (!pq[pqi].empty())
				pq[pqi].pop();

			return path;
		}

		//generate moves (for child nodes) in all possible directions
		for (i = 0; i < dir; i++){
			xdx = x + dx[i];
			ydy = y + dy[i];

			if (!(xdx < 0 || xdx > horiz_world - 1
				|| ydy < 0 || ydy > vert_world - 1
				|| open_node_map[xdx][ydy] == 0)){

				//generate a child node
				p_node_2 = new Node(xdx,ydy, p_node_1->getDistance(),
					p_node_1->getPriority());
				p_node_2->changeDist(i);
				p_node_2->updatePriority(x_finish, y_finish);
				//updates to say that it is not an open spot on the map
				open_node_map[xdx][ydy] = 0;
				pq[pqi].push(*p_node_2);
				//mark its parent node direction
				dir_node_map[xdx][ydy] = (i + dir / 2) % dir;
			}
		}
	}
	return ""; //no route found
}
