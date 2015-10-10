//Sound source file
#include "Sound.h"
#include "LogManager.h"

using namespace df;

Sound::Sound(){
	label = "";
}

Sound::~Sound(){
	sound.resetBuffer();
}

//Load sound buffer from file
//Return 0 if ok, else -1
int Sound::loadSound(std::string filename){
	LogManager &log_manager = LogManager::getInstance();
	sound_buffer.loadFromFile(filename);
	if (!sound_buffer.loadFromFile(filename)){
		log_manager.WriteMessage("Sound cannot be opened");
		return -1;
	}
	sound.setBuffer(sound_buffer);
	return 0;
}

//Set label associated with sound
void Sound::setLabel(std::string new_label){
	label = new_label;
}

//Get label associated with sound
std::string Sound::getLabel() const{
	return label;
}

//Play sound
//If loop is true, repeat play when done
void Sound::play(bool loop){
	LogManager &log_manager = LogManager::getInstance();
	if (sound.getBuffer() != NULL){
		sound.play();
	}
	//sound.setLoop(loop);
	//sound.play();
	
}

//Stop sound
void Sound::stop(){
	sound.stop();
}

//Pause sound
void Sound::pause(){
	sound.pause();
}

//Return SFML sound
sf::Sound Sound::getSound() const{
	return sound;
}