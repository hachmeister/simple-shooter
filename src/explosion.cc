#include "explosion.h"

#include "graphics.h"
#include "rect.h"
#include "sprite.h"
#include "vector2.h"

Explosion::Explosion(Sprite* spr, int n, int x, int y, int width, int height, float frameLength)
  : act(true), sprite(spr), num(n), curNum(0), posX(x), posY(y), wd(width), ht(height), fl(frameLength), ft(0)
{
}

Explosion::~Explosion()
{
}

void Explosion::update(float dt)
{
  if (!act) {
    return;
  }
  
  ft += dt;
  
  if (ft > fl) {
    ft -= fl;
    curNum++;
  }
  
  if (curNum >= num) {
    act = false;
  }
}

void Explosion::draw(const Graphics& graphics)
{
  if (!act) {
    return;
  }

  graphics.drawSprite(sprite, Rect(curNum * wd, 0, wd, ht), Vector2(posX, posY));
}

Vector2 Explosion::position() const
{
  return Vector2(posX, posY);
}

Rect Explosion::rect() const
{
  return Rect(posX, posY, wd, ht);
}

bool Explosion::active() const
{
  return act;
}