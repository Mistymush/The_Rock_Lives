/*
Header file which define the EventCollision file
*/

#ifndef EVENT_COLLISION
#define EVENT_COLLISION

#include "Event.h"
#include "Object.h"

namespace df{

	const std::string COLLISION_EVENT = "df::collision";

	class EventCollision : public Event {

	private:
		//Position of the collision
		Position pos; 
		//Object moving to cause collision
		Object *p_obj1;
		//object being hit
		Object *p_obj2;

	public:
		//Creates a collision event with pos (0,0) and NULL object pointers
		EventCollision();

		//Constructs a colision between 01 and 02 at given posistion p
		//Object 01 is the moving object that caused the collision
		EventCollision(Object *p_o1, Object *p_o2, Position p);

		//Destructs Oobjects
		~EventCollision();

		//Getters and Setters --

		//getter and setter for object that cuased collison
		Object *getObject() const;

		void setObject(Object *p_new_o1);

		//getter and setter for object that was hit
		Object *getHitObject() const;

		void setHitObject(Object *p_new_o2);

		//getters and setters for the position of the collision
		Position getPosition() const;

		void setPosition(Position new_pos);


	};


} //!df

#endif // !EVENT_COLLISION
