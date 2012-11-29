#pragma once

class Point
{
public:
  Point();
  
  Point(int x, int y);
  
  ~Point();
  
  int x() const;
  
  int y() const;
  
  void setX(int x);
  
  void setY(int y);

private:
  int _x;
  
  int _y;
};
