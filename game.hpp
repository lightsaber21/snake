#include "constants.hpp"
#include "display.hpp"
#include "foods.hpp"
#include "snake.hpp"
#include <string>
#include <iostream>

#ifndef GAME
#define GAME
class Game{
    Snake snake;
    Food food;

    public:
    Game();
    bool has_food();
    void run();

}; 
#endif