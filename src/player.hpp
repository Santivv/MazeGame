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
    int id;
    
public:
    
    player();
    //~player();
    player(int x, int y, int id);
    
    virtual void update();
    virtual void draw();
    virtual void setPosition(int x, int y);
    virtual int getID();
    virtual void move(char key);
    virtual bool checkPosition(int move);
    virtual bool checkGoal();
    virtual bool checkPower(coords posPower);
    
    ofImage img;
    int radius = 15;
    float forward = 1.5;
    
};

#endif /* player_hpp */
