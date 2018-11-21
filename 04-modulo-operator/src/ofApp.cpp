#include "ofApp.h"

//read this https://en.wikipedia.org/wiki/Modulo_operation

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(yVal.set("divisor y", 2, 1, 10));
    gui.add(lineWidth.set("lineWidth", 2, 1, 10));
    gui.add(padding.set("padding", 5, 2, 20));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    for(int y = 1; y<= ofGetHeight(); y+= padding){
        if(y%yVal == 0){
            ofPushStyle();
            ofSetColor(255);
            ofSetLineWidth(lineWidth);
            ofSetColor(255); // how could you map the color depending on the iteration y?
            ofDrawLine(10, y, ofGetWidth()-10, y);
            ofPopStyle();
        }
    }

    gui.draw();
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
