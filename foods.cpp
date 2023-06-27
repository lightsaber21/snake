#include "foods.hpp"
#include <iostream>

int ind2rowmaj(int y_coord, int x_coord){
    return y_coord*(WIDTH+2)+x_coord;
}

std::vector<int> rowmaj2ind(int indice){
    int y_coord = static_cast<int>(indice/(WIDTH+2));
    int x_coord = indice%(WIDTH+2);

    std::vector<int> coords;
    coords.push_back(y_coord);
    coords.push_back(x_coord);
    return coords;
}

Food get_food(const Body &snake_body){

    //Randomly sets the seed to be used
    srand(time(NULL));
    
    //Using row major format it finds the indices in the display screen that contain a snake
    std::unordered_set<int> snake_indices;

    
    for(int i=0; i<snake_body[0].size(); i++){
        int y_coord = snake_body[0][i];
        int x_coord = snake_body[1][i];
        snake_indices.insert(ind2rowmaj(y_coord, x_coord));
    }

    //Using row major format finds all the indices in the display screen that are clear
    std::vector<int> clear_indices;

    for(int i=1; i<=HEIGHT; i++){
        for(int j=1; j<=WIDTH; j++){

            int test_indice = ind2rowmaj(i, j);

            //Test if given indices in unordered_set containing snake body
            //Assigns to clear indices if not found
            if(snake_indices.find(test_indice)== snake_indices.end()){
                clear_indices.push_back(test_indice);
            }
        }
    }

    //Finds random indice in vectors containing clear value(s)
    int rand_ind = rand()%clear_indices.size();
    
    //Finds selected random index from vector of clear values
    int return_ind = clear_indices[rand_ind];

    return rowmaj2ind(return_ind);
}

Food get_food(const Snake snake){
    const Body snake_body = snake.get_body();
    return get_food(snake_body);
}
