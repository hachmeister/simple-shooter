#include "core/rect.h"

Rect::Rect()
  : _x(0), _y(0), _width(0), _height(0)
{
}

Rect::Rect(int x, int y, int width, int height)
  : _x(x), _y(y), _width(width), _height(height)
{
}

Rect::~Rect()
{
}

int Rect::x() const
{
  return _x;
}

int Rect::y() const
{
  return _y;
}

int Rect::width() const
{
  return _width;
}

int Rect::height() const
{
  return _height;
}

void Rect::setX(int x)
{
  _x = x;
}

void Rect::setY(int y)
{
  _y = y;
}

void Rect::setWidth(int width)
{
  _width = width;
}

void Rect::setHeight(int height)
{
  _height = height;
}

bool Rect::intersect(const Rect& r) const
{
  if (_y > (r._y + r._height - 1)) {
    return false;
  }
  
  if ((_y + _height - 1) < r._y) {
    return false;
  }
  
  if (_x > (r._x + r._width - 1)) {
    return false;
  }
  
  if ((_x + _width - 1) < r._x) {
    return false;
  }
  
  return true;
}
