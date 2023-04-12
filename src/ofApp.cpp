#include "ofApp.h"

#include <algorithm>
#include <vector>
#include <random>

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    system("cd /Users/santi/Documents/Master/GC/of_v0.11.2_osx_release/apps/myApps/MazeGame/bin/data ; ./mazegen ; qlmanage -t -s 1000 -o . maze.svg ");
    img.load("maze.svg.png");
    
    startTime = 0;
    elapsedTime = 0;
    
    float rx, ry;
    for(int i=0;i<3;i++){
        do{
            rx = ofRandom(65, img.getWidth()-65);
            ry = ofRandom(65, img.getWidth()-65);
        } while(!checkWhite(rx, ry));
        
        r.push_back(power(rx, ry, i));
    }
    
    state = playing;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (state == playing){
        elapsedTime = ofGetElapsedTimeMillis() - startTime;
    }
    if (elapsedTime%15000 <= 50){
        if (ofRandom(2) > 1){
            raffleKeys();
        } else {
            rotate++;
            standardKeys();
        }
    }
    
    if (ofGetKeyPressed('w')) {
        p1.move(keys_player1[0]);
    }
    if (ofGetKeyPressed('a')) {
        p1.move(keys_player1[1]);
    }
    if (ofGetKeyPressed('s')) {
        p1.move(keys_player1[2]);
    }
    if (ofGetKeyPressed('d')) {
        p1.move(keys_player1[3]);
    }
    
    if (ofGetKeyPressed('i')) {
        p2.move(keys_player2[0]);
    }
    if (ofGetKeyPressed('j')) {
        p2.move(keys_player2[1]);
    }
    if (ofGetKeyPressed('k')) {
        p2.move(keys_player2[2]);
    }
    if (ofGetKeyPressed('l')) {
        p2.move(keys_player2[3]);
    }
    
    if (ofGetKeyPressed(' ') && state == finish) {
        system("cd /Users/santi/Documents/Master/GC/of_v0.11.2_osx_release/apps/myApps/MazeGame/bin/data ; ./mazegen ; qlmanage -t -s 1000 -o . maze.svg ");
        img.load("maze.svg.png");
        
        p1.returnToStart();
        p1.setForward(1.5);
        p2.returnToStart();
        p2.setForward(1.5);
        
        rotate = 0;
        startTime = ofGetElapsedTimeMillis();
        standardKeys();
        
        r.clear();
        float rx, ry;
        for(int i=0;i<3;i++){
            do{
                rx = ofRandom(65, img.getWidth()-65);
                ry = ofRandom(65, img.getWidth()-65);
            } while(!checkWhite(rx, ry));
            
            r.push_back(power(rx, ry, i));
        }
        
        state = playing;
    }
    
    if (p1.checkGoal()){
        winner = p1.getID();
        state = finish;
    } else if (p2.checkGoal()){
        winner = p2.getID();
        state = finish;
    }
    
    coords posPower;
    for(int i=0;i<r.size();i++){
        posPower = r[i].getPosition();
        if (p1.checkPower(posPower)){
            if (r.size() > 1){
                choosePowerUp(&p1, &p2, r[i].getID());
                r.erase(r.begin()+i);
            } else {
                choosePowerUp(&p1, &p2, r[i].getID());
                r.clear();
            }
        } else if (p2.checkPower(posPower)){
            if (r.size() > 1){
                choosePowerUp(&p2, &p1, r[i].getID());
                r.erase(r.begin()+i);
            } else {
                choosePowerUp(&p2, &p1, r[i].getID());
                r.clear();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int seconds = (int)elapsedTime/1000;
    
    if (state == playing){
        ofPushMatrix();
        
            ofSetColor(ofColor::white);
            ofTranslate((ofGetWidth()/2)-(img.getWidth()*0.7/2), (ofGetHeight()/2)-(img.getHeight()*0.7/2));
            for(int i=0;i<rotate;i++){
                ofTranslate(img.getWidth()*0.7/2, img.getHeight()*0.7/2);
                ofRotateDeg(90);
                ofTranslate(-img.getWidth()*0.7/2, -img.getHeight()*0.7/2);
            }
            ofScale(0.7, 0.7);
            
            img.draw(0, 0);
            
            ofSetColor(ofColor::green);
            for(int i=0;i<r.size();i++){
                r[i].draw();
            }
        
            ofSetColor(ofColor::blue);
            ofDrawRectangle(p2x-20, p2y-20, 40, 40);
        
            ofSetColor(ofColor::red);
            ofDrawRectangle(p1x-20, p1y-20, 40, 40);
            
            ofSetColor(ofColor::blue);
            p1.draw();

            ofSetColor(ofColor::red);
            p2.draw();
        
        ofPopMatrix();
        
        ofSetColor(ofColor::black);
        ofDrawBitmapString(ofToString(seconds), ofGetWidth()/2-10, ofGetHeight()-20);
        
        if (seconds%15 == 0){
            if (rotate){
                ofDrawBitmapString("Rotación del laberinto", ofGetWidth()/2+10, ofGetHeight()-20);
            } else {
                ofDrawBitmapString("Cambio de controles", ofGetWidth()/2+10, ofGetHeight()-20);
            }
        }
    } else if(state == finish){
        ofBackground(255);
        ofDrawBitmapString("Player " + ofToString(winner) + " wins in " + ofToString(seconds) + " seconds", ofGetWidth()/2-100, ofGetHeight()/2-5);
        ofDrawBitmapString("Press SPACE to restart", ofGetWidth()/2-100, ofGetHeight()/2+15);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

void ofApp::raffleKeys(){
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(keys_player1.begin(), keys_player1.end(), g);
    std::shuffle(keys_player2.begin(), keys_player2.end(), g);
}

void ofApp::standardKeys(){
    keys_player1 = {'w', 'a', 's', 'd'};
    keys_player2 = {'i', 'j', 'k', 'l'};
}

bool ofApp::checkWhite(float x, float y){
    ofColor col[5];
    
    col[0] = img.getColor(x, y);
    col[1] = img.getColor(x+15, y);
    col[2] = img.getColor(x, y+15);
    col[3] = img.getColor(x+15, y+15);
    col[4] = img.getColor(x+7.5, y+7.5);
    if (col[0] == ofColor::white && col[1] == ofColor::white && col[2] == ofColor::white && col[03] == ofColor::white && col[4] == ofColor::white){
        return true;
    }
    
    return false;
}

void ofApp::choosePowerUp(player* owner, player* enemy, int id){
    switch(id){
        case 0:
            owner->setForward(2.5);
            break;
        case 1:
            enemy->setForward(1);
            break;
        case 2:
            enemy->returnToStart();
            break;
    }
}
