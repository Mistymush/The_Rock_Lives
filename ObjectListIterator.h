/*
Header which define the ObjectListItereator class
*/

#ifndef OBJECT_LIST_ITERATOR
#define OBJECT_LIST_ITERATOR

//engine includes
#include "ObjectList.h"
#include "Object.h"

namespace df{

	class Object;
	class ObjectList;

	class ObjectListIterator{
	private:
		//a point to the list, which cannot be changed
		const ObjectList *p_list;

		//the iundex of the intem in the list we are looking at
		int index;

	public:

		//constructor
		ObjectListIterator(ObjectList *p_l);

		//Set iterator to first item in list
		void first();
		//incriment iterator
		void next();
		//returns true when we reach the end of the list
		bool isDone() const;

		//Return a pointer to the current object.
		Object *currentObject() const;
	};


} // end df



#endif // end OBJECT_LIST_ITERATOR