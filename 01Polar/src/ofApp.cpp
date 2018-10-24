#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){
    angle += 0.1;
    radius += 1;
    radius = radius + 1;

    if(radius > ofGetHeight()/2){
        radius = 0;
        ofBackground(255);
    }

    if(angle >= TWO_PI){
        angle = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackgroundGradient(ofFloatColor::coral, ofFloatColor::lightGreen);
    // polar space to cartesian. SOHCAHTOA!!!!
    auto x = radius * cos(angle);
    auto y = radius * sin(angle);

    // put the circle in the middle
    auto offset = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    auto dance = glm::vec2(x,y);
    auto finalPos = dance + offset;

    ofPushStyle();

    // COLOR depending on the angle
    float hue = ofMap(angle, 0, TWO_PI, 0, 255);
    auto color = ofColor();
    color.setHsb(hue, 255, 255);

    ofSetColor(color);
    ofDrawCircle(finalPos, 30);
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
