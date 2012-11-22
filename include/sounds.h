#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include <map>
#include <string>
#include <vector>

class Sounds
{
public:
  Sounds();
  
  ~Sounds();
  
  void playSound(const std::string& name);
  
  void playMusic(const std::string& name);
  
private:
  ALuint loadSound(const std::string& name);
  
private:
  ALCdevice* device;
  
  ALCcontext* context;
  
  std::map<std::string, ALuint> sounds;
  
  std::vector<ALuint> channels;
};
