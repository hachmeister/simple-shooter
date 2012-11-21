#include "sounds.h"

#include <stdexcept>

#define NUM_BUFFERS 1

Sounds::Sounds()
{
  if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
    throw std::logic_error("SDL_Init_Subsystem(SDL_INIT_AUDIO) failed!");
  }
  
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
    printf("Mix_OpenAudio: %s\n", Mix_GetError());
    throw std::logic_error("Mix_OpenAudio failed!");
  }
}

Sounds::~Sounds()
{
  Mix_CloseAudio();
}

void Sounds::playSound(const std::string& name)
{
  Mix_Chunk* sound;
  
  if (sounds.count(name) > 0) {
    sound = sounds[name];
  }
  else {
    sound = Mix_LoadWAV(name.c_str());
  }
  
  if (sound == NULL) {
    return;
  }
  
  Mix_PlayChannel(-1, sound, 0);
}

void Sounds::playMusic(const std::string& name)
{
}
