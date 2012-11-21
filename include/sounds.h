#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

#include <map>
#include <string>

class Sounds
{
public:
  Sounds();
  
  ~Sounds();
  
  void playSound(const std::string& name);
  
  void playMusic(const std::string& name);
  
private:
  std::map<std::string, Mix_Chunk*> sounds;
};
