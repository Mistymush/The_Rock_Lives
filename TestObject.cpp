/*
File which defines test Object member funtions
*/

#include "TestObject.h"

using namespace df;

TestObject::TestObject(){

	display_string = "Press Space To exit Test";

	Object::setType("TestObject");
}

TestObject::~TestObject(){


}

void TestObject::draw(){
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();

	graphics_manager.drawString(getPosition(), display_string, df::LEFT_JUSTIFIED, df::RED);

}