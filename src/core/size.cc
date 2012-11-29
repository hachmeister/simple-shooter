#include "core/size.h"

Size::Size()
  : _width(0), _height(0)
{
}

Size::Size(int width, int height)
  : _width(width), _height(height)
{
}

Size::~Size()
{
}

int Size::width() const
{
  return _width;
}

int Size::height() const
{
  return _height;
}

void Size::setWidth(int width)
{
  _width = width;
}

void Size::setHeight(int height)
{
  _height = height;
}
