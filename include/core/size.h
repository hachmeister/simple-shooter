#pragma once

class Size
{
public:
  Size();
  
  Size(int width, int height);
  
  ~Size();
  
  int width() const;
  
  int height() const;
  
  void setWidth(int w);
  
  void setHeight(int h);

private:
  int _width;
  
  int _height;
};
