#include "core/graphics.h"

#include "core/rect.h"
#include "core/sprite.h"
#include "core/point.h"

#include <stdexcept>

Graphics::Graphics(int width, int height)
{
  // init SDL
  if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
    throw std::logic_error("SDL_Init failed!");
  }
  
  window_ = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
  //window_ = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);
  //window_ = SDL_CreateWindow("Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE);
  
  if (window_ == NULL) {
    throw std::logic_error("SDL_CreateWindow failed!");
  }
  
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  //renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer_ == NULL) {
    throw std::logic_error("SDL_CreateRenderer failed!");
  }
}

Graphics::~Graphics()
{
  if (renderer_) {
    SDL_DestroyRenderer(renderer_);
  }
  
  if (window_) {
    SDL_DestroyWindow(window_);
  }
  
  SDL_Quit();
}

void Graphics::clear()
{
  SDL_RenderClear(renderer_);
}

void Graphics::drawSprite(Sprite* sprite, const Rect& src, const Point& dest) const
{
  SDL_Rect srcRect = {src.x(), src.y(), src.width(), src.height()};
  SDL_Rect destRect = {dest.x(), dest.y(), src.width(), src.height()};
  SDL_RenderCopy(renderer_, sprite->texture(), &srcRect, &destRect);
}

void Graphics::drawTexture(SDL_Texture* texture, const Rect& src, const Point& dest) const
{
  SDL_Rect srcRect = {src.x(), src.y(), src.width(), src.height()};
  SDL_Rect destRect = {dest.x(), dest.y(), src.width(), src.height()};
  SDL_RenderCopy(renderer_, texture, &srcRect, &destRect);
}
  
void Graphics::drawTexture(SDL_Texture* texture, const Rect& src, const Rect& dest, float scale, float angle) const
{
  SDL_Rect srcRect = {src.x(), src.y(), src.width(), src.height()};
  SDL_Rect destRect = {dest.x(), dest.y(), (float)dest.width()*scale, (float)dest.height()*scale};
  SDL_Point p = {32, 32};
  SDL_RenderCopyEx(renderer_, texture, &srcRect, &destRect, angle, &p, SDL_FLIP_NONE);
}
  
void Graphics::drawTexture(SDL_Texture* texture, int x, int y) const
{
  Uint32 format;
  int access, w, h;
  
  SDL_QueryTexture(texture, &format, &access, &w, &h);
  
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  dest.w = w;
  dest.h = h;

  SDL_RenderCopy(renderer_, texture, NULL, &dest);
}

void Graphics::drawTexture(SDL_Texture* texture, int srcX, int srcY, int srcW, int srcH, int destX, int destY) const
{
  Uint32 format;
  int access, w, h;
  
  SDL_Rect src;
  src.x = srcX;
  src.y = srcY;
  src.w = srcW;
  src.h = srcH;
  
  SDL_QueryTexture(texture, &format, &access, &w, &h);
  
  SDL_Rect dest;
  dest.x = destX;
  dest.y = destY;
  dest.w = srcW;
  dest.h = srcH;

  SDL_RenderCopy(renderer_, texture, &src, &dest);
}

void Graphics::destroyTexture(SDL_Texture* texture)
{
  SDL_DestroyTexture(texture);
}

void Graphics::flip()
{
  SDL_RenderPresent(renderer_);
}

SDL_Texture* Graphics::loadBMP(const char* file)
{
  SDL_Surface* surface = SDL_LoadBMP(file);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer_, surface);
  SDL_FreeSurface(surface);
  
  return texture;
}

void Graphics::toggleFullscreen()
{
  Uint32 flags = SDL_GetWindowFlags(window_);
  
  if (flags & SDL_WINDOW_MAXIMIZED) {
    SDL_RestoreWindow(window_);
  }
  else {
    SDL_MaximizeWindow(window_);
  }
  
  /*if (flags & SDL_WINDOW_FULLSCREEN) {
    SDL_SetWindowFullscreen(window_, SDL_FALSE);
  }
  else {
    SDL_SetWindowFullscreen(window_, SDL_TRUE);
  }*/
}
