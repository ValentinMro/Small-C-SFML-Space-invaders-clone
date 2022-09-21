#ifndef WINDOW_HPP
#define WINDOW_HPP

#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920
#define SCREEN_BORDER_X 100
#define SCREEN_BORDER_Y 70

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class window
{
    public:
    void createGameWindow(sf::RenderWindow& window);
    void drawFrame(sf::RenderWindow& gameWindow, bool deactivatedAliens[]);
    void loadTextures();
    void createSprites();
    void setNewSpritePositions(sf::Vector2f playerPosition, sf::Vector2f fireballPosition, sf::Vector2f alienPositions[]);

    private:
    sf::Texture backgroundTexture, alienTexture, playerTexture, meteorTexture, fireballTexture;
    sf::Sprite backgroundSprite, alienSprites[81], playerSprite, meteorSprite, fireballSprite;
};

#endif // WINDOW_HPP