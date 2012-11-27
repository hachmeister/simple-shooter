#include "core/game.h"

#include "introstate.h"

int main()
{
  Game game;
  game.start(new IntroState());

  return 0;
}
