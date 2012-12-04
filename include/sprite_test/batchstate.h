#pragma once

#include "core/game.h"
#include "core/graphics.h"
#include "core/sounds.h"
#include "core/state.h"

struct SDL_Texture;

class Object;

class BatchState : public State
{
public:
  BatchState();
  
  ~BatchState();
  
  virtual void init(Game* game);

  virtual void input(const GameTime& time);

  virtual void update(const GameTime& time);

  virtual void draw(const GameTime& time);
  
private:
  Game* game;

  Graphics* graphics;
  
  Sounds* sounds;
  
  SDL_Texture* texture;
  
  std::vector<Object> objectes;
};
