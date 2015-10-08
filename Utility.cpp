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
std::string df::Utility::pathFind(const df::Position &posStart, const df::Position &posFinish){
	static priority_queue<Node> pq[2];
	static int pqi; //priority queue index
	static Node *p_pos1;
	static Node *p_pos2;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqi = 0;

	//reset the node maps
	for (y = 0; y < vert_world; y++){
		for (x = 0; x < horiz_world; x++){
			closed_node_map[x][y] = 0;
			open_node_map[x][y] = 0;
		}
	}

	//create the start node and push into list of open nodes
	p_pos1 = new Node(posStart, 0, 0);
	p_pos1->updatePriority(posFinish);
	pq[pqi].push(*p_pos1);
	open_node_map[x][y] = p_pos1->getPriority(); //mark it on the open nodes map

	//A* search
	while (!pq[pqi].empty()){
		//get the current node with the highest priority
		//from the list of open nodes
		p_pos1 = new Node(pq[pqi].top().getPosition(), pq[pqi].top().getDistance(), pq[pqi].top().getPriority());
		x = p_pos1->getPosition().getX();
		y = p_pos1->getPosition().getY();
		pq[pqi].pop(); //remove the node from the open list
		open_node_map[x][y] = 0;
		//mark it on closed nodes
		closed_node_map[x][y] = 1;

		//Quit searching when the goal state is reached
		//if((*p_pos).estimate(posFinish) == 0)
		if (x == posFinish.getX() && y == posFinish.getY()){
			//generate the path from finish to start
			// by following the directions
			std::string path = "";
			while (!(x == posStart.getX() && y == posStart.getY())){
				j = dir_node_map[x][y];
				c = '0' + ((j + dir / 2) % dir) + ',';
				path = c + path;
				x += dpos[j].getX();
				y += dpos[j].getY();
			}
			//garbage collection
			delete p_pos1;
			//empty the leftover nodes
			while (!pq[pqi].empty())
				pq[pqi].pop();

			return path;
		}

		//generate moves (for child nodes) in all possible directions
		for (i = 0; i < dir; i++){
			xdx = x + dpos[i].getX();
			ydy = y + dpos[i].getY();

			if (!(xdx < 0 || xdx > horiz_world - 1
				|| ydy < 0 || ydy > vert_world - 1
				|| closed_node_map[xdx][ydy] == 1)){

				//generate a child node
				p_pos2 = new Node(df::Position(xdx, ydy), p_pos1->getDistance(),
					p_pos1->getPriority());
				p_pos2->changeDist(i);
				p_pos2->updatePriority(posFinish);

				//if it is not in the open list then
				if (open_node_map[xdx][ydy] == 0){
					open_node_map[xdx][ydy] = p_pos2->getPriority();
					pq[pqi].push(*p_pos2);
					//mark its parent node direction
					dir_node_map[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if (open_node_map[xdx][ydy] > p_pos2->getPriority()){
					//update the priority info
					open_node_map[xdx][ydy] = p_pos2->getPriority();
					//update the parent direction info
					dir_node_map[xdx][ydy] = (i + dir / 2) % dir;

					//replace the node 
					//empty one queue to the other one
					//except the node to be replaced will be ignored
					//and the new node will be pushed in instead
					while (!(pq[pqi].top().getPosition().getX() == xdx &&
						pq[pqi].top().getPosition().getY() == ydy)){
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop(); //remove the wanted node

					//empty the larger size pq to the smaller one
					if (pq[pqi].size() > pq[1 - pqi].size())
						pqi = 1 - pqi;

					while (!pq[pqi].empty()){
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi = 1 - pqi;
					pq[pqi].push(*p_pos2); //add the better node instead
				}
				else
					delete p_pos2; //garbage collection
			}
		}
		delete p_pos1; //garbage collection
	}
	return ""; //no route found
}
