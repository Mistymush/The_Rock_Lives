/*
File containing class definition of the game manager
Author: August Beers
*/


//Give amount of game loops to the write log file

//Innclude timeBeginPeriod(1) start
//inclde   timeEndPeriod(1) shutdown

#ifndef GAME_MANAGER
#define GAME_MANAGER


//System includes
#include <Windows.h>

//project includes
#include "Manager.h"
#include "LogManager.h"
#include "Clock.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "Event.h"
#include "GraphicsManager.h"
#include "InputManager.h"

//Default frame time(game loop time)
const int FRAME_TIME_DEFAULT = 33;

namespace df{

	class GameManager : public df::Manager {

	private:
		//Singleton behaivior
		GameManager();
		GameManager(GameManager const&);
		void operator=(GameManager const&);

		bool game_over; //If true game loop should stop
		int frame_time; //Target time per game loop, in milliseconds

	public:
		~GameManager();

		//Get the singleton instance of the GameManager.
		static GameManager &getInstance();

		//Start gameManager services
		int startUp();

		//Shut GameManager services
		void shutDown();

		//Run game loop
		void run();

		//Set game over status to indicated value
		//If true (default), will stop game loop.
		void setGameOver(bool newValue);

		//Get game over status
		bool getGameOver() const;

		//Return farme time
		//Frame time is target time for game loop, in milliseconds.
		int getFrameTime() const;

	};

}// end DF
#endif // !GAME_MANAGER