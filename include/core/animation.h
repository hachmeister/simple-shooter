#pragma once

struct SDL_Texture;

class Graphics;
class Point;

class Animation
{
public:
  Animation(SDL_Texture* texture, int width, int height, int columns, int frames, float length);
  
  Animation(SDL_Texture* texture, int width, int height, int columns, int startframe, int frames, float length);
  
  ~Animation();
  
  int width() const;
  
  int height() const;
  
  //bool get_repeatable();
  
  void update(float dt);
  
  void draw(const Graphics& graphics, const Point& point);
  
private:
  void init();
  
private:
  SDL_Texture* _texture;
  
  int _width;
  
  int _height;
  
  int _columns;
  
  int _startframe;

  int _frames;
  
  float _length;
  
  bool _repeatable;
  
  float _frameLength;
  
  float _frameTime;
  
  int _curFrame;
};
