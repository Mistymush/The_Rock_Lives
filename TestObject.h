/*
Header file which defines an object used to assist with testing
*/


#ifndef TEST_OBJECT
#define TEST_OBJECT



#include "Object.h"
#include "GraphicsManager.h"

namespace df{

	class TestObject : public Object
	{
	private:

		std::string display_string;

	public:

		TestObject();

		~TestObject();

		void draw();


	};

} //!df
#endif // !TEST_OBJECT
