#pragma once

#include <map>
#include <string>

class Enemy;
class Graphics;
class Player;
class Sprite;
class Star;

struct SDL_Texture;

class EntityFactory
{
public:
  EntityFactory(Graphics& g);
  
  ~EntityFactory();
  
  Player* createPlayer();
  
  Star* createStar();
  
  Enemy* createEnemy();
  
private:
  Sprite* createSprite(const std::string& key, const char* file);
  
  SDL_Texture* getTexture(const std::string& key, const char* file);
  
  Graphics& graphics;
  
  std::map<std::string, SDL_Texture*> textures_;
};
