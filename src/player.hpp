//
//  player.hpp
//  practica1
//
//  Created by Carlos Escribano and Santi Vicente on 11/3/23.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofMain.h"
#include "coords.h"

class player{
protected:
    coords position;
    coords entrada;
    int id;
    
public:
    
    player();
    //~player();
    player(int x, int y, int id);
    
    virtual void update();
    virtual void draw();
    virtual void setPosition(int x, int y);
    virtual int getID();
    virtual void setForward(float dif);
    virtual void move(char key);
    virtual bool checkPosition(int move);
    virtual bool checkGoal();
    virtual bool checkPower(coords posPower);
    virtual void returnToStart();
    
    ofImage img;
    int radius = 15;
    float forward;
    
};

#endif /* player_hpp */
