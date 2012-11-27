#include "core/vector2.h"

Vector2::Vector2(int xx, int yy)
  : xp(xx), yp(yy)
{
}

Vector2::~Vector2()
{
}

int Vector2::x() const
{
  return xp;
}

int Vector2::y() const
{
  return yp;
}

void Vector2::setX(int xx)
{
  xp = xx;
}

void Vector2::setY(int yy)
{
  yp = yy;
}
