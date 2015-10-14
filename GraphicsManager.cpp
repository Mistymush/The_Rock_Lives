/*
File which defines the memeber funtions of the GraphicsManager class
*/

#include "GraphicsManager.h"
#include "Color.h"

using namespace df;


//Constuctor
GraphicsManager::GraphicsManager(){
	
	df::Manager::setType("GraphicsManager");
	
	window_horizontal_pixels = WINDOW_HORIZONTAL_PIXEDLS_DEFAULT;
	window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;

	window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
	window_vetical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;

}

GraphicsManager::GraphicsManager(GraphicsManager const&){

}

//Get the singleton instance of the GameManager.
GraphicsManager &GraphicsManager::getInstance(){
	static GraphicsManager single;
	return single;
}

int GraphicsManager::startUp(){

	//get the log manger for erros
	LogManager &log_manager = LogManager::getInstance();



	//check to see if the window has already been drawn, if so we have no work to do
	if (!(p_window == NULL)){
		return 0;
	}

	p_window =
		new sf::RenderWindow(sf::VideoMode(window_horizontal_pixels, window_vertical_pixels),
		"Rock Lives", WINDOW_STYLE_DEFAULTa | WINDOW_STYLE_DEFAULTb);

	if (p_window == NULL){
	log_manager.WriteMessage("Error! failed to initialize render window, graphics start up failed");
		return -1;
	}

	//Clear the screen so it is black
	p_window->clear(WINDOW_BACKGROUND_COLOR_DEFAULT);

	//remove mouse curser from window
	p_window->setMouseCursorVisible(false);

	//sycronize refresh rate with monitor
	p_window->setVerticalSyncEnabled(true);


	if (font.loadFromFile(FONT_FILE_DEFAULT) == false) {
		log_manager.WriteMessage("Error! unable to load font (Graphics Manager)! , graphics start up failed");
		return -1;
	}
	else {
		Manager::startUp();
		return 0;
	}

}

//this is broke
int GraphicsManager::shutDown(){
	
	p_window->close();
	
	Manager::shutDown();
	return 0;

}


/*
Method which draws a character to a specified loction with a specified color
*/
int GraphicsManager::drawCh(Position pos, char ch, Color color) const{

	LogManager &log_manager = LogManager::getInstance();
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();

	//first make sure that window exits
	if (p_window == NULL){
		log_manager.WriteMessage("Cannot drawCH becuase window is NULL");
		return -1;
	}
	
	

	//Convert spaces to pixes
	Position pixel_pos = graphics_manager.spacesToPixels(pos);

	//Draw background rectangle
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(graphics_manager.charWidth(), graphics_manager.charHeight() - 1));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(pixel_pos.getX() + graphics_manager.charWidth() / 2 - 5,
						  pixel_pos.getY() + graphics_manager.charHeight() / 2 - 12);
	p_window->draw(rectangle);

	//Create charcter text to draw
	static sf::Text text("", font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold); //Bold or die

	//scale to right size
	if (graphics_manager.charWidth() < graphics_manager.charHeight()){
		text.setCharacterSize((int)graphics_manager.charWidth() * 2);
	}
	else{
		text.setCharacterSize((int)graphics_manager.charHeight() * 2);
	}

	//Set SFML color based on our colors
	switch (color)
	{
	case df::BLACK:
		text.setColor(sf::Color::Black);
		break;
	case df::RED:
		text.setColor(sf::Color::Red);
		break;
	case df::GREEN:
		text.setColor(sf::Color::Green);
		break;
	case df::YELLOW:
		text.setColor(sf::Color::Yellow);
		break;
	case df::BLUE:
		text.setColor(sf::Color::Blue);
		break;
	case df::MAGENTA:
		text.setColor(sf::Color::Magenta);
		break;
	case df::CYAN:
		text.setColor(sf::Color::Cyan);
		break;
	case df::WHITE:
		text.setColor(sf::Color::White);
		break;
	default:
		break;
	}
	
	text.setPosition((float)pixel_pos.getX(), (float)pixel_pos.getY());

	p_window->draw(text);

	return 0;

}


/*
Method which draws a string to a given location with a given color and justification
*/
int GraphicsManager::drawString(Position world_pos, std::string str, Justification just, Color color) const {

	//Get starting position
	Position starting_pos = world_pos;
	switch (just)
	{
	case df::LEFT_JUSTIFIED:
		break;
	case df::CENTER_JUSTIFIED:
		starting_pos.setX(world_pos.getX() - str.size() / 2);
		break;
	case df::RIGHT_JUSTIFIED:
		starting_pos.setX(world_pos.getX() - str.size());
		break;
	default:
		break;
	}


	//Darw string char by char
	for (unsigned int i = 0; i < str.size(); i++){
		Position temp_pos(starting_pos.getX() + i, starting_pos.getY());
		drawCh(temp_pos, str[i], color);
	}

	return 0;
}

/*
Method which swaps the back buffer onto screen and clears the old screen display
*/
int GraphicsManager::swapBuffers(){

	LogManager &log_manager = LogManager::getInstance();

	//first make sure that window exits
	if (p_window == NULL){
		log_manager.WriteMessage("Cannot swap buffers because window does not exist");
		return -1;
			}

	//sfml code for swap buffers
	p_window->display();

	//clear the old window
	p_window->clear();

	return 0;
}


//Getters and setters
int GraphicsManager::getHorizontal() const{
	return window_horizontal_chars;
}

int GraphicsManager::getVertical() const{
	return window_vetical_chars;
}

int GraphicsManager::getHorizontalPixels() const{
	return window_horizontal_pixels;
}

int GraphicsManager::getVerticalPixels() const{
	return window_vertical_pixels;
}

sf::RenderWindow *GraphicsManager::getWindow() const{
	return p_window;
}


/*
Helper functions 
*/


//Method which calculates the heirght of a char
float GraphicsManager::charHeight(){

	return (float)(GraphicsManager::getVerticalPixels() / GraphicsManager::getVertical());
}

//Method which calculates the width of a char
float GraphicsManager::charWidth(){
	return (float)(GraphicsManager::getHorizontalPixels() / GraphicsManager::getHorizontal());
}

//Converts ADC11 spaces to window pixels
Position GraphicsManager::spacesToPixels(Position spaces){

	return Position(spaces.getX() * (int)charWidth(), spaces.getY() * (int)charHeight());
}

Position GraphicsManager::pixelsToSpaces(Position pixels){
	return Position(pixels.getX() / (int)charWidth(), pixels.getY() / (int)charHeight());
}