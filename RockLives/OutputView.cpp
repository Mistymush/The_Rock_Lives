#include <iostream>
#include <sstream>
#include <string>
#include "OutputView.h"
#include "EventTurn.h"

OutputView::OutputView() {
	setType("OutputView");

	setPosition(df::Position(0, 19));

	setWidth(114);
	setHeight(4);

	setHorizontalMargin(1);
	setVerticalMargin(0);

	setColor(df::RED);

	//setOutput("This is a long long long long long long long long long loooooong test output. This is a long random series of sentances made to get the input box to it's limit point, which should be 5 lines, I believe. This is also a test. I'm just trying to get this to stop printing.");
}

OutputView &OutputView::getInstance() {
	static OutputView output_view;
	return output_view;
}

void OutputView::setWidth(int new_width) {
	width = new_width;
}

int OutputView::getWidth() {
	return width;
}

void OutputView::setHeight(int new_height) {
	height = new_height;
}

int OutputView::getHeight() {
	return height;
}

void OutputView::setHorizontalMargin(int new_horizontal_margin) {
	horizontal_margin = new_horizontal_margin;
}

int OutputView::getHorizontalMargin() {
	return horizontal_margin;
}

void OutputView::setVerticalMargin(int new_vertical_margin) {
	vertical_margin = new_vertical_margin;
}

int OutputView::getVerticalMargin() {
	return vertical_margin;
}

void OutputView::setColor(df::Color new_color) {
	color = new_color;
}

df::Color OutputView::getColor() {
	return color;
}

void OutputView::setOutput(std::string new_output) {
	output.insert(output.begin(), new_output);
}

std::vector<string> OutputView::getOutput() {
	return output;
}

void OutputView::clearOutput() {
	std::vector<string>().swap(output);
}

void OutputView::draw() {
	df::GraphicsManager &graphics_manager = df::GraphicsManager::getInstance();
	int line_chars = width - (2 * horizontal_margin); // The number of characters spaces left on a line
	int current_line = 1 + getVerticalMargin(); // The current line of text being draw to
	df::Position string_pos = getPosition(); // The current position of the string being drawn
	int x = getPosition().getX(); // This object's x position
	int y = getPosition().getY(); // This object's y position

	int i; // Loop counter
	for (i = 0; i < width; i++) { //Draw the border above the output view using dashes
		string_pos.setX(x + i);
		graphics_manager.drawCh(string_pos, '-', color);
	}

	for (std::vector<string>::iterator iter = output.begin(); iter != output.end(); iter++) {
		std::istringstream stream(*iter); // A stream for reading the output string one word at a time
		std::string word; // A string for holding the current word being drawn

		// Set the x and y position of the string to the place where text should start being drawn from
		string_pos.setY(string_pos.getY() + 1 + vertical_margin);
		string_pos.setX(x + horizontal_margin);

		while (stream >> word) { // While there are still words to be read, store the current word from the stream into the variable "word"
			int len = word.length(); // The length of the current word.

			if ((len + 1) > line_chars) { // If the length of the current word plus a space is longer than the characters remaining on this line, wrap.
				string_pos.setY(string_pos.getY() + 1); // Move the string position to the next line down
				current_line++; // Increment the current line keeper
				line_chars = width - (2 * horizontal_margin); // Reset the number of available characters for the new line
				string_pos.setX(x + horizontal_margin); // Set the x position of the string back to the beginning of the line
			}
			if (current_line > (height - vertical_margin)) { // If there are no lines left, stop drawing words
				return;
			}
			graphics_manager.drawString(string_pos, word, df::LEFT_JUSTIFIED, color); // Draw the current word at the string position
			string_pos.setX(string_pos.getX() + len + 1); // Update the string x position to after the current word plus a space
			line_chars -= (len + 1); // Reduce the number of available characters on this line by the length of the word plus a space
		}
	}
}