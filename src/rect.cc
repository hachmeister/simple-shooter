#include "rect.h"

Rect::Rect()
  : xp(0), yp(0), wd(0), ht(0)
{
}

Rect::Rect(int xx, int yy, int w, int h)
  : xp(xx), yp(yy), wd(w), ht(h)
{
}

Rect::~Rect()
{
}

int Rect::x() const
{
  return xp;
}

int Rect::y() const
{
  return yp;
}

int Rect::width() const
{
  return wd;
}

int Rect::height() const
{
  return ht;
}

void Rect::setX(int xx)
{
  xp = xx;
}

void Rect::setY(int yy)
{
  yp = yy;
}

void Rect::setWidth(int w)
{
  wd = w;
}

void Rect::setHeight(int h)
{
  ht = h;
}

bool Rect::intersect(const Rect& r) const
{
  if (yp > (r.yp + r.ht - 1)) {
    return false;
  }
  
  if ((yp + ht - 1) < r.yp) {
    return false;
  }
  
  if (xp > (r.xp + r.wd - 1)) {
    return false;
  }
  
  if ((xp + wd - 1) < r.xp) {
    return false;
  }
  
  return true;
}
