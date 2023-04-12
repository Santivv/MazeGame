//
//  player.cpp
//  practica1
//
//  Created by Carlos Escribano and Santi Vicente on 11/3/23.
//

#include "player.hpp"

player::player(){
    cout << "Constructor de Player 1" << endl;
    position.x = 0;
    position.y = 0;
}

player::~player(){
    cout << "Destructor de Player" << endl;
}

player::player(int x, int y, int id){
    cout << "Constructor de Player 2" << endl;
    position.x = x;
    position.y = y;
    entrada.x = x;
    entrada.y = y;
    this->id = id;
    forward = 1.5;
}

void player::update(){
    position.y += 1;
}

void player::draw(){
    ofDrawCircle(position.x, position.y, radius);
}

void player::setPosition(int x, int y){
    position.x = x;
    position.y = y;
}

int player::getID(){
    return id;
}

void player::setForward(float dif){
    forward = dif;
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
            col = img.getColor(position.x, position.y-radius-forward);
            break;
        case 1:
            col = img.getColor(position.x-radius-forward, position.y);
            break;
        case 2:
            col = img.getColor(position.x, position.y+radius+forward);
            break;
        case 3:
            col = img.getColor(position.x+radius+forward, position.y);
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
            if (checkPosition(0) && position.y>50){
                position.y = position.y-forward;
            }
            break;
        case 'a':
        case 'j':
            if (checkPosition(1)){
                position.x = position.x-forward;
            }
            break;
        case 's':
        case 'k':
            if (checkPosition(2) && position.y<950){
                position.y = position.y+forward;
            }
            break;
        case 'd':
        case 'l':
            if (checkPosition(3)){
                position.x = position.x+forward;
            }
            break;
    }
}

bool player::checkGoal(){
    switch(id){
        case 1:
            if (position.x > 970){
                return true;
            }
            break;
        case 2:
            if (position.x < 25){
                return true;
            }
            break;
    }
    
    return false;
}

bool player::checkPower(coords posPower){
    if ((position.x >= posPower.x && position.x <= posPower.x+15) && (position.y >= posPower.y && position.y <= posPower.y+15)){
        return true;
    }
    return false;
}

void player::returnToStart(){
    position.x = entrada.x;
    position.y = entrada.y;
}
