#include "star.h"

#include "core/graphics.h"

#include <iostream>

Star::Star(SDL_Texture* sprite, int num, float x, float y, float speed)
  : sprite_(sprite), num_(num), posX_(x), posY_(y), speed_(speed)
{
}

Star::~Star()
{
}

void Star::update(float dt)
{
  posX_ -= dt * speed_;
  
  if (posX_ < -15.0) {
    posX_ = 800.0;
  }
}

void Star::draw(const Graphics& graphics)
{
  graphics.drawTexture(sprite_, num_ * 15, 0, 15, 15, (int)posX_, (int)posY_);
}
