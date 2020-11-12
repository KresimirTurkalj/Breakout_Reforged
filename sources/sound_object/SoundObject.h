#pragma once
#include <string>
#include <SDL_Mixer.h>
#include "interfaces\IPlayable.h"

class SoundObject : public IPlayable{
public:
	SoundObject(std::string fileLocation) : soundEffect(Mix_LoadWAV(fileLocation.c_str())) {}
	~SoundObject() { Mix_FreeChunk(soundEffect); }
	void playSound() { Mix_PlayChannel(-1, soundEffect, 0); }
private:
	Mix_Chunk* soundEffect;
	SoundObject();
};

