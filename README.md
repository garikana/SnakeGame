# SnakeGame
Object-Oriented Implementation of SnakeGame in C++

[![Snake Game](Videos/SnakeGame.gif)

### Build Instructions
1) This implementation using SFML Graphic library. Hence copy SFML library files to your platform's usual locations(Ex:- headers to /usr/local/include & lib 
files to /usr/local/lib).
2) Clone this repo to your platform
3) Build executable using the below command. For more detailed instructions in compiling and linking programs using SFML, read 'Getting Started" secion of the link
[SFML compile & link](https://www.sfml-dev.org/tutorials/2.5/)
```
g++ -std=c++11 -o SnakeGame SnakeGame.cpp Engine/Game.cpp Snake_Artifact.cpp Apple_Artifact.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
### Game Architecture
#### Classes:-
The game is built on 2 main classes.
1) Game:- 
This class is the game engine. It consists of the below methods.
   - init
     - Initializes game engine with screen-res, game refresh rate & game font
   - add_Artifacts
     - Adds Game Artifacts. A Game Artifact is an abstraction of object displayed in the game
   - run
     - Run the game
   - end
     - End the game
     

Below are protected methods 
   - update_State
     - updates Game Artifacts based on input game events. Can be overriden in a sub-class
   - get_Input
     - polls user inputs like keystrokes,  mouse-clicks etc.
   - get_Score
     - calculates and returns game score. Can be overriden in a sub-class
2) Artifact:- This class is abstact concept of a game Artifact. It should be implemented. For Snake Game we define 2 sub-classes - Snake_Artifact & Apple_Artifact 
which implement this abstract class.
Below are the pure-virtual methods that should be implemented.
   - update
     -  updates artifact based on game environment & input events
   - draw
     -  draws artifact to screen
   - get_Position
     -  returns position of the artifact of the screen
   - size
     -  returns size of the artifact
     
3) Snake_Artifact:- Implementation of Artifact abstract class. This represents the Snake artifact in the game.
4) Apple_Artifact:- Implementation of Artifact abstract class. This represents the Apple artifact in the game.

#### Putting Everything Together
SnakeGame.cpp puts everything together. It does the following in the order specified.
1) Creates game engine object.
2) Initializes the game engine object.
3) Creates game artifacts - Snake & Apple.
4) Adds the game artifacts to the game engine object.
4) Calls run method on game engine object
5) Calls end method on game engine object
