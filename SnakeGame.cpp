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
  float artifact_sz = 30;
  Snake_Artifact s{artifact_sz};
  Apple_Artifact a{artifact_sz};

  //add game artifacts to game engine object
  g.add_Artifacts("Snake",s);
  g.add_Artifacts("Apple",a);

  //run game
  g.run();
  //end game
  g.end();

}
