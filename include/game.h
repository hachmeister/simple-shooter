#pragma once

#include <map>
#include <string>

//#include "input.h"

class GameTime;

class Game
{
public:
  Game();
  
  virtual ~Game();
  
  void start();
  
  void stop();
  
protected:
  virtual void setup() = 0;
  
  virtual void input(const GameTime& time) = 0;
  
  virtual void update(const GameTime& time) = 0;
  
  virtual void draw(const GameTime& time) = 0;
  
private:
  bool running_;
};
