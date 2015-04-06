#pragma once

#include "ofMain.h"
#include "ofxGrayCode.h"

class ofApp : public ofBaseApp {
    int encodedX;
    int encodedY;
public:
    ofApp()
    : encodedX(0)
    , encodedY(0)
    {};
    
    void draw() {
        ofBackground(ofColor::black);
        float blockSize = 102.4f;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if((encodedX & (1 << i)) && (encodedY & (1 << j))) {
                    ofSetColor(ofColor::white);
                } else if((encodedX & (1 << i)) || (encodedY & (1 << j))) {
                    ofSetColor(ofColor::gray);
                } else {
                    ofSetColor(ofColor::black);
                }
                ofRect(i * blockSize, j * blockSize, blockSize, blockSize);
            }
        }
        
        ofTranslate(512.0f, 512.0f);
        ofSetColor(ofColor::green);
        ofDrawBitmapString(ofVAArgsToString("(mx, my) = %04d, %04d", ofxGrayCode::decode(encodedX), ofxGrayCode::decode(encodedY)), ofPoint(-100, -25));
        ofDrawBitmapString(ofVAArgsToString("(ex, ey) = %04d, %04d", encodedX, encodedY), ofPoint(-100, 25));
        
    }
    
    void mouseMoved(int x, int y) {
        encodedX = ofxGrayCode::encode(ofClamp(x, 0, 1024));
        encodedY = ofxGrayCode::encode(ofClamp(y, 0, 1024));
    }
};
