#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    radius = 200;
    ofSetBackgroundColor(ofFloatColor::black);
    yoff = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    line.clear();
    xoff = 0;
    // What if you increment the angle by 1.1 instead of 0.1? Why is this happening?
    for(float angle = 0; angle < TWO_PI; angle+= 0.1 ){

        // A circle
        // float x = offset.x + radius * cos(angle);
        // float y = offset.y + radius * sin(angle);

        // intro to random
        //float newRadius = radius + ofRandom(-5, 5);

        // A classic sin wave
        // float newRadius = radius + ofMap(sin(angle * 10), -1, 1, -25 , 25);
        // float newRadius = radius + ofMap(sin(angle * 10 + ofGetFrameNum()*0.1), -1, 1, -25 , 25);

        // intro to noise
        // first with time
        //float time = ofGetElapsedTimef();
        //float newRadius = radius + ofMap(ofNoise(time), 0, 1, -25, 25);

        float newRadius = radius + ofMap(ofNoise(xoff+yoff), 0, 1, -25, 25);

        float x = offset.x + newRadius * cos(angle);
        float y = offset.y + newRadius * sin(angle);
        line.lineTo(x,y);

        // Tesselation
        tessellation = line.getTessellation();

        xoff += 0.15;
    }
    yoff += 0.05;
    line.close();
    line.setFilled(true);
    line.setFillColor(ofFloatColor::red);
    line.setStrokeColor(ofFloatColor::white);
    line.setStrokeWidth(3.0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    line.draw();
    ofPushStyle();
    ofSetColor(ofFloatColor::blue);
    tessellation.drawWireframe();
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
