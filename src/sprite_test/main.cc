#include "core/game.h"

#include "sprite_test/batchstate.h"

int main()
{
  Game game;
  game.start(new BatchState());

  return 0;
}
