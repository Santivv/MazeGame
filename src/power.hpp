//
//  power.hpp
//  practica1
//
//  Created by Carlos Escribano and Santi Vicente on 22/3/23.
//

#ifndef power_hpp
#define power_hpp

#include <stdio.h>
#include "ofMain.h"
#include "coords.h"

class power{
protected:
    coords position;
    int id;
    
public:
    
    power();
    ~power();
    power(int x, int y, int id);
    
    virtual void draw();
    virtual coords getPosition();
    int getID();
    
    int width = 15;
    int height = 15;
    
};

#endif /* power_hpp */
