#include "constants.hpp"
#include "snake.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_set>

#ifndef FOODS
#define FOODS


int ind2rowmaj(int y_coord, int x_coord);
std::vector<int> rowmaj2ind(int indice); 
Food get_food(const Body &snake_body);
Food get_food(const Snake snake);
#endif