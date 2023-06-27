#include "display.hpp"

void fill_screen(Food food, Body snake_body, char game_screen[HEIGHT+2][WIDTH+2]){

    for(int i=0; i<=HEIGHT+1; i++){
        for(int j=0; j <=WIDTH+1; j++){
            game_screen[i][j]=' ';
        }
    }


    
    game_screen[food[0]][food[1]] = FOOD;

    for(int i = 0; i<snake_body[0].size(); i++){
        game_screen[snake_body[0][i]][snake_body[1][i]] = SNAKE_BODY;
    }

    for(int i = 0; i < HEIGHT+2; i++){
        game_screen[i][0]= VERT_WALL;
        game_screen[i][WIDTH+1] = VERT_WALL;
    }

    for(int i = 0; i<WIDTH+2; i++){
        game_screen[0][i] = HORIZ_WALL;
        game_screen[HEIGHT+1][i] = HORIZ_WALL;
    }

}

void display_screen(Food food, Body snake_body){
    char game_screen[HEIGHT+2][WIDTH+2];
    fill_screen(food, snake_body, game_screen);

    for (int i = 0; i < HEIGHT+2; i++) {
        for (int j = 0; j < WIDTH+2; j++) {
            std::cout << game_screen[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void display_screen(Food food, Snake snake){
    Body snake_body = snake.get_body();
    display_screen(food, snake_body);
}