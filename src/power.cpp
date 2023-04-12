//
//  power.cpp
//  practica1
//
//  Created by Carlos Escribano and Santi Vicente on 22/3/23.
//

#include "power.hpp"

power::power(){
    cout << "Constructor de Power 1" << endl;
    position.x = 0;
    position.y = 0;
}

power::~power(){
    cout << "Destructor de Power" << endl;
}

power::power(int x, int y, int id){
    cout << "Constructor de Power 2" << endl;
    position.x = x;
    position.y = y;
    this->id = id;
}

void power::draw(){
    ofDrawRectangle(position.x, position.y, width, height);
}

coords power::getPosition(){
    return position;
}

int power::getID(){
    return id;
}
