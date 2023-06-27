#ifndef CONSTANTS
#define CONSTANTS

#define HEIGHT 30
#define WIDTH 40
#define FOOD '#'
#define HORIZ_WALL '%'
#define VERT_WALL '%'
#define SNAKE_BODY '*'

#include <vector>

typedef std::vector<int> Food;
typedef std::vector<std::vector<int>> Body;


enum direction {NONE, UP, DOWN, RIGHT, LEFT};
#endif