#include "projectile.h"

#include "core/graphics.h"
#include "core/point.h"
#include "core/rect.h"
#include "core/sprite.h"

Projectile::Projectile(Sprite* spr, float x, float y, float spd)
  : act(true), sprite(spr), posX(x), posY(y), speed(spd)
{
}

Projectile::~Projectile()
{
}

void Projectile::update(float dt)
{
  posX += dt * speed;
  
  if (posX > 800.0) {
    act = false;
  }
}

void Projectile::draw(const Graphics& graphics)
{
  graphics.drawSprite(sprite, Rect(0, 0, sprite->width(), sprite->height()), Point(posX, posY));
}

Point Projectile::position() const
{
  return Point(posX, posY);
}

Rect Projectile::rect() const
{
  return Rect(posX, posY, sprite->width(), sprite->height());
}

bool Projectile::active() const
{
  return act;
}
