#include "core/pointf.h"

PointF::PointF()
  : _x(0), _y(0)
{
}

PointF::PointF(float x, float y)
  : _x(x), _y(y)
{
}

PointF::~PointF()
{
}

float PointF::x() const
{
  return _x;
}

float PointF::y() const
{
  return _y;
}

void PointF::setX(float x)
{
  _x = x;
}

void PointF::setY(float y)
{
  _y = y;
}
