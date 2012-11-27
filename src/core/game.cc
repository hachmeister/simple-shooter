#include "core/game.h"

#include <iostream>
#include <map>

#include "core/gametime.h"
#include "core/state.h"
#include "core/timer.h"

Game::Game()
  : g(800, 600), running(false), current(0), next(0)
{
}

Game::~Game()
{
  if (current) {
    delete current;
  }
}

void Game::start(State* state)
{
  current = state;
  current->init(this);
  
  Timer timer;
  GameTime time;
  unsigned long start = timer.millis();
  unsigned long prev = start;
  unsigned long cur = start;
  unsigned long delta = 0;
  unsigned long ft;
  
  unsigned long count = 0;
  int frames = 0;
  
  running = true;
  
  while (running) {
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
    
    current->input(time);
    
    if (time.delta() > 0) {
      current->update(time);
    }
    
    current->draw(time);
    
    if (next) {
      delete current;
      current = next;
      current->init(this);
      next = 0;
    }
    
    /*ft = timer.millis() - cur;
    
    if (ft < 17) {
      timer.sleep(17 - ft);
    }*/
  }
}

void Game::stop()
{
  running = false;
}

void Game::changeState(State* state)
{
  if (next != 0) {
    delete next;
  }
  
  next = state;
}

Graphics* Game::graphics()
{
  return &g;
}

Sounds* Game::sounds()
{
  return &s;
}
