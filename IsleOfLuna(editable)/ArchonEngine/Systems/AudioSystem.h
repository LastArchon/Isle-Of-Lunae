#pragma once
#include "System.h"
#include<SDL.h>
#include<SDL_mixer.h>
#include<string>

namespace core
{
	class AudioSystem : public System
	{
	public:
		//The event structure
		SDL_Event event;

		//The music that will be played
		
		
		bool LoadSound(std::string filename_);
		void PlayMusic();
		AudioSystem();
		~AudioSystem();


	};

}


