#include "snake.hpp"

Snake::Snake(){
    curr_dir = NONE;
    body_coords.push_back(std::vector<int>());
    body_coords.push_back(std::vector<int>());
    body_coords[0].push_back(HEIGHT/2);
    body_coords[1].push_back(WIDTH/2);
}

bool Snake::has_collision(){
    if(body_coords[0][0] == 0 || body_coords[0][0] == HEIGHT+1){
        return true;
    }

    if(body_coords[1][0] == 0 || body_coords[1][0] == WIDTH+1){
        return true;
    }

    int head_y = body_coords[0][0];
    int head_x = body_coords[1][0];

    for(int i = 1; i < body_coords[0].size(); i++){
        if((head_y == body_coords[0][i]) && (head_x == body_coords[1][i])){
            return true;
        }
    }

    return false;
}

void Snake::increase_length(){

    if(body_coords[0].size()<=1){
    
        switch (curr_dir)
        {
        case UP: 
            body_coords[0].push_back(body_coords[0][0]+1);
            body_coords[1].push_back(body_coords[1][0]);
            break;
        case DOWN:
            body_coords[0].push_back(body_coords[0][0]-1);
            body_coords[1].push_back(body_coords[1][0]);
            break;
        case LEFT:
            body_coords[0].push_back(body_coords[0][0]);
            body_coords[1].push_back(body_coords[1][0]+1);
            break;
        case RIGHT:
            body_coords[0].push_back(body_coords[0][0]);
            body_coords[1].push_back(body_coords[1][0]-1);
            break;
        default:
            break;
        }
    } 
    
    else{
        int last_index = body_coords[0].size()-1;
        int y_delta = body_coords[0][last_index] - body_coords[0][last_index-1];
        int x_delta = body_coords[1][last_index] - body_coords[1][last_index-1];
        body_coords[0].push_back(body_coords[0][last_index] + y_delta);
        body_coords[1].push_back(body_coords[1][last_index] + x_delta);
    }
}

Body Snake::get_body() const{
    return body_coords;
}

void Snake::set_dir(direction dir){
    curr_dir = dir;
}

void Snake::set_dir(char key){

    switch(key){
        case 'w':
            set_dir(UP);
            break;
        case 'a':
            set_dir(LEFT);
            break;
        case 'd':
            set_dir(RIGHT);
            break;
        case 's':
            set_dir(DOWN);
            break;
    }
}

void Snake::move(){

    int change_y = 0;
    int change_x = 0;
    
    switch(curr_dir)
    {
        case UP:
        change_y = -1; 
        break;
        case DOWN:
        change_y = 1;
        break;
        case LEFT:
        change_x = -1; 
        break;
        case RIGHT:
        change_x = 1;
        break;
    }

    int head_y = body_coords[0][0] + change_y;
    int head_x = body_coords[1][0] + change_x;
    body_coords[0].insert(body_coords[0].begin(), head_y);
    body_coords[1].insert(body_coords[1].begin(), head_x);

    body_coords[0].pop_back();
    body_coords[1].pop_back();
}