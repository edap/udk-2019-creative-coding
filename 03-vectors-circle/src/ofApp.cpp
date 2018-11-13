#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    firstBgColor.setHsb(0,255,255);
    secondBgColor.setHsb(0,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){
    float hueFirst = ofMap(position.x, 0, ofGetWidth(), 0, 125);
    float hueSecond = ofMap(position.y, 0, ofGetHeight(), 126, 255);
    firstBgColor.setHsb(hueFirst,255,255);
    secondBgColor.setHsb(hueSecond,255,255);

    // move the circle slowly to the target position
    if (glm::distance(position, target) > 0) {
        // in which direction is the ball moving?
        auto direction = glm::normalize(target - position);
        auto velocity = direction; // for now, let's say that the velocity change like the direction.

        // 1)
        //position += velocity;

        // 2) accelleration. The strict definition of acceleration we’re using here is: the rate of change of velocity
        //auto acceleration = glm::vec2(0.5, 1.5);
        //velocity += acceleration;
        //position += velocity;

        // 3) Hey, but the ball goes out of the screen!
        // let's say that the accelleration is just a value that cahnges the speed.
        auto rate = glm::distance(target, position) * 0.01; // what if you change the 0.01 value?
        auto acceleration = direction * rate;
        velocity += acceleration;
        position += velocity;

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(firstBgColor, secondBgColor, OF_GRADIENT_LINEAR);

    ofPushStyle();
    ofSetColor(circleColor);
    ofDrawCircle(position, 10);
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
