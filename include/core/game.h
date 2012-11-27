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
  
  void changeState(State* state);
  
  Graphics* graphics();
  
  Sounds* sounds();
  
private:
  Graphics g;
  
  Sounds s;
  
  bool running;
  
  State* current;
  
  State* next;
};
