#pragma once

#include <map>
#include <string>

struct SDL_Texture;

class Animation;
class Graphics;
class Point;

class Sprite
{
public:
  Sprite();
  
  Sprite(SDL_Texture* t, int w, int h);
  
  Sprite(Animation* animation);
  
  ~Sprite();
  
  void addAnimation(const std::string& name, Animation* animation);
  
  void setCurrentAnimation(const std::string& name);
  
  void update(float dt);
  
  void draw(const Graphics& graphics, const Point& point);
  
  SDL_Texture* texture() const;
  
  int width() const;
  
  int height() const;
  
private:
  std::map<std::string, Animation*> _animations;
  
  Animation* _currentAnimation;
  
  SDL_Texture* tex;
  
  int wd;
  
  int ht;
};
