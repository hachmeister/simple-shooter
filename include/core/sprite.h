#pragma once

struct SDL_Texture;

class Sprite
{
public:
  Sprite(SDL_Texture* t, int w, int h);
  
  ~Sprite();
  
  SDL_Texture* texture() const;
  
  int width() const;
  
  int height() const;
  
private:
  SDL_Texture* tex;
  
  int wd;
  
  int ht;
};
