#pragma once

class Graphics;

struct SDL_Texture;

class Star
{
public:
  Star(SDL_Texture* sprite, int num, float x, float y, float speed);
  
  ~Star();
  
  void update(float dt);
  
  void draw(const Graphics& graphics);
  
private:
  SDL_Texture* sprite_;
  
  int num_;
  
  float posX_;
  
  float posY_;
  
  float speed_;
};
