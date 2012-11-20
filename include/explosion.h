#pragma once

class Graphics;
class Rect;
class Sprite;
class Vector2;

class Explosion
{
public:
  Explosion(Sprite* spr, int num, int x, int y, int width, int height, float frameTime);
  
  ~Explosion();
  
  void update(float dt);
  
  void draw(const Graphics& graphics);
  
  Vector2 position() const;
  
  Rect rect() const;
  
  bool active() const;
  
private:
  bool act;
  
  Sprite* sprite;
  
  int num;
  
  int curNum;
  
  int posX;
  
  int posY;
  
  int wd;
  
  int ht;
  
  float fl;
  
  float ft;
};
