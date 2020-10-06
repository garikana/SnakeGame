#include "Game.h"
#include<iostream>
Game::Game(std::string g_name){
  game_name = g_name;
}

void Game::init(float r_rate,
  std::pair<float,float> screen_res,
  std::string path_to_font){
    win_refresh_freq = sf::seconds(r_rate);
    window.create(sf::VideoMode(screen_res.first, screen_res.second), game_name,sf::Style::Close);
    window.setKeyRepeatEnabled(false); //held key is read only once
    game_font.loadFromFile(path_to_font);
}

// add game artifacts
void Game::add_Artifacts(std::string Artifact_Name, Artifact& a){
  Artifacts[Artifact_Name] = &a;
}

// Game run
void Game::run(){
  /*
   * 1)check if clock time > game refresh rate
   * 2)get input game events
   * 3)update game artifacts
   * 4)display game artifacts to Screen
   * 5)goto step 1
   */
   sf::Clock clock; //start game clock
   while(window.isOpen()){

     //check if time to refresh window
     sf::Time elapsed_time = clock.getElapsedTime();
     if(elapsed_time < win_refresh_freq)
       continue;
     else
       clock.restart();

     /* get input events */
     std::vector<sf::Event> Events = get_Input();

     /* clear window */
     window.clear(sf::Color::Black);

     //update game state for each event
     if(!update_State(Events)){
       std::cout<<"Game Ended\n";
       return;//game ended
     }else{
       //display game artifacts to Screen
       draw_to_screen();
     }
   }
   return;
}

int Game::get_Score(){
  //snake game scoring is
  //counting the size of the snake
  return Artifacts["Snake"]->size();
}
void Game::draw_to_screen(){

  //display all game artifacts
  for(std::pair<std::string,Artifact*> p: Artifacts){
    //std::cout<<p.first<<"drawn\n";
    (p.second)->draw(window);
  }

  //display game score
  int score = get_Score();
  sf::Text text;
  text.setFont(game_font);
  sf::Vector2u win_sz = window.getSize();
  text.setPosition(win_sz.x-200,50);
  text.setString("Score :"+std::to_string(score));
  text.setCharacterSize(25);
  text.setFillColor(sf::Color::Red);
  window.draw(text);
  window.display();
}

//game update
bool Game::update_State(std::vector<sf::Event>& Events){
  //game state is Artifacts Vector
  /*for(std::pair<std::string,Artifact*> p: Artifacts){
    //we pass the game class as input
    //to a.update. This is game context
    //Artifact can only update themselves
    //when there is a game-context
    if(!((p.second)->update(Artifacts,window))){
      return false;
    }
  }*/
  //first update snake
  if(!Artifacts["Snake"]->update(Artifacts,window,Events))
    return false;
  if(!Artifacts["Apple"]->update(Artifacts,window,Events))
    return false;
  return true;
}
/* get event input */
std::vector<sf::Event> Game::get_Input(){
  std::vector<sf::Event> Events;
  sf::Event event;
  while(window.pollEvent(event)){
    Events.push_back(event);
  }
  return Events;
}

/* return game window reference */
sf::RenderWindow& Game::get_Window(){ return window; }

void Game::end(){
  if(window.isOpen()){
    //display end game artifacts to screen
    sf::Text text;
    text.setFont(game_font);
    sf::Vector2u win_sz = window.getSize();
    text.setString("Game Over");
    text.setCharacterSize(50);
    text.setPosition(win_sz.x/2-50*(9/2),win_sz.y/2-(50/2));
    text.setFillColor(sf::Color::Red);
    window.draw(text);
    window.display();
    sf::sleep(sf::seconds(3));
    window.close();
  }

}
