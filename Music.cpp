//Music source file
#include "Music.h"
#include "LogManager.h"

using namespace df;

Music::Music(){
	label = "";
}

// Associate music buffer with file.
// Return 0 if ok, else -1.
int Music::loadMusic(std::string filename){
	LogManager &log_manager = LogManager::getInstance();
	music.openFromFile(filename);
	if (music.openFromFile(filename) == false){
		log_manager.WriteMessage("Music file failed to load");
		return -1;
	}
	else{
		return 0;
	}
}
// Set label associated with music.
void Music::setLabel(std::string new_label){
	label = new_label;
}
// Get label associated with music.
std::string Music::getLabel() const{
	return label;
}
// Play music.
// If loop is true, repeat play when done.
void Music::play(bool loop){
	//LogManager &lm = LogManager::getInstance();
		music.play();
}
// Stop music.
void Music::stop(){
	music.stop();
}
// Pause music.
void Music::pause(){
	music.pause();
}
// Return SFML music.
sf::Music *Music::getMusic(){
	sf::Music *p_m = &music;
	return p_m;
}

