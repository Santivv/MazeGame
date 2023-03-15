#pragma once

#include "ofMain.h"
#include "player.hpp"
#include "ofxSVG.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    const char* svgToBMP(std::string svgfilepath, std::uint32_t width, std::uint32_t height, std::uint32_t bgcolor);

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
    
    ofxSVG img;
    player p1, p2;
		
};
