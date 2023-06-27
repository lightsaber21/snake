#include "game.hpp"

Game::Game(){
    food = get_food(snake);
}

bool Game::has_food(){
    const Body snake_body = snake.get_body();
    int head_y = snake_body[0][0];
    int head_x = snake_body[1][0];

    if(head_y == food[0] && head_x == food[1]){
        return true;
    }

    return false;
}

void Game::run(){
    while(!snake.has_collision()){
        display_screen(food, snake);
        char key_input;
        std::cin >> key_input;
        snake.set_dir(key_input);
        if(has_food()){
            snake.increase_length();
            food = get_food(snake);
        }
        snake.move();
    }
}