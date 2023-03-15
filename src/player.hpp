//
//  player.hpp
//  practica1
//
//  Created by Santi Vicente on 11/3/23.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofMain.h"

struct coords{
    float x, y;
};

class player{
protected:
    coords position;
    
public:
    
    player();
    ~player();
    player(int x, int y);
    
    virtual void update();
    virtual void draw();
    virtual void move(char key);
    
};

#endif /* player_hpp */
