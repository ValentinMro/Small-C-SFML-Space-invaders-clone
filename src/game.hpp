#ifndef GAME_HPP
#define GAME_HPP

#define BOTTOM_PLAYER_DISTANCE 950
#define LOOSING_LINE 850


#include "window.hpp"
#include "playerInputs.hpp"
#include "gameStats.hpp"
#include "gameSounds.hpp"

class game
{
    public:
    game();
    
    void createWindow();
    void run();
    void createGameLoop();
    void moveObjects(sf::Keyboard::Key pressedKey);
    void moveAliens();
    void createFireball(sf::Keyboard::Key pressedKey);
    void detectCollision();
    
    private:
    int alienState = 1;                 // -> for counting the different states of moving the aliens
    int alienPositionX {1561};          // -> x position of the 16th alien in the beginning
    int alienPositionY {40};            // -> y position of the 16th alien in the beginning
    
    double alienSpeed {0.5};
    double fireballSpeed {20};
    
    bool fireballActive {false};
    bool deactivatedAlienSprites[80];   // -> saves the sprites which got killed by the player
    
    window Window;
    playerInputs Inputs;
    gameStats Stats;
    gameSounds Sounds;

    sf::RenderWindow gameWindow;
    sf::Event eventHandler;
    sf::Clock gameClock;
    sf::Time gameTime;
    sf::Vector2f playerPositionV2F, alienPositionsV2F[81];
    sf::Vector2f fireballPositionV2F;
};

#endif // GAME_HPP