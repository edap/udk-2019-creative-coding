#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(32);
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0);

    nBands = 1024;
    mySound.load("beat.wav");
    mySound.setLoop(true);
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBands);

}

//--------------------------------------------------------------
void ofApp::draw(){
    float width = float(ofGetWidth())/ float(nBands) / 2.0f;

    for(int i = 0; i < nBands; i++){
        int b = 255.0f / float(nBands) * i;
        int g = 30;
        int r = 255 - b;

        ofSetColor(r,g,b);
        ofDrawCircle(ofGetWidth()/2 + width * i,
                 ofGetHeight()/2, fft[i] * 800
                 );
        ofDrawCircle(ofGetWidth()/2 - width * i,
                 ofGetHeight()/2, fft[i] * 800
                 );

    }

}
