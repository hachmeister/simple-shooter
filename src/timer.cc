#include "timer.h"

#include <iostream>

Timer::Timer()
{
  gettimeofday(&start_, 0);
}

Timer::~Timer()
{
}

unsigned long Timer::millis() const
{
  struct timeval now;
  gettimeofday(&now, 0);
  return (now.tv_sec - start_.tv_sec)*1000 + (now.tv_usec - start_.tv_usec)/1000;
}

void Timer::sleep(unsigned long millis) const
{
  struct timeval tv;
  
  tv.tv_sec = millis / 1000;
  tv.tv_usec = (millis * 1000) % 1000000;
  
  select(0, 0, 0, 0, &tv);
}
