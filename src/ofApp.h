#pragma once

#include "ofMain.h"
#include "player.hpp"
#include "power.hpp"
#include "coords.h"

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
    void exit();
    
    void raffleKeys();
    void standardKeys();
    bool checkWhite(float x, float y);
    void choosePowerUp(player* owner, player* enemy, int id);
    
    States state;
    
    int p1x = 25, p1y = 933, p2x = 974, p2y = 70;
    
    ofImage img;
    player p1 = player(p1x, p1y, 1);
    player p2 = player(p2x, p2y, 2);
    vector<power> r;
    
    unsigned long startTime; // Tiempo en milisegundos desde que se inició el cronómetro
    unsigned long elapsedTime; // Tiempo transcurrido desde que se inició el cronómetro
    
    vector<char> keys_player1 = {'w', 'a', 's', 'd'};
    vector<char> keys_player2 = {'i', 'j', 'k', 'l'};
    
    int winner;
    int rotate = 0;
    bool control = false;
    
    ofSoundPlayer soundPlayer;

};
