#pragma once

#include "entityfactory.h"
#include "game.h"
#include "graphics.h"

#include <list>

class Enemy;
class GameTime;
class Player;
class Star;

struct SDL_Texture;

class Shooter : public Game
{
public:
  Shooter();
  
  ~Shooter();
  
protected:
  virtual void setup();
  
  virtual void input(const GameTime& time);
  
  virtual void update(const GameTime& time);
  
  virtual void draw(const GameTime& time);
  
private:
  Graphics graphics;
  
  EntityFactory entityFactory;
  
  SDL_Texture* background;
  
  Player* player;
  
  std::list<Star*> stars;
  
  std::list<Enemy*> enemies;
  
  float enemySpawnTime;
  
  float previousSpawnTime;
};
