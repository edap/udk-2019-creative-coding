#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    auto time = ofGetElapsedTimef();
    auto freq = 0.2;
    float x = sin(time*freq);
    ofLog() << x;
    float y = 400;

    float newX = ofMap(x, -1, 1, 0, ofGetWidth());
    float newX2 = ofMap(x, -1, 1, ofGetWidth(), 0);

    auto firstColor = ofColor(255, 0, 0, 100);
    auto secondColor = ofColor(0, 0, 255, 100);

    ofPushStyle();
    ofSetColor(firstColor);
    ofDrawCircle(newX, y, 100);
    ofPopStyle();

    ofPushStyle();
    ofSetColor(secondColor);
    ofDrawCircle(newX2, y, 100);
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
