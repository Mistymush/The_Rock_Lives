/*
Header file which defines the world manager, a singleton class
*/

#ifndef WORLD_MANAGER
#define WORLD_MANAGER

//Engine includes
#include "Manager.h"
#include "GraphicsManager.h"
#include "ObjectList.h"
#include "EventStep.h"
#include "Utility.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "ObjectListIterator.h"

namespace df{

	const int MAX_ALTTITUDE = 6;

	class Manager;

	class WorldManager : public df::Manager {

	private:
		//Singleton behaivior
		WorldManager();
		WorldManager(WorldManager const&);
		void operator=(WorldManager const&);

		//All objects in world to update
		ObjectList updates;
		//All objects in the world to delete
		ObjectList deletions;

	public:
		//Get the instance of the world manager
		static WorldManager &getInstance();


		//Destructor
		~WorldManager();

		//Startup game world(initialize everything to empty).
		//Return 0.
		int startUp();

		//Shutdown game world(delete all game owrl objects)
		void shutDown();

		//Add an object to world
		int insertObject(Object *p_o);

		//Remove an object from the world
		int removeObject(Object *p_o);

		//Return a list of objects in world
		ObjectList getAllobjects(void) const;

		//update world
		//delete all objects marked for deletion
		void update();

		//Indicate Object is to be deleted at the end of current game loop
		int markforDelete(Object *p_o);

		//ask all objects to draw themselvs
		void draw();

		//Returns list of Objects collided with at Position 'where'
		//Collusuibs onyl happen to solid objects
		//Does not consider if p_o is solid or not
		ObjectList isCollision(Object *p_o, Position where) const;

		//Move object, atempts to move object. if no collision with solid 
		//object move is ok
		int moveObject(Object *p_o, Position where);

	};

}//edn df

#endif // end WORLD_MANAGER
