#include "Artifact.h"
#include<string>
#include<map>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

/*
 * Game class
 * This class is the main game engine
 * Can be sub-classed to implement below virtual methods
 * 1) update_State //updates game artifacts based on game input events
 * 2) get_Score    //get game score
 * 3) end         //end game
 */
 class Game{
 public:
   //default constructor
   Game(std::string g_name);
   //initalize game
   void init(float r_rate,std::pair<float,float> screen_res,std::string path_to_font);

   // add game artifacts
   void add_Artifacts(std::string Artifact_Name, Artifact& a);

   //start game
   void run();

   //end game method
   //can be overridden by sub class
   virtual void end();

   //un-used
   sf::RenderWindow& get_Window();

 protected:
   //game update is game dependent, should be virtual
   virtual bool update_State(Event_Vec& Events);

   //scoring is game dependent, should be virtual
   virtual int get_Score();

   // get input Events
   std::vector<sf::Event> get_Input();

   //draw game state to Screen
   void draw_to_screen();
 private:
   sf::RenderWindow window; //main game Window
   Artifact_Map Artifacts; //game artifacts collection
   sf::Time win_refresh_freq; //game refresh rate in secs
   std::string game_name{""}; //name of the game
   sf::Font game_font; //font to use for all text in the game

 };
