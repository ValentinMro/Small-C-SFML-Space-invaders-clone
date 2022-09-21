#include "window.hpp"
#include <iostream>

/* creating the initial window with SFML */
void window::createGameWindow(sf::RenderWindow& window)
{
    window.create(sf::VideoMode(1920, 1080), "Space Invaders");
    window.setFramerateLimit(60);
}

/* loading all required textures */
void window::loadTextures()
{
    if(!(backgroundTexture.loadFromFile("./img/background.jpg")))
    {
        std::cerr << "unable to load the background-texture!" << std::endl;
    }
    
    if(!(alienTexture.loadFromFile("./img/alien.png")))
    {
        std::cerr << "unable to load the alien-texture!" << std::endl;
    }

    if(!(playerTexture.loadFromFile("./img/player.png")))
    {
        std::cerr << "unable to load the player-texture!" << std::endl;
    }

    if(!(meteorTexture.loadFromFile("./img/meteor.png")))
    {
        std::cerr << "unable to load the meteor-texture!" << std::endl;    
    }

    if(!(fireballTexture.loadFromFile("./img/fireball.png")))
    {
        std::cerr << "unable to load the fireball-texture!" << std::endl;
    }
}

/* creates the sprites for all required objects */
void window::createSprites()
{
    backgroundSprite.setTexture(backgroundTexture);

    fireballSprite.setTexture(fireballTexture);
    fireballSprite.setRotation(125);
    fireballSprite.setOrigin(1600/2, 1600/2);
    fireballSprite.setScale(0.02, 0.02);

    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(0.7, 0.7);
    playerSprite.setOrigin((200/2), (167/2));

    for (int i = 0; i <= 80; i++)
    {
        alienSprites[i].setTexture(alienTexture);
        alienSprites[i].setScale(0.5, 0.5);
        alienSprites[i].setOrigin((200/2), (145/2));
    }
}

/* function to set the positions of all sprites in the game */
void window::setNewSpritePositions(sf::Vector2f playerPosition, sf::Vector2f fireballPosition, sf::Vector2f alienPositions[])
{
    playerSprite.setPosition(playerPosition);
    fireballSprite.setPosition(fireballPosition);

    for (int i = 1; i < 81; i++)
    {
        alienSprites[i].setPosition(alienPositions[i]);
    }
}

/* draws the frame on the window */
void window::drawFrame(sf::RenderWindow& gameWindow, bool deactivatedAliens[])
{
    gameWindow.draw(backgroundSprite);
    gameWindow.draw(playerSprite);  
    gameWindow.draw(fireballSprite);

    for (int i = 1; i < 81; i++)
    {
        if(!deactivatedAliens[i])
        gameWindow.draw(alienSprites[i]);
    }
}