#pragma once

#include "ofMain.h"
#include "player.hpp"

class ofApp : public ofBaseApp{
    
    enum States {
        playing, finish
    };

    public:
        void setup();
        void update();
        void draw();
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    void raffleKeys();
    
    States state;
    
    ofImage img;
    player p1 = player(25, 933, 1);
    player p2 = player(974, 70, 2);
    
    unsigned long startTime; // Tiempo en milisegundos desde que se inició el cronómetro
    unsigned long elapsedTime; // Tiempo transcurrido desde que se inició el cronómetro
    
    vector<char> keys_player1 = {'w', 'a', 's', 'd'};
    vector<char> keys_player2 = {'i', 'j', 'k', 'l'};
    
    int winner;

};
