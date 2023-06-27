//File containing code for the body of the snake
#include "constants.hpp"
#include <vector>

#ifndef SNAKE
#define SNAKE
class Snake {
    private:
    Body body_coords;
    direction curr_dir;

    public:
    Snake();
    bool has_collision();
    void increase_length();
    Body get_body() const;
    void move();
    void set_dir(direction dir);
    void set_dir(char key);
};
#endif