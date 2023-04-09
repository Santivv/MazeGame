//
//  power.cpp
//  practica1
//
//  Created by Carlos Escribano and Santi Vicente on 22/3/23.
//

#include "power.hpp"

power::power(){
    cout << "Constructor de GameObject 1" << endl;
    position.x = 0;
    position.y = 0;
}

/*power::~power(){
    
}*/

power::power(int x, int y, int id){
    cout << "Constructor de GameObject 2" << endl;
    position.x = x;
    position.y = y;
    this->id = id;
}

void power::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(position.x, position.y, width, height);
    ofSetRectMode(OF_RECTMODE_CORNER);
}

coords power::getPosition(){
    return position;
}

int power::getID(){
    return id;
}
