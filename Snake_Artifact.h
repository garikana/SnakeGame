#include "Engine/Artifact.h"
#include<string>
#include<map>
#include<deque>
#include<SFML/Graphics.hpp>
/*
 * Snake Artifact class
 * Implements Artifact abstract class
 */

 class Snake_Artifact : public Artifact{
 public:
   Snake_Artifact(float s_size);
   bool update(std::map<std::string,Artifact*>& Game_Artifacts, sf::RenderWindow& window, std::vector<sf::Event>& Events);
   bool draw(sf::RenderWindow& window);
   std::pair<float,float> get_Position();
   int size();
 private:
   bool check_collision(std::map<std::string,Artifact*>& Game_Artifacts,sf::RenderWindow& window);
   bool eat_Apple(std::map<std::string,Artifact*>& Game_Artifacts,sf::RenderWindow& window);
   std::deque<sf::RectangleShape> data;
   sf::Color head_color{sf::Color::Red};
   sf::Color body_color{sf::Color::Green};
   float snake_size{20}; //size of snake cell in pixels
   sf::Keyboard::Key snake_dir; //current direction of snake movement

 };
