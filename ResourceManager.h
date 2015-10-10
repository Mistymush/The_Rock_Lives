//System includes
#include <string>

//Engine includes
#include "Manager.h"
#include "Sound.h"
#include "Music.h"
namespace df{
	const int MAX_SOUNDS = 128;
	const int MAX_MUSICS = 128;

	class ResourceManager : public Manager{
	private:
		ResourceManager(); // Private(A singleton)
		ResourceManager(ResourceManager const&); //Don't allow copy
		void operator = (ResourceManager const&); //Don't allow assignment
		Sound sound[MAX_SOUNDS]; // Array of sound buffers.
		int sound_count; // Count of number of loaded sounds.
		Music music[MAX_MUSICS]; // Array of music buffers.
		int music_count; // Count of number of loaded musics.

	public:
		//Get the one and only instamce of the Resource amanger
		static ResourceManager &getInstance();

		//Get ResourceManager ready to manage resources
		int startUp();

		//Shut down resource manager 
		void shutDown();

		// Load Sound from file.
		// Return 0 if ok, else -1.
		int loadSound(std::string filename, std::string label);

		// Remove Sound with indicated label.
		// Return 0 if ok, else -1.
		int unloadSound(std::string label);

		// Find Sound with indicated label.
		// Return pointer to it if found, else NULL.
		Sound *getSound(std::string label);

		// Associate file with Music.
		// Return 0 if ok, else -1.
		int loadMusic(std::string filename, std::string label);

		// Remove label for Music with indicated label.
		// Return 0 if ok, else -1.
		int unloadMusic(std::string label);

		// Find Music with indicated label.
		// Return pointer to it if found, else NULL.
		Music *getMusic(std::string label);
	};
}