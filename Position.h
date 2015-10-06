/*
Header file which defines the position class

*/

#ifndef POSITION
#define POSITION

namespace df{

	class Position {

	private:
		int x; //Horizontal coor
		int y; //vertical coor




	public:

		//Create object at 2d location (x,y)
		Position(int init_x, int init_y);

		//Default 2d (x,y) location is (0,0)
		Position();

		//get set
		void setX(int newValue);
		int getX() const;
		void setY(int newValue);
		int getY() const;

		//Set horizonatl & vertical coordinates.
		void setXY(int new_x, int new_y);



	}; //end class
}//end df

#endif //end POSTITION