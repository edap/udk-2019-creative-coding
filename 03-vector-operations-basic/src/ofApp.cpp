#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    auto mouse = glm::vec2(mouseX, mouseY);

    // line from origin to mouse
    ofSetColor(200, 200, 10);
    ofSetLineWidth(20);
    ofDrawLine(origin, mouse);

    // focus direction
    auto direction = glm::normalize(mouse-origin);
    ofSetColor(255, 0, 10);
    ofSetLineWidth(20);
    //multiplication and addiction
    ofDrawLine(origin, origin+direction*40);

    ofSetColor(0, 255, 10);
    ofSetLineWidth(20);
    //multiplication and subtraction
    ofDrawLine(origin, origin-direction*40);

    // focus on magnitude
    ofSetColor(0, 0, 200);
    ofSetLineWidth(20);
    ofDrawLine(0,0,glm::distance(origin, mouse),0);
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
