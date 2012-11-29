#pragma once

class SizeF
{
public:
  SizeF();
  
  SizeF(float width, float height);
  
  ~SizeF();
  
  float width() const;
  
  float height() const;
  
  void setWidth(float w);
  
  void setHeight(float h);

private:
  float _width;
  
  float _height;
};
