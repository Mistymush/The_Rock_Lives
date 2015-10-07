/*
Header file which defines the graphics manager class
*/


#ifndef GRAPHICS_MANAGER
#define GRAPHICS_MANAGER

#include <SFML/graphics.hpp>
#include "Manager.h"
#include "Position.h"
#include "LogManager.h"
#include "Color.h"

namespace df{

	//justification enumeration
	enum Justification {
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED,
		RIGHT_JUSTIFIED,
	};


	const int WINDOW_HORIZONTAL_PIXEDLS_DEFAULT = 1366;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 106;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	const int WINDOW_STYLE_DEFAULTa = sf::Style::Titlebar;
	const int WINDOW_STYLE_DEFAULTb = sf::Style::Close;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
	const std::string FONT_FILE_DEFAULT = "df-font.ttf";

	class GraphicsManager : public Manager {

	private:
		//singleton functionality
		GraphicsManager();
		GraphicsManager(GraphicsManager const&);
		void operator=(GraphicsManager const&);

		//Font used for the ASC11 grahics
		sf::Font font;
		//Pointer to the SFML window.
		sf::RenderWindow *p_window;
		//width and hieght in pixels
		int window_horizontal_pixels;
		int window_vertical_pixels;
		//width and height in ASC11 spaces
		int window_horizontal_chars;
		int window_vetical_chars;

	public:
		//Grab the one and only instance of the Graphics Manager.
		static GraphicsManager &getInstance();

		//Deconstuctor

		//Start of the manager and window
		//Return 0 if or, els -1
		int startUp();

		//Shut down game manager
		int shutDown();

		//Draw a charctrer to a locaiton(x,y)
		int drawCh(Position world_pos, char ch, Color color) const;

		//Render current display buffer
		int swapBuffers();

		//Draw a string at location (x,y) with color and justification
		int drawString(Position world_pos, std::string str, Justification just, Color color) const;

		//Getters and setters
		int getHorizontal() const;

		int getVertical() const;

		int getHorizontalPixels() const;

		int getVerticalPixels() const;

		sf::RenderWindow *getWindow() const;

		//Helper functions
		float charHeight();

		float charWidth();

		Position spacesToPixels(Position spaces);

		Position pixelsToSpaces(Position pixels);
	};

} // end namespace df

#endif // end GRAPHICS_MANAGER