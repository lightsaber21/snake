#ifndef DISPLAY
#define DISPLAY
#include "constants.hpp"
#include "snake.hpp"
#include <iostream>
#include <vector>

void fill_screen(Food food, Body snake_body, char game_screen[HEIGHT+2][WIDTH+2]);
void display_screen(Food food, Body snake_body);
void display_screen(Food food, Snake snake);
#endif