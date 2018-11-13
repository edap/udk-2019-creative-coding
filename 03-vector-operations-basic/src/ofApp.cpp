#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(200,100,10), ofColor(10,200,10));
    glm::vec2 mouse = glm::vec2(mouseX, mouseY);

    ofPushStyle();
    ofSetColor(ofFloatColor::red);
    ofSetLineWidth(20);

    // Direction and normalization
    auto dir = glm::normalize(mouse-origin);


    // addiction
    // ofDrawLine(origin, origin+dir);

    // scalar multiplication
    //ofDrawLine(origin, origin+dir*30);

    // subtraction
    ofDrawLine(origin, origin-dir*30);

    ofPopStyle();

    // magnitude. The magnitude is the length of a vector
//    ofPushStyle();
//    ofSetColor(ofFloatColor::blueViolet);
//    ofSetLineWidth(20);
//    ofDrawLine(0,0,glm::distance(mouse, origin),0);
//    ofPopStyle();
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
