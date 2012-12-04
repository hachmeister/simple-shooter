#include "core/sprite.h"

#include "core/animation.h"

Sprite::Sprite() :
  _currentAnimation(0)
{
}
  
Sprite::Sprite(SDL_Texture* t, int w, int h) :
  _currentAnimation(0), tex(t), wd(w), ht(h)
{
}

Sprite::Sprite(Animation* animation)
{
  _animations["default"] = animation;
  _currentAnimation = animation;
}
  
Sprite::~Sprite()
{
  for (std::map<std::string, Animation*>::iterator it = _animations.begin(); it != _animations.end(); ++it) {
    delete it->second;
  }
}

void Sprite::addAnimation(const std::string& name, Animation* animation)
{
  _animations[name] = animation;
}

void Sprite::setCurrentAnimation(const std::string& name)
{
  if (_animations.count(name) > 0) {
    _currentAnimation = _animations[name];
  }
}

void Sprite::update(float dt)
{
  if (_currentAnimation) {
    _currentAnimation->update(dt);
  }
}

void Sprite::draw(const Graphics& graphics, const Point& point)
{
  if (_currentAnimation) {
    _currentAnimation->draw(graphics, point);
  }
}

SDL_Texture* Sprite::texture() const
{
  return tex;
}

int Sprite::width() const
{
  if (_currentAnimation) {
    return _currentAnimation->width();
  }
  else {
    return wd;
  }
}

int Sprite::height() const
{
  if (_currentAnimation) {
    return _currentAnimation->height();
  }
  else {
    return ht;
  }
}
