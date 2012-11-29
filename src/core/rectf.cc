#include "core/rectf.h"

#include "core/rect.h"

RectF::RectF()
  : _x(0.0), _y(0.0), _width(0.0), _height(0.0)
{
}

RectF::RectF(float x, float y, float width, float height)
  : _x(x), _y(y), _width(width), _height(height)
{
}

RectF::~RectF()
{
}

float RectF::x() const
{
  return _x;
}

float RectF::y() const
{
  return _y;
}

float RectF::width() const
{
  return _width;
}

float RectF::height() const
{
  return _height;
}

void RectF::setX(float x)
{
  _x = x;
}

void RectF::setY(float y)
{
  _y = y;
}

void RectF::setWidth(float width)
{
  _width = width;
}

void RectF::setHeight(float height)
{
  _height = height;
}

bool RectF::intersect(const RectF& r) const
{
  if (_y >= (r._y + r._height)) {
    return false;
  }
  
  if ((_y + _height) <= r._y) {
    return false;
  }
  
  if (_x >= (r._x + r._width)) {
    return false;
  }
  
  if ((_x + _width) <= r._x) {
    return false;
  }
  
  return true;
}

Rect RectF::rect() const
{
  return Rect(_x, _y, _width, _height);
}
