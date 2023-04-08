#include "ofApp.h"
#include <chrono>
#include <thread>
#include <stb/stb_image_write.h>

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    system("cd /Users/santi/Documents/Master/GC/of_v0.11.2_osx_release/apps/myApps/MazeGame/bin/data ; ./mazegen ; qlmanage -t -s 1000 -o . maze.svg ");
    img.load("maze.svg.png");
    
    startTime = 0;
    elapsedTime = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
    elapsedTime = ofGetElapsedTimeMillis() - startTime;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofSetColor(ofColor::white);
    ofTranslate((ofGetWidth()/2)-(img.getWidth()*0.7/2), (ofGetHeight()/2)-(img.getHeight()*0.7/2));
    ofScale(0.7, 0.7);      //0.8 queda justo en la ventana
    img.draw(0, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofSetColor(ofColor::blue);
    ofTranslate((ofGetWidth()/2)-(img.getWidth()*0.7/2), (ofGetHeight()/2)-(img.getHeight()*0.7/2));
    ofScale(0.7, 0.7);
    p1.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofSetColor(ofColor::red);
    ofTranslate((ofGetWidth()/2)-(img.getWidth()*0.7/2), (ofGetHeight()/2)-(img.getHeight()*0.7/2));
    ofScale(0.7, 0.7);
    p2.draw();
    ofPopMatrix();
    
    /*for (int i = 0; i < img.getHeight(); i++){
        for (int j = 0; j < img.getWidth(); j++){
            ofColor col = img.getColor(j, i);

            col.r = round(((double)col.r)/ 255) * 255;
            col.g = round(((double)col.g)/ 255) * 255;
            col.b = round(((double)col.b)/ 255) * 255;
            

            img.setColor(j, i, col);
        }
    }*/
    
    ofColor col;
    col.r = 255;
    col.g = 0;
    col.b = 0;
    img.setColor(200, 200, col);
    img.update();
    
    ofDrawBitmapString("Tiempo transcurrido: " + ofToString(elapsedTime), 10, 20);
    
    /*ofScale(0.7, 0.7);
    ofSetColor(0);
    for(auto path: img.getPaths()){
        cout << path.isFilled() << endl;
        path.draw();
    }*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //cout << key << endl;
    if((key == 119) || (key == 97) || (key == 115) || (key == 100)){
        //cout << key << endl;
        p1.move(key);
    }
    if((key == 105) || (key == 106) || (key == 107) || (key == 108)){
        //cout << key << endl;
        p2.move(key);
    }
    
    if (key == ' ') {
        startTime = ofGetElapsedTimeMillis();
    }
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
