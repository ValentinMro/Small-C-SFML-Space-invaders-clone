#include "game.hpp"
#include <iostream>
#include <cmath>        //because of std::abs()
#include <cstdlib>      //because of std::abs()

/* setting up the default positions for the game-objects in the constructor */
game::game()    
{
    playerPositionV2F.x = SCREEN_WIDTH/2;
    playerPositionV2F.y = BOTTOM_PLAYER_DISTANCE;

    fireballPositionV2F.x = 1600;
    fireballPositionV2F.y = 800;

    for (int i = 0; i <= 80; i++)
    {
        if(i < 17)
        {
            if(i == 0)
            {
                alienPositionsV2F[i].x = SCREEN_BORDER_X;
                alienPositionsV2F[i].y = SCREEN_BORDER_Y;
            }
            if(i != 0)
            {
                alienPositionsV2F[i].x = (SCREEN_BORDER_X * i+1);
                alienPositionsV2F[i].y = SCREEN_BORDER_Y;
            }
        }
        if(i >= 17 && i < 33)
        {
            if(i == 17)
            {
                alienPositionsV2F[i].x = SCREEN_BORDER_X;
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*2;
            }
            if(i != 17)
            {
                alienPositionsV2F[i].x = (SCREEN_BORDER_X * (i-16));
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*2;
            }
        }
        if(i >= 33 && i < 49)
        {
            if(i == 33)
            {
                alienPositionsV2F[i].x = SCREEN_BORDER_X;
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*3;
            }
            if(i != 33)
            {
                alienPositionsV2F[i].x = (SCREEN_BORDER_X * (i-32));
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*3;
            }
        }
        if(i >= 49 && i < 65)
        {
            if(i == 49)
            {
                alienPositionsV2F[i].x = SCREEN_BORDER_X;
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*4;
            }
            if(i != 49)
            {
                alienPositionsV2F[i].x = (SCREEN_BORDER_X * (i-48));
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*4;
            }
        }
        if(i >= 65 && i < 81)
        {
            if(i == 64)
            {
                alienPositionsV2F[i].x = SCREEN_BORDER_X;
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*5;
            }
            if(i != 64)
            {
                alienPositionsV2F[i].x = (SCREEN_BORDER_X * (i-64));
                alienPositionsV2F[i].y = SCREEN_BORDER_Y*5;
            }
        }
    }
    
    for(int i = 0; i <= 80; i++)
    {
        alienPositionsV2F[i].x -= 40;
        alienPositionsV2F[i].y -= 30; 
    }
}

void game::createWindow()
{
    Window.createGameWindow(gameWindow);
    Window.loadTextures();
    Window.createSprites();
    
    fireballPositionV2F.x = -100;       // setting up the fireball default position until it is used
    fireballPositionV2F.x = -100;
}

void game::moveObjects(sf::Keyboard::Key pressedKey)
{   
    if(pressedKey == sf::Keyboard::Key::Left && playerPositionV2F.x > 50)
    {
        playerPositionV2F.x -= 6;
    }
    
    if(pressedKey == sf::Keyboard::Key::Right && playerPositionV2F.x < 1870)
    {
        playerPositionV2F.x += 6;
    }

    if(fireballActive == true)
    {
        fireballPositionV2F.y -=fireballSpeed;
    }    
    moveAliens();
}

void game::moveAliens()
{
    /* moves tha aliens from left to right */
    if(alienPositionsV2F[16].x <= (alienPositionX+309) && alienState == 1)
    {
        for(int i = 0; i <= 80; i++)
        {
            alienPositionsV2F[i].x += alienSpeed;
        }
        if(alienPositionsV2F[16].x >= (alienPositionX+309))
        {
            alienState = 2;
            alienPositionX = alienPositionsV2F[16].x;
        }
    }

    /* moves the aliens on the left side downwards */
    if(alienPositionsV2F[16].y <= (alienPositionY+30) && alienState == 2)
    {
        for(int i = 0; i <= 80; i++)
        {
            alienPositionsV2F[i].y += alienSpeed;
        }
        if(alienPositionsV2F[16].y >= (alienPositionY+30))
        {
            alienPositionY = alienPositionsV2F[16].y;
            alienState = 3;
        }
    }

    /* moves tha aliens from right to left */
    if(alienPositionsV2F[16].x >= (alienPositionX-309) && alienState == 3)
    {
        for(int i = 0; i <= 80; i++)
        {
            alienPositionsV2F[i].x -= alienSpeed;
        }
        if(alienPositionsV2F[16].x <= (alienPositionX-309))
        {
            alienState = 4;
            alienPositionX = alienPositionsV2F[16].x;
        }
    } 

    /* moves the aliens on the right side downwards */
    if(alienPositionsV2F[16].y <= (alienPositionY+30) && alienState == 4)
    {
        for(int i = 0; i <= 80; i++)
        {
            alienPositionsV2F[i].y += alienSpeed;
        }
        if(alienPositionsV2F[16].y >= (alienPositionY+30))
        {
            alienPositionY = alienPositionsV2F[16].y;
            alienState = 1;
        }
    }
}

void game::createFireball(sf::Keyboard::Key pressedKey)
{
    if(!fireballActive && pressedKey == sf::Keyboard::Key::Space)
    {
        fireballPositionV2F.x = playerPositionV2F.x;
        fireballPositionV2F.y = playerPositionV2F.y-30;
        fireballActive = true;
    }
}

void game::detectCollision()
{
    for(int i = 0; i <= 80; i++)
    {
        if(!deactivatedAlienSprites[i])
        {
            if(std::abs(alienPositionsV2F[i].y - fireballPositionV2F.y) < 20 && std::abs(alienPositionsV2F[i].x - fireballPositionV2F.x) < 50)
            {
                deactivatedAlienSprites[i] = true;
                fireballPositionV2F.x =  1000000;           // move the sprite away after a hit
                fireballPositionV2F.y = -1000000;           // move the sprite away after a hit
                alienSpeed += 0.04;
                fireballActive = false;
            }
        }
    }
    
    if(fireballPositionV2F.y < -100)        // if the fireball hits nothing and goes out of the screen
    {
        fireballActive = false;
    }
}

void game::run()
{
    this->createWindow();
    while(gameWindow.isOpen())
    {
        gameWindow.clear(sf::Color::Black);
        while(gameWindow.pollEvent(eventHandler))
        {
            if(eventHandler.type == sf::Event::Closed)
                gameWindow.close();
        }
/* -------------------------- Write draw-code here! ---------------------------- */
        
        createFireball(Inputs.getPressedKey());
        moveObjects(Inputs.getPressedKey());
        detectCollision();
        Window.drawFrame(gameWindow, deactivatedAlienSprites);
        Window.setNewSpritePositions(playerPositionV2F, fireballPositionV2F, alienPositionsV2F);

/* ----------------------------------------------------------------------------- */
        gameWindow.display();
    }
}