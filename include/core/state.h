#pragma once

class Game;
class GameTime;

class State
{
public:
  virtual ~State() {};
  
  virtual void init(Game* game) = 0;

  virtual void input(const GameTime& time) = 0;

  virtual void update(const GameTime& time) = 0;

  virtual void draw(const GameTime& time) = 0;
};
