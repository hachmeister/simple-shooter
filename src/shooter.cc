#include "shooter.h"

#include "enemy.h"
#include "entityfactory.h"
#include "gametime.h"
#include "player.h"
#include "rect.h"
#include "star.h"

#include <SDL.h>

#include <iostream>

Shooter::Shooter()
  : graphics(800, 600), entityFactory(graphics)
{
  enemySpawnTime = 1.0f;
  previousSpawnTime = 0;
}

Shooter::~Shooter()
{
  if (player) {
    delete player;
  }
  
  for (std::list<Star*>::iterator it = stars.begin(); it != stars.end(); ++it) {
    delete *it;
  }
  
  for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
    delete *it;
  }
}

void Shooter::setup()
{
  background = graphics.loadBMP("../resources/background.bmp");
  player = entityFactory.createPlayer();
  
  for (int i = 0; i < 150; ++i) {
    stars.push_back(entityFactory.createStar());
  }
}

void Shooter::input(const GameTime& time)
{
  SDL_Event event;

  while(SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN: {
        SDL_KeyboardEvent* key = &event.key;
        switch (key->keysym.sym) {
          case SDLK_ESCAPE:
            stop();
            break;
          case SDLK_w:
            player->setMoveUp(true);
            break;
          case SDLK_a:
            player->setMoveLeft(true);
            break;
          case SDLK_s:
            player->setMoveDown(true);
            break;
          case SDLK_d:
            player->setMoveRight(true);
            break;
          default:
            break;
        }
        break;
      }
      case SDL_KEYUP: {
        SDL_KeyboardEvent* key = &event.key;
        switch (key->keysym.sym) {
          case SDLK_w:
            player->setMoveUp(false);
            break;
          case SDLK_a:
            player->setMoveLeft(false);
            break;
          case SDLK_s:
            player->setMoveDown(false);
            break;
          case SDLK_d:
            player->setMoveRight(false);
            break;
          default:
            break;
        }
        break;
      }
      case SDL_QUIT:
        stop();
        break;
    }
  }
}
  
void Shooter::update(const GameTime& time)
{
  if (time.total() - previousSpawnTime > enemySpawnTime) {
    enemies.push_back(entityFactory.createEnemy());
    previousSpawnTime = time.total();
  }
  
  for (std::list<Star*>::iterator it = stars.begin(); it != stars.end(); ++it) {
    (*it)->update(time.delta());
  }
  
  for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
    (*it)->update(time.delta());
    
    if (!(*it)->active()) {
      delete *it;
      it = enemies.erase(it);
    }
  }
  
  player->update(time.delta());
  
  // collision
  Rect rect1 = player->rect();
  Rect rect2;
  
  for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
    rect2 = (*it)->rect();
    
    if (rect1.intersect(rect2)) {
      std::cout << "Collision!\n";
    }
  }
}

void Shooter::draw(const GameTime& time)
{
  graphics.clear();
  
  graphics.drawTexture(background, 0, 0);
  
  for (std::list<Star*>::iterator it = stars.begin(); it != stars.end(); ++it) {
    (*it)->draw(graphics);
  }
  
  for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
    (*it)->draw(graphics);
  }
  
  player->draw(graphics);
  
  graphics.flip();
}
