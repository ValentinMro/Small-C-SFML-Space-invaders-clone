#include "playerInputs.hpp"
#include <iostream>

sf::Keyboard::Key playerInputs::getPressedKey()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return sf::Keyboard::Left;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return sf::Keyboard::Key::Right;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        return sf::Keyboard::Key::Space;
    }

    return sf::Keyboard::Key::Unknown;
}