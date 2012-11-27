#include "entityfactory.h"

#include "enemy.h"
#include "explosion.h"
#include "core/graphics.h"
#include "player.h"
#include "projectile.h"
#include "core/sprite.h"
#include "star.h"

#include <stdlib.h>
#include <time.h>

EntityFactory::EntityFactory(Graphics& g)
  : graphics(g)
{
  srand(time(NULL));
}

EntityFactory::~EntityFactory()
{
  std::map<std::string, SDL_Texture*>::iterator it;
  
  for (it = textures_.begin(); it != textures_.end(); ++it) {
    graphics.destroyTexture((*it).second);
  }
}

Player* EntityFactory::createPlayer()
{
  Sprite* sprite = createSprite("player", "../resources/spaceship.bmp");
  return new Player(sprite, 0, 300 - (sprite->height() / 2), 480);
}

Star* EntityFactory::createStar()
{
  SDL_Texture* sprite = getTexture("stars", "../resources/stars.bmp");
  int num = rand() % 10;
  int x = rand() % 800;
  int y = rand() % 600;
  int speed = (rand() % 70) + 20;
  return new Star(sprite, num, x, y, speed);
}

Enemy* EntityFactory::createEnemy()
{
  Sprite* sprite = createSprite("enemy", "../resources/asteroid.bmp");
  int y = rand() % (600 - sprite->height());
  int speed = (rand() % 100) + 360;
  return new Enemy(sprite, 800, y, speed);
}

Projectile* EntityFactory::createProjectile(int x, int y)
{
  Sprite* sprite = createSprite("projectile", "../resources/projectile.bmp");
  return new Projectile(sprite, x, y, 1440);
}

Explosion* EntityFactory::createExplosion(int x, int y)
{
  Sprite* sprite = createSprite("explosion", "../resources/explosion.bmp");
  return new Explosion(sprite, 30, x, y, 160, 120, 0.05f);
}

Sprite* EntityFactory::createSprite(const std::string& key, const char* file)
{
  Uint32 format;
  int access, w, h;
  
  SDL_Texture* texture = getTexture(key, file);
  SDL_QueryTexture(texture, &format, &access, &w, &h);
  
  return new Sprite(texture, w, h);
}

SDL_Texture* EntityFactory::getTexture(const std::string& key, const char* file)
{
  if (textures_.count(key) > 0) {
    return textures_[key];
  }
  else {
    SDL_Texture* texture = graphics.loadBMP(file);
    textures_[key] = texture;
    return texture;
  }
}
