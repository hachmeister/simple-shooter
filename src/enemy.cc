#include "enemy.h"

#include "core/graphics.h"
#include "core/rect.h"
#include "core/sprite.h"
#include "core/point.h"

Enemy::Enemy(Sprite* spr, float x, float y, float spd)
  : act(true), sprite(spr), posX(x), posY(y), speed(spd)
{
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
  posX -= dt * speed;
  
  if (posX + sprite->width() < 0.0) {
    act = false;
  }
}

void Enemy::draw(const Graphics& graphics)
{
  graphics.drawSprite(sprite, Rect(0, 0, sprite->width(), sprite->height()), Point(posX, posY));
}

Point Enemy::position() const
{
  return Point(posX, posY);
}

Rect Enemy::rect() const
{
  return Rect(posX, posY, sprite->width(), sprite->height());
}

bool Enemy::active() const
{
  return act;
}
