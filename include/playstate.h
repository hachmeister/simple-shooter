#pragma once

#include "entityfactory.h"
#include "core/game.h"
#include "core/graphics.h"
#include "core/sounds.h"
#include "core/state.h"

#include <list>

class Enemy;
class Explosion;
class GameTime;
class Player;
class Star;

struct SDL_Texture;

class PlayState : public State
{
public:
  PlayState();
  
  ~PlayState();
  
  virtual void init(Game* game);

  virtual void input(const GameTime& time);

  virtual void update(const GameTime& time);

  virtual void draw(const GameTime& time);
  
private:
  void addExplosion(Enemy* enemy);
  
private:
  Game* game;

  Graphics* graphics;
  
  Sounds* sounds;
  
  EntityFactory* entityFactory;
  
  SDL_Texture* background;
  
  Player* player;
  
  std::list<Star*> stars;
  
  std::list<Enemy*> enemies;
  
  std::list<Projectile*> projectiles;
  
  std::list<Explosion*> explosions;
  
  float enemySpawnTime;
  
  float previousSpawnTime;
  
  float fireTime;
  
  float previousFireTime;
};
