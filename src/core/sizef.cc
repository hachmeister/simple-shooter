#include "core/sizef.h"

SizeF::SizeF()
  : _width(0), _height(0)
{
}

SizeF::SizeF(float width, float height)
  : _width(width), _height(height)
{
}

SizeF::~SizeF()
{
}

float SizeF::width() const
{
  return _width;
}

float SizeF::height() const
{
  return _height;
}

void SizeF::setWidth(float width)
{
  _width = width;
}

void SizeF::setHeight(float height)
{
  _height = height;
}
