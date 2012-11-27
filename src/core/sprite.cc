#include "core/sprite.h"

Sprite::Sprite(SDL_Texture* t, int w, int h)
  : tex(t), wd(w), ht(h)
{
}

Sprite::~Sprite()
{
}

SDL_Texture* Sprite::texture() const
{
  return tex;
}

int Sprite::width() const
{
  return wd;
}

int Sprite::height() const
{
  return ht;
}
