#pragma once

class Vector2
{
public:
  Vector2(int x, int y);
  
  ~Vector2();
  
  int x() const;
  
  int y() const;
  
  void setX(int x);
  
  void setY(int y);
  
private:
  int xp;
  
  int yp;
};
