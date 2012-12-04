#include "core/animation.h"

#include "core/graphics.h"
#include "core/point.h"
#include "core/rect.h"

Animation::Animation(SDL_Texture* texture, int width, int height, int columns, int frames, float length) :
  _texture(texture), _width(width), _height(height), _startframe(0), _columns(columns), _frames(frames), _length(length), _repeatable(false)
{
  init();
}

Animation::Animation(SDL_Texture* texture, int width, int height, int columns, int startframe, int frames, float length) :
  _texture(texture), _width(width), _height(height), _startframe(startframe), _columns(columns), _frames(frames), _length(length), _repeatable(false)
{
  init();
}
  
Animation::~Animation()
{
}

void Animation::init()
{
  _frameLength = _length / _frames;
  _frameTime = 0.0f;
  _curFrame = 0;
  
  /*Uint32 format;
  int access, width, height;
  
  SDL_QueryTexture(_texture, &format, &access,  &width, &height);*/
}

int Animation::width() const
{
  return _width;
}

int Animation::height() const
{
  return _height;
}

void Animation::update(float dt)
{
  if (!_repeatable && (_curFrame + 1) == _frames) {
    return;
  }
  
  _frameTime += dt;
  
  if (_frameTime > _frameLength) {
    _curFrame++;
    _frameTime -= _frameLength;
  }
  
  if (_curFrame >= _frames) {
    _curFrame = 0;
  }
}

void Animation::draw(const Graphics& graphics, const Point& point)
{
  int frameNo, x, y;
  frameNo = _startframe + _curFrame;
  y = frameNo / _columns;
  x = frameNo - (y * _columns);
  
  graphics.drawTexture(_texture, Rect(x * _width, y * _height, _width, _height), point);
}
