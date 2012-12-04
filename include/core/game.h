#pragma once

#include "core/graphics.h"
#include "core/sounds.h"

class State;

class Game
{
public:
  Game();
  
  virtual ~Game();
  
  void start(State* state);
  
  void stop();
  
  void pause();
  
  void resume();
  
  bool is_paused();
  
  void changeState(State* state);
  
  Graphics* graphics();
  
  Sounds* sounds();
  
private:
  Graphics g;
  
  Sounds s;
  
  bool running;
  
  bool _paused;
  
  State* current;
  
  State* next;
};
