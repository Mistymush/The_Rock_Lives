#ifndef __OUTPUT_VIEW_H__
#define __OUTPUT_VIEW_H__

#include "ObjectListIterator.h"
#include "EventKeyboard.h"
#include "GraphicsManager.h"
#include "Color.h"

class OutputView : public df::Object {

private:
	OutputView(); // Private since a singleton
	OutputView(OutputView const&); // Don't allow copy
	void operator=(OutputView const&); // Don't allow assignment
	int width;
	int height;

	int horizontal_margin;
	int vertical_margin;

	df::Color color;

	std::string output;

public:
	// Get the one and only instance of the OutputView
	static OutputView &getInstance();
	void setOutput(std::string new_output);
	std::string getOutput();
	void setWidth(int new_width);
	int getWidth();
	void setHeight(int new_height);
	int getHeight();
	void setHorizontalMargin(int new_horizontal_margin);
	int getHorizontalMargin();
	void setVerticalMargin(int new_vertical_margin);
	int getVerticalMargin();
	void setColor(df::Color new_color);
	df::Color getColor();
	void draw();
};

#endif // __OUTPUT_VIEW_H__