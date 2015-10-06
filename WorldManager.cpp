/*
File which defines the methods og the world manager class
*/


#include "WorldManager.h"
#include "LogManager.h"

using namespace df;

/*
Default Constructor
*/
WorldManager::WorldManager(){

	df::Manager::setType("WorldManager");
	updates = ObjectList();
	deletions = ObjectList();

}

/*
Default destructor
*/
WorldManager::~WorldManager(){

}


/*
Meethod which returns the current instance of the WorldManger
*/

WorldManager &WorldManager::getInstance(){
	static df::WorldManager single;
	return single;
}


/*
Method which starts up the world manager
*/
int WorldManager::startUp(){


	return df::Manager::startUp();
	
}

/*
Methoid which shuts down the world manager
*/
void WorldManager::shutDown(){

	//Delete all objects
	ObjectList p_ol = updates;
	df::ObjectListIterator *li = new df::ObjectListIterator(&p_ol);
	for (li->first(); !li->isDone(); li->next()){
		li->currentObject()->~Object();
	}
	updates.clear();
	

	//Empty deletions list
	ObjectList p_dl = deletions;
	df::ObjectListIterator *ld = new df::ObjectListIterator(&p_dl);
	for (ld->first(); !ld->isDone(); ld->next()){
		ld->currentObject()->~Object();
	}
	deletions.clear();
	


	Manager::shutDown();

}


/*
Method which inserts an object into the game world
*/
int WorldManager::insertObject(df::Object *p_o){
	return updates.insert(p_o);
}

/*
Method which removes an object from the game world
*/
int WorldManager::removeObject(df::Object *p_o){
	return updates.remove(p_o);
}


/*
Method which deletes all object marked for deletion
*/
void WorldManager:: update(){
	//Provide step event to all Objects - move this into update
	EventStep s;
	onEvent(&s);


	//delete the objects in the deletion list
	ObjectList p_dl = deletions;
	df::ObjectListIterator ld =  df::ObjectListIterator(&p_dl);
	for (ld.first(); !ld.isDone(); ld.next()){
		updates.remove(ld.currentObject());		
	}
	deletions.clear();

	//udpade object positions based on their velocities
	int x = -1, y = -1; // poetntial new postition of object
	df::ObjectListIterator lu = df::ObjectListIterator(&updates);
	while (!lu.isDone()){
		x = lu.currentObject()->getXVelocityStep();
		y = lu.currentObject()->getYVelocityStep();
		
		if (x || y){
			Position old_position = lu.currentObject()->getPosition();
			Position new_position = Position(old_position.getX() + x,
				old_position.getY() + y);
			moveObject(lu.currentObject(), new_position);
		}
		lu.next();
	}//end while

	
	//Iterate through game objects to see if a collision has occured
	/*
	Position tmp_pos;
	ObjectList collisions;
	df::ObjectListIterator luc = ObjectListIterator(&updates);
	while (!luc.isDone()){

		collisions = isCollision(luc.currentObject(),luc.currentObject()->getPosition());
		df::ObjectListIterator lucc = ObjectListIterator(&collisions);

		//Iterate with list of collisions with the current object passsing a collision event to each object
		while (!lucc.isDone()){
			EventCollision new_collision = EventCollision(luc.currentObject(), 
				lucc.currentObject(), luc.currentObject()->getPosition());

				lucc.currentObject()->eventHandler(&new_collision);
				lucc.next();
		}

		luc.next();
	}
	
	*/

}

/*
Marks an object for deletion
*/
int WorldManager::markforDelete(df::Object *p_o){
	return deletions.insert(p_o);
}

/*
Returns the object list
*/
ObjectList WorldManager::getAllobjects(void) const{
	return updates;
}

/*
ask all objects to draw themselvs
*/
void WorldManager::draw(){

	ObjectListIterator *li = new ObjectListIterator(&updates);
	//for loop that enforeces drawing by alttitude
	for (int alt = 0; alt < MAX_ALTTITUDE; alt++){
		while (!li->isDone()){	
			if (li->currentObject()->getAltitude() == alt){
				Object tmp_obj = *li->currentObject();
				li->currentObject()->draw();
			}
			li->next();
		}
		li->first();
	}
}

/*
Return a list of objects collided at position where. Collsiosns only occur
between solide objects.
P-o's solidness is not considered
*/
ObjectList WorldManager::isCollision(Object *p_o, Position where) const{

	Utility utility; //object for reference
	//Make empty list
	ObjectList collision_list;

	//Create an iterator of the current objects
	
	ObjectListIterator lu(&getAllobjects());

	while (!lu.isDone()){

		Object *p_temp_o = lu.currentObject(); 

		if (p_temp_o != p_o){//Do not consider self

			if (utility.positionsIntersect(p_temp_o->getPosition(), where) //check location
			&& p_temp_o->isSolid() && p_o->isSolid()){ //check if solid

			//if not self and solid and at correct position add to current collisions list
			collision_list.insert(p_temp_o);

			}//no solid collision 

		}//not self

		lu.next();
		
	}//end while

	
	return collision_list;

}


/*
Move the object pointed to to postion where(in asc11 spaces)
*/
int WorldManager::moveObject(Object *p_o, Position where){
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();

	if (p_o->isSolid()){ //collisions only matter for solid objects
		bool doMove = true;
		//Get collisions
		ObjectList list = isCollision(p_o, where);
		//if we have collided with something
		if (!list.isEmpty()){
			
			//Itereate accross list
			ObjectListIterator li = ObjectListIterator(&list);
			while (!li.isDone()){
				Object *p_temp_o = li.currentObject();

				//Create collision event
				EventCollision collision(p_o, p_temp_o, where);

				//send to both objects
				p_o->eventHandler(&collision);
				p_temp_o->eventHandler(&collision);

				//if both objects are hard move fails
				if (p_o->getSolidness() == HARD && p_temp_o->getSolidness() == HARD){
					doMove = false;
				}


				li.next();
			}// end iterator while

			if (!doMove){
				return -1;
			}

		}// end list is not empty ( no collision
	}//Object not solid



	p_o->setPosition(where);


	//Check to see if moving out of bounds
	if (where.getX() < 0
		|| (where.getX() >= graphics_manager.getHorizontal())
		|| where.getY() < 0
		|| (where.getY() >= graphics_manager.getVertical())){
		EventOut ov = EventOut();
		p_o->eventHandler(&ov);
	}

	return 0;
}