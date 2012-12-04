#include "sprite_test/batchstate.h"

#include <stdlib.h>
#include <time.h>

#include "core/gametime.h"
#include "core/point.h"
#include "core/rect.h"

const int WIDTH = 1280;
const int HEIGHT = 800;
const int MAX_SCALE = 2;

class Object
{
public:
  Point pos;
  float xSpeed;
  float ySpeed;
  float rotation;
  float rotationSpeed;
  float scale;
  float scaleSpeed;
};

BatchState::BatchState()
  : graphics(0), sounds(0)
{
}

BatchState::~BatchState()
{
}

void BatchState::init(Game* g)
{
  Object obj;
  
  srand(time(NULL));
  
  for (int i = 0; i < 40000; ++i) {
    obj.pos.setX(rand() % WIDTH);
    obj.pos.setY(rand() % HEIGHT);
    obj.xSpeed = (rand() % 800) - 400;
    obj.ySpeed = (rand() % 800) - 400;
    obj.rotation = 0;
    obj.rotationSpeed = (rand() % 100) - 50.0f;
    obj.scale = 1;
    obj.scaleSpeed = (float)((rand() % (2 * MAX_SCALE * 1000)) - MAX_SCALE * 1000) / 1000.0f;
    
    objectes.push_back(obj);
  }
  
  
  game = g;
  graphics = g->graphics();
  sounds = g->sounds();
  
  texture = graphics->loadBMP("../resources/blowfish.bmp");
}

void BatchState::input(const GameTime& time)
{
  SDL_Event event;

  while(SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN: {
        SDL_KeyboardEvent* key = &event.key;
        switch (key->keysym.sym) {
          case SDLK_ESCAPE:
            game->stop();
            break;
          case SDLK_p: {
            if (game->is_paused()) {
              game->resume();
            }
            else {
              game->pause();
            }
          }
          default:
            break;
        }
        break;
      }
      case SDL_QUIT:
        game->stop();
        break;
    }
  }
}

void BatchState::update(const GameTime& time)
{
  Object* obj;
  
  int moveX, moveY;
  Point newPos;
  float scale;
  
  for (std::vector<Object>::iterator it = objectes.begin(); it != objectes.end(); ++it) {
    obj = &(*it);
    
    moveX = obj->xSpeed * time.delta();
    moveY = obj->ySpeed * time.delta();
    
    newPos.setX(obj->pos.x() + moveX);
    newPos.setY(obj->pos.y() + moveY);
    
    if (newPos.x() < -63 || newPos.x() >= WIDTH || newPos.y() < -63 || newPos.y() >= HEIGHT) {
      newPos.setX(obj->pos.x() - moveX);
      newPos.setY(obj->pos.y() - moveY);
      obj->xSpeed = -obj->xSpeed;
      obj->ySpeed = -obj->ySpeed;
    }
    
    obj->pos.setX(newPos.x());
    obj->pos.setY(newPos.y());
    
    obj->rotation += obj->rotationSpeed * time.delta();
    
    scale = obj->scaleSpeed * time.delta();
    
    if (obj->scale + scale <= -MAX_SCALE || obj->scale + scale >= MAX_SCALE) {
      scale = -scale;
      obj->scaleSpeed = -obj->scaleSpeed;
    }
    
    obj->scale += scale;
  }
}

void BatchState::draw(const GameTime& time)
{
  graphics->clear();
  
  for (std::vector<Object>::iterator it = objectes.begin(); it != objectes.end(); ++it) {
    graphics->drawTexture(texture, Rect(0, 0, 64, 64), Rect((*it).pos.x(), (*it).pos.y(), 64, 64), (*it).scale, (*it).rotation);
  }
  
  graphics->flip();
}
