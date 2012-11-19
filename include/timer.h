#pragma once

#include <sys/time.h>

class Timer
{
public:
  Timer();
  
  ~Timer();
  
  unsigned long millis() const;
  
  void sleep(unsigned long millis) const;

private:
  struct timeval start_;
};
