#include "Engine/Artifact.h"
#include<string>
#include<map>
#include<SFML/Graphics.hpp>
/*
 * Apple Artifact class
 * Implements Artifact abstract class
 */

class Apple_Artifact : public Artifact{
public:
  Apple_Artifact(float sz);
  bool update(Artifact_Map& Game_Artifacts, sf::RenderWindow& window, Event_Vec& Events);
  bool draw(sf::RenderWindow& window);
  std::pair<float,float> get_Position();
  int size();

private:
  bool eaten_Snake(Artifact_Map& Game_Artifacts);
  sf::RectangleShape data;
  sf::Color apple_color{sf::Color::Green};
  float apple_size{20}; //size in pixels
};
