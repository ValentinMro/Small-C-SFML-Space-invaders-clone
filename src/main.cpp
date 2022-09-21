#include <memory>
#include "game.hpp"

int main()
{
    std::unique_ptr<game> Game (new game());
    Game->run();
}