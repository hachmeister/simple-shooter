#pragma once

class Graphics;
class Rect;
class Sprite;
class Point;

class Projectile
{
public:
  Projectile(Sprite* spr, float x, float y, float spd);
  
  ~Projectile();
  
  void update(float dt);
  
  void draw(const Graphics& graphics);
  
  Point position() const;
  
  Rect rect() const;
  
  bool active() const;
  
private:
  bool act;
  
  Sprite* sprite;
  
  float posX;
  
  float posY;
  
  float speed;  
};
