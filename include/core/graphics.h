#pragma once

#include <SDL.h>

class Rect;
class Sprite;
class Point;

class Graphics
{
public:
  Graphics(int width, int height);
  
  ~Graphics();
  
  void clear();
  
  void drawSprite(Sprite* sprite, const Rect& src, const Point& dest) const;
  
  void destroyTexture(SDL_Texture* texture);
  
  void drawTexture(SDL_Texture* texture, int x, int y) const;
  
  void drawTexture(SDL_Texture* texture, int srcX, int srcY, int srcW, int srcH, int destX, int destY) const;

  void flip();
  
  SDL_Texture* loadBMP(const char* file);
  
private:
  SDL_Window* window_;
  
  SDL_Renderer* renderer_;
};
