#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(32);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int radius = 300;
    ofColor color;

    ofPushStyle();
    color.setHsb(0, 100, 100);
    //color.a = sin(ofGetElapsedTimef()*0.5) * 255;
    ofSetColor(color);
    ofDrawCircle(ofGetWidth()/2 - radius/2, ofGetHeight()/2, radius);
    ofPopStyle();

    ofPushStyle();
    color.setHsb(180, 100, 100);
    //color.a = cos(ofGetElapsedTimef()*0.5) * 255;
    ofSetColor(color);
    ofDrawCircle(ofGetWidth()/2 + radius/2, ofGetHeight()/2, radius);
    ofPopStyle();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
