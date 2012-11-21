#include "game.h"

#include <iostream>
#include <map>

#include "gametime.h"
#include "timer.h"

Game::Game()
  : running_(true)//, input_(0)
{
  //input_ = new Input(hWnd);
}

Game::~Game()
{
  /*if (input_) {
    delete input_;
  }*/
}

void Game::start()
{
  // call setup method
  setup();
  
  Timer timer;
  GameTime time;
  unsigned long start = timer.millis();
  unsigned long prev = start;
  unsigned long cur = start;
  unsigned long delta = 0;
  unsigned long ft;
  
  unsigned long count = 0;
  int frames = 0;
  
  while (running_) {
    prev = cur;
    cur = timer.millis();
    delta = cur - prev;
    
    time.setDelta((float)delta / 1000.0f);
    time.setTotal((float)(cur - start) / 1000.0f);
    
    frames++;
    count += delta;
    if (count >= 5000) {
      std::cout << (int)(frames/5) << " FPS\n";
      count -= 5000;
      frames = 0;
    }
    
    input(time);
    
    if (time.delta() > 0) {
      update(time);
    }
    
    draw(time);
    
    ft = timer.millis() - cur;
    
    if (ft < 16) {
      timer.sleep(16 - ft);
    }
  }
}

void Game::stop()
{
  running_ = false;
}
