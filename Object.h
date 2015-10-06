/*
header file which defines the game object class
*/

#ifndef OBJECT
#define OBJECT

//System includes
#include <string>

//Engine includes
#include "Position.h"
#include "Event.h"
#include "math.h"
#include "GraphicsManager.h"


namespace df{

	enum Solidness {
		HARD, // Objects cause collisions and impede.
		SOFT, // Objects cause collisions, but don't impede
		SPECTRAL // Objects don't cause collisions.
	};


	class Object{

	private:
		int id; //unique id of oject
		std::string type; //string type representation
		Position pos; //Object position in game world
		int altitude; //0 to max


		Solidness solidness; // Solidness of object

		//Variables relating to object movement
		float x_velocity;
		float x_velocity_countdown;
		float y_velocity;
		float y_velocity_countdown;

	public:
		//Construct Object and add to the game world
		Object();

		//Destruct object and remove from game world
		virtual ~Object();

		//Generic Event Handler
		virtual int eventHandler(const df::Event *p_e);

		//Objects should be able to draw themselvs
		virtual void draw();

		//getter and setters

		//Set Object id
		void setID(int new_id);

		//get object id
		int getId() const;

		//set type
		void setType(std::string new_type);

		//get object ype
		std::string getType();

		//Set position object
		void setPosition(Position new_pos);

		//Get position of object
		Position getPosition() const;

		//altitude controll
		int setAltitude(int new_altitude);

		//Return object altitude
		int getAltitude() const;

		//velocity getters and setters
		void setXVelocity(float new_x_velocity);
		float getXVelocity() const;
		void setYVelocity(float new_y_velocity);
		float getYVelocity() const;
		int getXVelocityStep();
		int getYVelocityStep();

		//Solidness methods

		// True if HARD or SOFT, else false.
		bool isSolid(); 

		int setSolidness(Solidness new_solid);

		Solidness getSolidness() const;

	};






}// end df


#endif //end OBJECT