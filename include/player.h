#pragma once

class Graphics;
class Rect;
class Sprite;
class Point;

class Player
{
public:
  Player(Sprite* spr, float x, float y, float spd);
  
  ~Player();
  
  void update(float dt);
  
  void draw(const Graphics& graphics);
  
  Point position() const;
  
  Rect rect() const;
  
  void setMoveLeft(bool m);
  
  void setMoveRight(bool m);
  
  void setMoveUp(bool m);
  
  void setMoveDown(bool m);
  
private:
  Sprite* sprite;
  
  float posX;
  
  float posY;
  
  float speed;
  
  bool moveLeft;
  
  bool moveRight;
  
  bool moveUp;
  
  bool moveDown;
};
