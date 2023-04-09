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
    if ((elapsedTime/1000)%10 == 0){
        raffleKeys();
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
                choosePowerUp(p1, p2, r[i].getID());
                r.erase(r.begin()+i);
            } else {
                choosePowerUp(p1, p2, r[i].getID());
                r.clear();
            }
        } else if (p2.checkPower(posPower)){
            if (r.size() > 1){
                choosePowerUp(p2, p1, r[i].getID());
                r.erase(r.begin()+i);
            } else {
                choosePowerUp(p2, p1, r[i].getID());
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
            /*ofTranslate(img.getWidth()*0.7/2, img.getHeight()*0.7/2);
            ofRotateDeg(90);
            ofTranslate(-img.getWidth()*0.7/2, -img.getHeight()*0.7/2);*/
            ofScale(0.7, 0.7);      //0.8 queda justo en la ventana
            
            img.draw(0, 0);
            
            ofSetColor(ofColor::green);
            for(int i=0;i<r.size();i++){
                r[i].draw();
            }
            
            ofSetColor(ofColor::blue);
            p1.draw();

            ofSetColor(ofColor::red);
            p2.draw();
        
        ofPopMatrix();
        
        ofSetColor(ofColor::black);
        ofDrawBitmapString(ofToString(seconds), ofGetWidth()/2-10, ofGetHeight()-20);
        
        if (seconds%10 == 0){
            ofDrawBitmapString("Cambio de direccion", ofGetWidth()/2+10, ofGetHeight()-20);
        }
    } else if(state == finish){
        ofBackground(255);
        ofDrawBitmapString("Player " + ofToString(winner) + " wins in " + ofToString(seconds) + " seconds", ofGetWidth()/2-50, ofGetHeight()/2-5);
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
    // Obtener un generador de números aleatorios
    std::random_device rd;
    std::mt19937 g(rd());
    
    // Barajar los elementos de keys
    std::shuffle(keys_player1.begin(), keys_player1.end(), g);
    std::shuffle(keys_player2.begin(), keys_player2.end(), g);
}

bool ofApp::checkWhite(float x, float y){
    ofColor col;
    col = img.getColor(x, y);
    
    if (col == ofColor::white){
        return true;
    }
    return false;
}

void ofApp::choosePowerUp(player owner, player enemy, int id){
    switch(id){
        case 0:
            cout << "Putada 1" << endl;
            break;
        case 1:
            cout << "Putada 2" << endl;
            break;
        case 2:
            cout << "Putada 3" << endl;
            break;
    }
}

/*for (int i = 0; i < img.getHeight(); i++){
 for (int j = 0; j < img.getWidth(); j++){
 ofColor col = img.getColor(j, i);
 
 col.r = round(((double)col.r)/ 255) * 255;
 col.g = round(((double)col.g)/ 255) * 255;
 col.b = round(((double)col.b)/ 255) * 255;
 
 
 img.setColor(j, i, col);
 }
 }
 
 ofColor col;
 col.r = 255;
 col.g = 0;
 col.b = 0;
 img.setColor(200, 200, col);
 img.update();*/

/*ofScale(0.7, 0.7);
ofSetColor(0);
for(auto path: img.getPaths()){
    cout << path.isFilled() << endl;
    path.draw();
}*/
