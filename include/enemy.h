#pragma once

class Graphics;
class Rect;
class Sprite;
class Vector2;

class Enemy
{
public:
  Enemy(Sprite* spr, float x, float y, float spd);
  
  ~Enemy();
  
  void update(float dt);
  
  void draw(const Graphics& graphics);
  
  Vector2 position() const;
  
  Rect rect() const;
  
  bool active() const;
  
private:
  bool act;
  
  Sprite* sprite;
  
  float posX;
  
  float posY;
  
  float speed;  
};
