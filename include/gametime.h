#pragma once

class GameTime
{
public:
  GameTime()
  {
    dt = 0;
    tl = 0;
  }
  
  ~GameTime()
  {
  }
  
  float delta() const;
  
  float total() const;
  
  void setDelta(float delta);
  
  void setTotal(float total);
  
private:
  float dt;
  
  float tl;
};

inline float GameTime::delta() const
{
  return dt;
}

inline float GameTime::total() const
{
  return tl;
}

inline void GameTime::setDelta(float delta)
{
  dt = delta;
}

inline void GameTime::setTotal(float total)
{
  tl = total;
}
