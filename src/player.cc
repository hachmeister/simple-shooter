#include "player.h"

#include "core/graphics.h"
#include "core/rect.h"
#include "core/sprite.h"
#include "core/point.h"

#include <iostream>

Player::Player(Sprite* spr, float x, float y, float spd)
  : sprite(spr), posX(x), posY(y), speed(spd)
{
}

Player::~Player()
{
}

void Player::update(float dt)
{
  if ((moveLeft && !moveRight) || (!moveLeft && moveRight)) {
    int direction = (moveLeft) ? -1 : 1;
    posX += direction * dt * speed;
  }
  
  if ((moveUp && ! moveDown) || (!moveUp && moveDown)) {
    int direction = (moveUp) ? -1 : 1;
    posY += direction * dt * speed;
  }
  
  if (posX < 0.0) {
    posX = 0.0;
  }
  
  if (posX + sprite->width() > 800.0) {
    posX = 800.0 - sprite->width();
  }
  
  if (posY < 0.0) {
    posY = 0.0;
  }
  
  if (posY + sprite->height() > 600.0) {
    posY = 600.0 - sprite->height();
  }
}

void Player::draw(const Graphics& graphics)
{
  graphics.drawSprite(sprite, Rect(0, 0, sprite->width(), sprite->height()), Point(posX, posY));
}

Point Player::position() const
{
  return Point(posX, posY);
}

Rect Player::rect() const
{
  return Rect(posX, posY, sprite->width(), sprite->height());
}

void Player::setMoveLeft(bool m)
{
  moveLeft = m;
}

void Player::setMoveRight(bool m)
{
  moveRight = m;
} 

void Player::setMoveUp(bool m)
{
  moveUp = m;
}

void Player::setMoveDown(bool m)
{
  moveDown = m;
} 
