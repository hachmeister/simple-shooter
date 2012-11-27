#include "introstate.h"

#include "core/gametime.h"

#include "playstate.h"

IntroState::IntroState()
  : graphics(0), sounds(0)
{
}

IntroState::~IntroState()
{
}

void IntroState::init(Game* g)
{
  game = g;
  graphics = g->graphics();
  sounds = g->sounds();
  
  background = graphics->loadBMP("../resources/intro_background.bmp");
}

void IntroState::input(const GameTime& time)
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
          case SDLK_SPACE:
            game->changeState(new PlayState());
            break;
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

void IntroState::update(const GameTime& time)
{
}

void IntroState::draw(const GameTime& time)
{
  graphics->clear();
  
  graphics->drawTexture(background, 0, 0);
  
  graphics->flip();
}
