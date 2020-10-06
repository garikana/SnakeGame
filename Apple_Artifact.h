#include "Artifact.h"
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
  bool update(std::map<std::string,Artifact*>& Game_Artifacts, sf::RenderWindow& window, std::vector<sf::Event>& Events);
  bool draw(sf::RenderWindow& window);
  std::pair<float,float> get_Position();
  int size();

private:
  bool eaten_Snake(std::map<std::string,Artifact*>& Game_Artifacts);
  sf::RectangleShape data;
  sf::Color apple_color{sf::Color::Green};
  float apple_size{20}; //size in pixels
};
