/*
File which defines methods of the Object list class
*/


#include "ObjectList.h"



/*
Connstructor
*/
df::ObjectList::ObjectList(){
	count = 0;
}

/*
Clear the list, by reseting the index
*/
void df::ObjectList::clear(){
	count = 0;
}

/*
Insert an objext pointer into the list
*/
int df::ObjectList::insert(Object *p_o){
	for (int i = 0; i < count; i++){
		if (list[i] == p_o){
			return 0;
		}
	}

	if (count == MAX_OBJECTS){
		return -1;
	}
	list[count] = p_o;
	count++;
	return 0;
}

/*
remove an object from the list, then shift over the contents
*/
int df::ObjectList::remove(Object *p_o){
	for (int i = 0; i < count; i++){
		if (list[i] == p_o){
			for (int j = i; j < count - 1; j++){
				list[j] = list[j + 1];
			}	
			count--;
			return 0;
		}
	}

	return -1;
}


/*
Return count
*/
int df::ObjectList::getCount() const{
	return count;
}

/*
Returns true if the index is pointing slot 0, else returns false
*/
bool df::ObjectList::isEmpty() const{
	if (count == 0){
		return true;
	}
	else
		return false;

}

/*
Returns true when the list has reached its max capacity, else returns false
*/
bool df::ObjectList::isFull() const{
	if (count == MAX_OBJECTS){
		return true;
	}
	else
		return false;
}


