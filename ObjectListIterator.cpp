/*
File which defines Oject Iterator class methods
*/

#include "ObjectListIterator.h"



/*
Constructr an iterator objext
*/
df::ObjectListIterator::ObjectListIterator(ObjectList *p_l){
	p_list = p_l;
	int index = 0;
}

/*
Set iterator to first item in list
*/
void df::ObjectListIterator::first(){
	index = 0;
}

//incriment iterator
void df::ObjectListIterator::next(){
	if (index < p_list -> count){
		index++;
	}
}

//returns true when we reach the end of the list
bool df::ObjectListIterator::isDone() const{
	return (index == p_list->count);
}

//Return a pointer to the current object.
df::Object *df::ObjectListIterator::currentObject() const{
	return p_list->list[index];
}