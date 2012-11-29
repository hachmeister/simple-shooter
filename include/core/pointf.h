#pragma once

class PointF
{
public:
  PointF();
  
  PointF(float x, float y);
  
  ~PointF();
  
  float x() const;
  
  float y() const;
  
  void setX(float x);
  
  void setY(float y);

private:
  float _x;
  
  float _y;
};
