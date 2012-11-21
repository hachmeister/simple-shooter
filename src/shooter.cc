#include "shooter.h"

#include "enemy.h"
#include "entityfactory.h"
#include "explosion.h"
#include "gametime.h"
#include "player.h"
#include "projectile.h"
#include "rect.h"
#include "star.h"

#include <SDL.h>

#include <iostream>

Shooter::Shooter()
  : graphics(800, 600), entityFactory(graphics)
{
  enemySpawnTime = 1.0f;
  previousSpawnTime = 0;
  
  fireTime = 0.15f;
  previousFireTime = 0;
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
  Uint8 *state = SDL_GetKeyboardState(NULL);
  
  if (state[SDL_SCANCODE_SPACE] && (time.total() - previousFireTime) > fireTime) {
    Rect rect = player->rect();
    projectiles.push_back(entityFactory.createProjectile(rect.x() + rect.width(), rect.y() + rect.height()/2 - 5));
    previousFireTime = time.total();
    sounds.playSound("../resources/laser.wav");
  }

  if (time.total() - previousSpawnTime > enemySpawnTime) {
    enemies.push_back(entityFactory.createEnemy());
    previousSpawnTime = time.total();
  }
  
  // ---

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
  
  for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it) {
    (*it)->update(time.delta());
    
    if (!(*it)->active()) {
      delete *it;
      it = projectiles.erase(it);
    }
  }
  
  player->update(time.delta());
  
  for (std::list<Explosion*>::iterator it = explosions.begin(); it != explosions.end(); ++it) {
    (*it)->update(time.delta());
    
    if (!(*it)->active()) {
      delete *it;
      it = explosions.erase(it);
    }
  }
  
  // collision
  Rect rect1 = player->rect();
  Rect rect2;
  
  for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
    rect2 = (*it)->rect();
    
    if (rect1.intersect(rect2)) {
      addExplosion(*it);
      it = enemies.erase(it);
      std::cout << "Player Collision!\n";
    }
  }
  
  for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it) {
    rect1 = (*it)->rect();
    
    for (std::list<Enemy*>::iterator it2 = enemies.begin(); it2 != enemies.end(); ++it2) {
      rect2 = (*it2)->rect();
      
      if (rect1.intersect(rect2)) {
        addExplosion(*it2);
        it = projectiles.erase(it);
        it2 = enemies.erase(it2);
        std::cout << "Projectile Collision!\n";
      }
    }
  }
}

void Shooter::addExplosion(Enemy* enemy)
{
  Rect rect = enemy->rect();
  explosions.push_back(entityFactory.createExplosion(rect.x() + (rect.width() - 160) / 2, rect.y() + (rect.height() - 120) / 2));
  sounds.playSound("../resources/explosion.wav");
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
  
  for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it) {
    (*it)->draw(graphics);
  }
  
  player->draw(graphics);
  
  for (std::list<Explosion*>::iterator it = explosions.begin(); it != explosions.end(); ++it) {
    (*it)->draw(graphics);
  }
  
  graphics.flip();
}
