#pragma once

class Rect;

class RectF
{
public:
  RectF();
  
  RectF(float x, float y, float width, float height);
  
  ~RectF();
  
  float x() const;
  
  float y() const;
  
  float width() const;
  
  float height() const;
  
  void setX(float x);
  
  void setY(float y);
  
  void setWidth(float w);
  
  void setHeight(float h);
  
  bool intersect(const RectF& r) const;
  
  Rect rect() const;

private:
  float _x;
  
  float _y;
  
  float _width;
  
  float _height;
};
