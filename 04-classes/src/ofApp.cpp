#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    firstBgColor.setHsb(0,255,255);
    secondBgColor.setHsb(0,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){
    float hueFirst = ofMap(ball.position.x, 0, ofGetWidth(), 0, 125);
    float hueSecond = ofMap(ball.position.y, 0, ofGetHeight(), 126, 255);
    firstBgColor.setHsb(hueFirst,255,255);
    secondBgColor.setHsb(hueSecond,255,255);

    ball.update(target);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(firstBgColor, secondBgColor, OF_GRADIENT_LINEAR);

    ball.draw();
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
    target = glm::vec2(x,y);
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
