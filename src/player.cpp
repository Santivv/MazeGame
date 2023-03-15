//
//  player.cpp
//  practica1
//
//  Created by Santi Vicente on 11/3/23.
//

#include "player.hpp"

player::player(){
    cout << "Contructor de GameObject" << endl;
    position.x = 20;
    position.y = 20;
}

player::~player(){
    cout << "Destructor de GameObject" << endl;
}

player::player(int x, int y){
    cout << "Contructor de GameObject" << endl;
    position.x = x;
    position.y = y;
}

void player::update(){
    position.y += 1;
}

void player::draw(){
    ofDrawCircle(position.x, position.y, 10);
}

void player::move(char key){
    //cout << key << endl;
    switch(key){
        case 'w':
        case 'i':
            position.y = position.y-3;
            break;
        case 'a':
        case 'j':
            position.x = position.x-3;
            break;
        case 's':
        case 'k':
            position.y = position.y+3;
            break;
        case 'd':
        case 'l':
            position.x = position.x+3;
            break;
    }
}
