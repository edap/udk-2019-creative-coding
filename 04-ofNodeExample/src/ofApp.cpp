#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetBackgroundAuto(false);
    //nodeOne.setGlobalPosition(0, 0, 0);
    nodeOne.setGlobalPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    nodeTwo.setParent(nodeOne);
    nodeTwo.setPosition(0, 0, 200);

    nodeThree.setParent(nodeTwo);
    nodeThree.setPosition(0,50,0);

}

//--------------------------------------------------------------
void ofApp::update(){
    nodeOne.panDeg(1);
    nodeTwo.tiltDeg(3);

    line.addVertex(nodeThree.getGlobalPosition());
    if(line.size() > 200){
        line.getVertices().erase(line.getVertices().begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //camera.begin();
    //ofBackground(200, 0, 100);
    // node One
    //nodeOne.draw();

    // node Two
    //nodeTwo.draw();

    // node Three
    //nodeThree.draw();

    ofPushStyle();
    ofSetColor(0, 0, 200);
    line.draw();
    ofPopStyle();

    //camera.end();




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
