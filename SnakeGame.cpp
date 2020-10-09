#include "Engine/Game.h"
#include "Snake_Artifact.h"
#include "Apple_Artifact.h"

int main()
{
  //instantiate Snake Game Engine;
  Game g{"SnakeGame"};
  //initialize game engine with
  //game refresh rate, window size, font to use for displaying text
  g.init(0.20,std::pair<float,float>({1280,720}),"./fonts/Sweet_Creamy.ttf");
  //create game artifacts
  //constructor accepts size in pixels
  constexpr float artifact_sz = 30;
  //Snake_Artifact s{artifact_sz};
  //Apple_Artifact a{artifact_sz};

  //add game artifacts to game engine object
  //using smart_ptr to game artifacts serves 2 purposes
  //1. smart_ptrs can be passed to game engine to enable run-time polymorphism
  //2. smart_ptrs automatically transfer artifact ownership to game-engine from main
  g.add_Artifacts("Snake",std::make_unique<Snake_Artifact>(artifact_sz));
  g.add_Artifacts("Apple",std::make_unique<Apple_Artifact>(artifact_sz));

  //run game
  g.run();
  //end game
  g.end();

}
