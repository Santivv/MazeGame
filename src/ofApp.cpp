#include "ofApp.h"
#include <chrono>
#include <thread>
#include <lunasvg/include/lunasvg.h>
#include <stb/stb_image_write.h>


//--------------------------------------------------------------
void ofApp::setup(){
    //using namespace std::chrono;
    //using namespace std::this_thread;
    using namespace lunasvg;
    
    auto document = Document::loadFromFile("laberinto.svg");
    auto bitmap = document->renderToBitmap();

    // do something useful with the bitmap here.
    using namespace Aspose::Words;

    auto doc = MakeObject<Document>();
    auto builder = MakeObject<DocumentBuilder>(doc);

    auto shape = builder->InsertImage(u"Input.svg");
    shape->get_ImageData()->Save(u"Output.png");


    ofBackground(255);
    
    //system("cd /Users/santi/Documents/Master/GC/of_v0.11.2_osx_release/apps/myApps/practica1/bin/data ; ./mazegen");
    //sleep_for(seconds(1));
    //img.load("laberinto.svg");
    img.load(svgToBMP("/Users/santi/Documents/Master/GC/of_v0.11.2_osx_release/apps/myApps/practica1/bin/data", 1000, 1000, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

const char* svgToBMP(std::string svgfilepath, std::uint32_t width, std::uint32_t height, std::uint32_t bgcolor) 
{
    std::string filename = "laberinto.svg";
    auto document = lunasvg::Document::loadFromFile(svgfilepath);
    auto bitmap = document->renderToBitmap(width, height, bgcolor);
    auto basename = filename.substr(filename.find_last_of("/\\") + 1);
    basename.append(".bmp");
    stbi_write_bmp(basename.c_str(), int(bitmap.width()), int(bitmap.height()), 4, bitmap.data());

    return NULL;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofScale(0.5, 0.5);
    ofTranslate((ofGetWidth()/2)-(img.getWidth()*0.5/2), (ofGetHeight()/2)-(img.getHeight()*0.5/2));
    img.draw();
    ofPopMatrix();
    
    ofSetColor(ofColor::red);
    p1.draw();
    
    ofSetColor(ofColor::blue);
    p2.draw();
    
    /*ofScale(0.7, 0.7);
    ofSetColor(0);
    for(auto path: img.getPaths()){
        cout << path.isFilled() << endl;
        path.draw();
    }*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << key << endl;
    if((key == 119) || (key == 97) || (key == 115) || (key == 100)){
        cout << key << endl;
        p1.move(key);
    }
    if((key == 105) || (key == 106) || (key == 107) || (key == 108)){
        cout << key << endl;
        p2.move(key);
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
