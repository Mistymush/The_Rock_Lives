//Resource Manager source file
#include "ResourceManager.h"
#include "LogManager.h"

using namespace df;
//constructor
ResourceManager::ResourceManager(){
	setType("ResourceManager");
	sound_count = 0;
	music_count = 0;
	sound[sound_count];
	music[music_count];
}

//Get the one and only instance of the resource manager 
ResourceManager &ResourceManager::getInstance(){
	static ResourceManager resource_manager;
	return resource_manager;
}

//Start up the resource manager
int ResourceManager::startUp(){
	Manager::startUp();
	if (&Manager::isStarted){
		return 0;
	}
	else{
		return -1;
	}
}

//Shut down the resource manager
void ResourceManager::shutDown(){
	Manager::shutDown();
}

// Load Sound from file.
// Return 0 if ok, else -1.
int ResourceManager::loadSound(std::string filename, std::string label){
	LogManager &log_manager = LogManager::getInstance();
	if (sound_count == MAX_SOUNDS){
		log_manager.WriteMessage("Sound array is full");
		return -1;
	}
	if (sound[sound_count].loadSound(filename) == -1){
		log_manager.WriteMessage("Unable to load from file");
		return -1;
	}

	//all set
	sound[sound_count].setLabel(label);
	sound[sound_count].loadSound(filename);
	sound_count++;
	log_manager.WriteMessage("Sound loaded succesfully");
	return 0;
}

// Remove Sound with indicated label.
// Return 0 if ok, else -1.
int ResourceManager::unloadSound(std::string label){
	LogManager &log_manager = LogManager::getInstance();
	for (int i = 0; i <= sound_count-1; i++){
		if (sound[sound_count].getLabel() == label){
			//unload sound, by scooting over remaining sounds
			for (int j = 0; j <= sound_count - 2; j++){
				sound[j] = sound[j + 1];
			}
			sound_count--;
			return 0;
		}
	}
		log_manager.WriteMessage("Could not unload the sound");
		return -1;
	

}

// Find Sound with indicated label.
// Return pointer to it if found, else NULL.
Sound *ResourceManager::getSound(std::string label){
	LogManager &log_manager = LogManager::getInstance();
	for (int i = 0; i <= sound_count-1; i++){
		if (sound[sound_count].getLabel().compare(label)){
			return (&sound[i]);
		}
	}
		log_manager.WriteMessage("Could not get the sound");
		return NULL;
}

// Associate file with Music.
// Return 0 if ok, else -1.
int ResourceManager::loadMusic(std::string filename, std::string label){
	LogManager &log_manager = LogManager::getInstance();
	if (music_count == MAX_MUSICS){
		log_manager.WriteMessage("Music array is full");
		return -1;
	}
	if (music[music_count].loadMusic(filename) == -1){
		log_manager.WriteMessage("Unable to load from file");
		return -1;
	}
	if (music[music_count].getLabel().compare("")){
		log_manager.WriteMessage("Cannot open a blank file");
		return -1;
	}

	//all set
	music[music_count].setLabel(label);
	music[music_count].loadMusic(filename);
	music_count++;
	return 0;
}

// Remove label for Music with indicated label.
// Return 0 if ok, else -1.
int ResourceManager::unloadMusic(std::string label){
	LogManager &log_manager = LogManager::getInstance();
	for (int i = 0; i <= music_count - 1; i++){
		if (music[music_count].getLabel().compare(label)){
			//unload sound, can't scoot over so set label to empty
			for (int j = 0; j <= music_count - 2; j++){
				music[j].setLabel("");
			}
			music_count--;
			return 0;
		}
	}
	log_manager.WriteMessage("Could not unload the music");
	return -1;
}

// Find Music with indicated label.
// Return pointer to it if found, else NULL.
Music *ResourceManager::getMusic(std::string label){
	LogManager &log_manager = LogManager::getInstance();
	for (int i = 0; i <= music_count - 1; i++){
		if (music[music_count].getLabel().compare(label)){
			return (&music[i]);
		}
	}
	log_manager.WriteMessage("Could not get the Music");
	return NULL;
}