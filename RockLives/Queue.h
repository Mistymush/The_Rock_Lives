//Creates a FIFO queue to process the Breadth First Search
//Node for the position of the monster
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Position.h"
#include "Object.h"
struct node{
	df::Position pos;
	node *next;
};

class Queue{
	private:
		node *head;
		node *tail;
	public:
		Queue();
		~Queue();
		bool isEmpty();
		void enqueue(df::Position);
		df::Position dequeue();
		
};
#endif