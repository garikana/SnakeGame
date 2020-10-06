#include "Apple_Artifact.h"
#include <stdlib.h>

//default constructor
Apple_Artifact::Apple_Artifact(float sz)
 :apple_size{sz}
{
  data = sf::RectangleShape(sf::Vector2f(apple_size,apple_size));
  data.setFillColor(apple_color);
  data.setPosition(10*sz, sz);

}

//check if Apple is eaten by Snake
bool Apple_Artifact::eaten_Snake(std::map<std::string,Artifact*>& Game_Artifacts){
  Artifact* snake = Game_Artifacts["Snake"];
  std::pair<float,float> snake_pos = snake->get_Position();
  sf::Vector2f apple_pos = data.getPosition();
  if(snake_pos.first == apple_pos.x && snake_pos.second == apple_pos.y)
    return true;
  return false;
}

// Implements abstract concept of Artifact size
// returns no of sf::Shape objects apple artifact is made of
int Apple_Artifact::size(){
  //only 1 apple always
  return 1;
}

// Implement abstract Artifact get_Position method
// return Apple Artifact position in the window
std::pair<float,float> Apple_Artifact::get_Position(){
  sf::Vector2f pos = data.getPosition();
  return std::pair<float,float>({pos.x, pos.y});
}

// Draw Apple Artifact to window
bool Apple_Artifact::draw(sf::RenderWindow& window){
  window.draw(data);
  return true;
}

// Implements Apple Artifact update
// Apple Artifact update => generate next Apple position if eaten by Snake
bool Apple_Artifact::update(std::map<std::string,Artifact*>& Game_Artifacts,
                        sf::RenderWindow& window,
                        std::vector<sf::Event>& Events){
  if(eaten_Snake(Game_Artifacts)){
    //update apple position randomly in the window
    sf::Vector2u win_sz = window.getSize();
    int win_width = win_sz.x;
    int win_height = win_sz.y;
    float new_x = (float)((int)apple_size*(rand() % (win_width/(int)apple_size)));
    float new_y = (float)((int)apple_size*(rand() % (win_height/(int)apple_size)));
    data.setPosition(new_x, new_y);
  }
  return true;
}
