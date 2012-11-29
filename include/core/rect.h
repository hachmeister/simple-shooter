#pragma once

class Rect
{
public:
  Rect();
  
  Rect(int x, int y, int width, int height);
  
  ~Rect();
  
  int x() const;
  
  int y() const;
  
  int width() const;
  
  int height() const;
  
  void setX(int x);
  
  void setY(int y);
  
  void setWidth(int w);
  
  void setHeight(int h);
  
  bool intersect(const Rect& r) const;

private:
  int _x;
  
  int _y;
  
  int _width;
  
  int _height;
};
