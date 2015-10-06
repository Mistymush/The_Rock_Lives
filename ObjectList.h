/*
Header file which define the object list class
*/



#ifndef OBJECT_LIST
#define OBJECT_LIST


const int MAX_OBJECTS = 5000;

//Engine includes
#include "Object.h"
#include "ObjectListIterator.h"


namespace df{

class Object;
class ObjectListIterator;

class ObjectList {

private:
	int count;					//count of objexts in list.
	Object *list[MAX_OBJECTS];  //Array of pointers to objexts.

public:
	friend class ObjectListIterator;

	//Default construtor.
	ObjectList();

	//Inset object pointer in list
	int insert(Object *p_o);

	//Remove objext pointer from list
	int remove(Object *p_o);

	//Clear list
	void clear();

	//Return count of number of objects in list
	int getCount() const;

	//Return true if list is empty, else false
	bool isEmpty() const;

	//Retrun true if list is full, else false.
	bool isFull() const;


};







}// end df

#endif// end OBJECT_LIST