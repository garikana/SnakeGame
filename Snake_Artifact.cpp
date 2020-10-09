#include "Snake_Artifact.h"
#include<iostream>
//constructor
Snake_Artifact::Snake_Artifact(float sz)
  :snake_size{sz}
{
  sf::RectangleShape head{sf::RectangleShape(sf::Vector2f(snake_size,snake_size))};
  head.setFillColor(head_color);
  head.setPosition(0, sz);
  data.push_back(head);
}

std::pair<float,float> Snake_Artifact::get_Position(){
  sf::RectangleShape head = data.front();
  sf::Vector2f head_pos = head.getPosition();
  return std::pair<float,float>({head_pos.x,head_pos.y});
}

int Snake_Artifact::size(){
  //head should not be counted as size
  return data.size()-1;
}
//collison with window or with itself
bool Snake_Artifact::check_collision(Artifact_Map& Game_Artifacts,
                                     sf::RenderWindow& window){
  //check collision with Window
  sf::RectangleShape head = data.front();
  sf::Vector2f head_pos = head.getPosition();
  sf::Vector2u window_sz = window.getSize();
  if(head_pos.x < 0 || head_pos.x > (float)(window_sz.x-snake_size) ||
     head_pos.y < 0 || head_pos.y > (float)(window_sz.y-snake_size)){
     //std::cout<<"Collision detected\n";
     return true;
   }
   //check collision with itself
   std::deque<sf::RectangleShape>::iterator it = data.begin();
   it++; sf::RectangleShape body;
   for(;it != data.end();it++){
     body = *it;
     sf::Vector2f body_pos = body.getPosition();
     if(head_pos.x == body_pos.x && head_pos.y == body_pos.y){
       //std::cout<<"Collision with itself\n";
       return true;
     }
   }
  return false;
}

//collision with Apple
bool Snake_Artifact::eat_Apple(Artifact_Map& Game_Artifacts,
                               sf::RenderWindow& window){
  std::pair<float,float> apple_pos = Game_Artifacts["Apple"]->get_Position();
  sf::RectangleShape head = data.front();
  sf::Vector2f head_pos = head.getPosition();
  if(head_pos.x == apple_pos.first && head_pos.y == apple_pos.second)
    return true;
  return false;
}

//draw - implements snake draw
bool Snake_Artifact::draw(sf::RenderWindow& window){
  for(sf::RectangleShape r : data){
    window.draw(r);
  }
  return true;
}


//update - implements snake Artifact update
// snake update => snake movement
bool Snake_Artifact::update(Artifact_Map& Game_Artifacts,
                        sf::RenderWindow& window, Event_Vec& Events){

  for(sf::Event event : Events){
    switch(event.type)
    {
      case sf::Event::Closed:
        window.close();
        return false;
      case sf::Event::KeyPressed:
        if(event.key.code == sf::Keyboard::Up && !(snake_dir == sf::Keyboard::Down))
          snake_dir = event.key.code;
        if(event.key.code == sf::Keyboard::Down && !(snake_dir == sf::Keyboard::Up))
          snake_dir = event.key.code;
        if(event.key.code == sf::Keyboard::Left && !(snake_dir == sf::Keyboard::Right))
          snake_dir = event.key.code;
        if(event.key.code == sf::Keyboard::Right && !(snake_dir == sf::Keyboard::Left))
          snake_dir = event.key.code;
        break;
    }
  }
  //std::cout<<"Snake size is"<<data.size()<<"\n";
  sf::RectangleShape& head = data.front();
  sf::Vector2f head_pos = head.getPosition();
  sf::RectangleShape new_head{sf::RectangleShape(sf::Vector2f(snake_size,snake_size))};
  //create new head & attach to snake
  switch(snake_dir){
    case sf::Keyboard::Up:
      new_head.setFillColor(head_color);
      new_head.setPosition(head_pos.x,head_pos.y-snake_size);
      head.setFillColor(body_color);
      data.push_front(new_head);
      if(!eat_Apple(Game_Artifacts,window)){
        data.pop_back(); //remove tail of snake
      }
      break;
    case sf::Keyboard::Down:
      new_head.setFillColor(head_color);
      new_head.setPosition(head_pos.x,head_pos.y+snake_size);
      head.setFillColor(body_color);
      data.push_front(new_head);
      if(!eat_Apple(Game_Artifacts,window)){
        data.pop_back(); //remove tail of snake
      }
      break;
    case sf::Keyboard::Left:
      new_head.setFillColor(head_color);
      new_head.setPosition(head_pos.x-snake_size,head_pos.y);
      head.setFillColor(body_color);
      data.push_front(new_head);
      if(!eat_Apple(Game_Artifacts,window)){
        data.pop_back(); //remove tail of snake
      }
      break;
    case sf::Keyboard::Right:
      new_head.setFillColor(head_color);
      new_head.setPosition(head_pos.x+snake_size,head_pos.y);
      head.setFillColor(body_color);
      data.push_front(new_head);
      if(!eat_Apple(Game_Artifacts,window)){
        data.pop_back(); //remove tail of snake
      }
      break;
  }

  //check collision
  return !(check_collision(Game_Artifacts,window));

}
