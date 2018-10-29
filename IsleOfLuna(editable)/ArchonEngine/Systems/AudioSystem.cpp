#include "AudioSystem.h"

using namespace core;
#include <iostream>
	AudioSystem::AudioSystem() :
		System(SystemType::AUDIO)
	{
		
	}


	AudioSystem::~AudioSystem()
	{
	}
	std::string soundname;
	bool AudioSystem::LoadSound(std::string filename_)
	{
		if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);
		if (filename_ != "")
		{
			printf(filename_.c_str()); 
			soundname = filename_;
	
			return true;

		}
		else
		{
			return false;
		}

	}
	void AudioSystem::PlayMusic()
	{
		Mix_Music *music;
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
		music = Mix_LoadMUS(soundname.c_str());
		Mix_PlayMusic(music, -1);
	}

