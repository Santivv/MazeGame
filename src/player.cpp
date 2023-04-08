//
//  player.cpp
//  practica1
//
//  Created by Carlos Escribano and Santi Vicente on 11/3/23.
//

#include "player.hpp"

player::player(){
    cout << "Constructor de GameObject" << endl;
    position.x = 0;
    position.y = 0;
}

player::~player(){
    cout << "Destructor de GameObject" << endl;
}

player::player(int x, int y){
    cout << "Constructor de GameObject" << endl;
    position.x = x;
    position.y = y;
}

void player::update(){
    position.y += 1;
}

void player::draw(){
    ofDrawCircle(position.x, position.y, radius);
}

/*
 0 -> mov arriba
 1 -> mov izquierda
 2 -> mov abajo
 3 -> mov derecha
 */
bool player::checkPosition(int move){
    ofColor col;
    img.load("maze.svg.png");
    
    switch(move){
        case 0:
            col = img.getColor(position.x, position.y-radius-3);
            break;
        case 1:
            col = img.getColor(position.x-radius-3, position.y);
            break;
        case 2:
            col = img.getColor(position.x, position.y+radius+3);
            break;
        case 3:
            col = img.getColor(position.x+radius+3, position.y);
            break;
    }
    
    if (col != ofColor::white){
        return false;
    }
    
    return true;
}

void player::move(char key){
    switch(key){
        case 'w':
        case 'i':
            if (checkPosition(0)){
                position.y = position.y-3;
            }
            break;
        case 'a':
        case 'j':
            if (checkPosition(1)){
                position.x = position.x-3;
            }
            break;
        case 's':
        case 'k':
            if (checkPosition(2)){
                position.y = position.y+3;
            }
            break;
        case 'd':
        case 'l':
            if (checkPosition(3)){
                position.x = position.x+3;
            }
            break;
    }
}
