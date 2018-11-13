#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(41, 50, 73);
    ofSetCircleResolution(50);
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // SET FILL
    ofFill();
    
    // SET TIME INTERVAL
    auto getTime = ofGetElapsedTimef();
    
    // SIN 1
    auto freq = 2.0;
    float interval1 = sin(getTime * freq);
    
    // SIN 2
    auto freq2 = 2.5;
    float interval2 = sin(getTime * freq2);
    
    // SIN 3
    auto freq3 = 3;
    float interval3 = sin(getTime * freq3);
    
    // SIN 4
    auto freq4 = 3.5;
    float interval4 = sin(getTime * freq4);
    
    // SIN 5
    auto freq5 = 4;
    float interval5 = sin(getTime * freq5);
    
    // SIN 6
    auto freq6 = 4.5;
    float interval6 = sin(getTime * freq6);

    
    
    
    // DRAW CIRCLE 1 AND 11
    ofSetColor(65, 75, 102, 90);
    float circleSize1 = ofMap(interval1, -1, 1, 20, 70);
    ofDrawCircle(ofGetWidth()/12, ofGetHeight()/2, circleSize1);
    ofDrawCircle((ofGetWidth()/12)*11, ofGetHeight()/2, circleSize1);
    
    // DRAW CIRCLE 2 AND 10
    ofSetColor(65, 75, 102, 92);
    float circleSize2 = ofMap(interval2, -1, 1, 20, 80);
    ofDrawCircle(ofGetWidth()/12*2, ofGetHeight()/2, circleSize2);
    ofDrawCircle((ofGetWidth()/12)*10, ofGetHeight()/2, circleSize2);
    
    // DRAW CIRCLE 3 AND 9
    ofSetColor(65, 75, 102, 94);
    float circleSize3 = ofMap(interval3, -1, 1, 20, 90);
    ofDrawCircle(ofGetWidth()/12*3, ofGetHeight()/2, circleSize3);
    ofDrawCircle((ofGetWidth()/12)*9, ofGetHeight()/2, circleSize3);
    
    // DRAW CIRCLE 4 AND 8
    ofSetColor(65, 75, 102, 96);
    float circleSize4 = ofMap(interval4, -1, 1, 20, 100);
    ofDrawCircle(ofGetWidth()/12*4, ofGetHeight()/2, circleSize4);
    ofDrawCircle((ofGetWidth()/12)*8, ofGetHeight()/2, circleSize4);
    
    // DRAW CIRCLE 5 AND 7
    ofSetColor(65, 75, 102, 98);
    float circleSize5 = ofMap(interval5, -1, 1, 20, 110);
    ofDrawCircle(ofGetWidth()/12*5, ofGetHeight()/2, circleSize5);
    ofDrawCircle((ofGetWidth()/12)*7, ofGetHeight()/2, circleSize5);
    
    // DRAW CIRCLE 6
    ofSetColor(65, 75, 102, 100);
    float circleSize6 = ofMap(interval6, -1, 1, 20, 120);
    ofDrawCircle(ofGetWidth()/12*6, ofGetHeight()/2, circleSize6);
    
    // DRAW SECOND CIRCLE SERIES
    
    // DRAW CIRCLE 1B AND 11B
    ofSetColor(215, 58, 90, 90);
    float circleSize1B = ofMap(interval6, -1, 1, 10, 40);
    ofDrawCircle(ofGetWidth()/12, ofGetHeight()/2, circleSize1B);
    ofDrawCircle((ofGetWidth()/12)*11, ofGetHeight()/2, circleSize1B);
    
    // DRAW CIRCLE 2B AND 10B
    ofSetColor(215, 58, 90, 92);
    float circleSize2B = ofMap(interval5, -1, 1, 10, 50);
    ofDrawCircle(ofGetWidth()/12*2, ofGetHeight()/2, circleSize2B);
    ofDrawCircle((ofGetWidth()/12)*10, ofGetHeight()/2, circleSize2B);
    
    // DRAW CIRCLE 3B AND 9B
    ofSetColor(215, 58, 90, 94);
    float circleSize3B = ofMap(interval4, -1, 1, 10, 60);
    ofDrawCircle(ofGetWidth()/12*3, ofGetHeight()/2, circleSize3B);
    ofDrawCircle((ofGetWidth()/12)*9, ofGetHeight()/2, circleSize3B);
    
    // DRAW CIRCLE 4B AND 8B
    ofSetColor(215, 58, 90, 96);
    float circleSize4B = ofMap(interval3, -1, 1, 10, 70);
    ofDrawCircle(ofGetWidth()/12*4, ofGetHeight()/2, circleSize4B);
    ofDrawCircle((ofGetWidth()/12)*8, ofGetHeight()/2, circleSize4B);
    
    // DRAW CIRCLE 5B AND 7B
    ofSetColor(215, 58, 90, 98);
    float circleSize5B = ofMap(interval2, -1, 1, 10, 80);
    ofDrawCircle(ofGetWidth()/12*5, ofGetHeight()/2, circleSize5B);
    ofDrawCircle((ofGetWidth()/12)*7, ofGetHeight()/2, circleSize5B);
    
    // DRAW CIRCLE 6B
    ofSetColor(215, 58, 90, 100);
    float circleSize6B = ofMap(interval1, -1, 1, 10, 90);
    ofDrawCircle(ofGetWidth()/12*6, ofGetHeight()/2, circleSize6B);
    
    

    
    
    // SET DELAY
    auto timeDelay = ofGetElapsedTimeMillis();
    auto delay1 = 18300;
    auto delay2 = 26000;
    auto delay3 = 30000;
    
    // SET TRANSPARENCY TIMES
    float recOpacity = ofMap(timeDelay, 17000, 18000, 0, 255);
    float recOpacityStart = ofMap(timeDelay, 8000, 9500, 255, 0);
    
    // DRAW RED RECTANGLE AFTER DELAY
    ofSetColor(41, 50, 73, recOpacity);
    ofDrawRectangle(0, 0,  ofGetWidth(), ofGetHeight());
    
    // DRAW RED RECTANGLE BEFORE START
    ofSetColor(41, 50, 73, recOpacityStart);
    ofDrawRectangle(0, 0,  ofGetWidth(), ofGetHeight());
    
    // SIN 1
    auto freqLoading1 = 2;
    float intervalLoading1 = sin(getTime * freqLoading1);
    
    // SIN 2
    auto freqLoading2 = 2.1;
    float intervalLoading2 = sin(getTime * freqLoading2);
    
    // SIN 3
    auto freqLoading3 = 2.2;
    float intervalLoading3 = sin(getTime * freqLoading3);
    
    
    // SET FADE-OUT LOADING CIRCLES
    float recOpacityLoading = ofMap(timeDelay, 7000, 8000, 255, 0);
    
    // DRAW LOADING CIRCLES
    ofSetColor(215, 58, 90, recOpacityLoading);
    float circleSizeLoading1 = ofMap(intervalLoading1, -1, 1, 15, 20);
    float circleSizeLoading2 = ofMap(intervalLoading2, -1, 1, 15, 20);
    float circleSizeLoading3 = ofMap(intervalLoading3, -1, 1, 15, 20);
    ofDrawCircle((ofGetWidth()/10)*4, ofGetHeight()/2, circleSizeLoading1);
    ofDrawCircle((ofGetWidth()/10)*5, ofGetHeight()/2, circleSizeLoading2);
    ofDrawCircle((ofGetWidth()/10)*6, ofGetHeight()/2, circleSizeLoading3);

    
    
        // SECOND SET OF CIRCLES AFTER DELAY ––––————————————————————
        
        // SET OUTLINE
        ofNoFill();
        
        // MOVE POSITION OF ZERO ZERO (CARTESIAN COORDINATES)
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
        // ROTATE
        auto freqRotation1 = 0.499999;
        float intervalRotation1 = sin(getTime * freqRotation1);
        float rotation1 = ofMap(intervalRotation1, -1, 1, 0, 360);
        
        auto freqRotation2 = 0.499997;
        float intervalRotation2 = sin(getTime * freqRotation2);
        float rotation2 = ofMap(intervalRotation2, -1, 1, 0, 360);
        
        auto freqRotation3 = 0.499996;
        float intervalRotation3 = sin(getTime * freqRotation3);
        float rotation3 = ofMap(intervalRotation3, -1, 1, 0, 360);
        
        auto freqRotation4 = 0.499995;
        float intervalRotation4 = sin(getTime * freqRotation4);
        float rotation4 = ofMap(intervalRotation4, -1, 1, 0, 360);
        
        auto freqRotation5 = 0.499994;
        float intervalRotation5 = sin(getTime * freqRotation5);
        float rotation5 = ofMap(intervalRotation5, -1, 1, 0, 360);
        
        auto freqRotation6 = 0.499993;
        float intervalRotation6 = sin(getTime * freqRotation6);
        float rotation6 = ofMap(intervalRotation6, -1, 1, 0, 360);
        
        auto freqRotation7 = 0.499992;
        float intervalRotation7 = sin(getTime * freqRotation7);
        float rotation7 = ofMap(intervalRotation7, -1, 1, 0, 360);
        
        auto freqRotation8 = 0.499991;
        float intervalRotation8 = sin(getTime * freqRotation8);
        float rotation8 = ofMap(intervalRotation8, -1, 1, 0, 360);
        
        auto freqRotation9 = 0.499990;
        float intervalRotation9 = sin(getTime * freqRotation9);
        float rotation9 = ofMap(intervalRotation9, -1, 1, 0, 360);
        
        
        // SET COLOR
        float circleOpacityRotation = sin(getTime * freqRotation1);
        float circleOpacity = ofMap(circleOpacityRotation, -1, 1, 200, 255);
        float circleOpacity2 = ofMap(circleOpacityRotation, -1, 1, 50, 30);
        ofSetColor(215, 58, 90, circleOpacity);
     
       if(timeDelay > delay1){
        // DRAW CIRCLES
        ofDrawCircle(0, 0, 30);
        ofRotateDeg(rotation1);
        ofDrawCircle(30, 0, 30);
        ofRotateDeg(rotation2);
        ofDrawCircle(60, 0, 30);
        ofRotateDeg(rotation3);
        ofDrawCircle(90, 0, 30);
        ofRotateDeg(rotation4);
        ofDrawCircle(120, 0, 30);
        ofRotateDeg(rotation5);
        ofDrawCircle(150, 0, 30);
        ofRotateDeg(rotation6);
        ofDrawCircle(180, 0, 30);
        ofRotateDeg(rotation7);
        ofDrawCircle(210, 0, 30);
        ofRotateDeg(rotation8);
        ofDrawCircle(240, 0, 30);
        ofDrawCircle(270, 0, 30);
    
    };
    
    if(timeDelay > delay2){
        
        // DRAW CIRCLES WITH FILL
        // SET FILL
        ofFill();
        ofSetColor(215, 58, 90, circleOpacity2);
        ofDrawCircle(0, 0, 10);
        ofRotateDeg(rotation1);
        ofDrawCircle(30, 0, 20);
        ofRotateDeg(rotation2);
        ofDrawCircle(60, 0, 30);
        ofRotateDeg(rotation3);
        ofDrawCircle(90, 0, 40);
        ofRotateDeg(rotation4);
        ofDrawCircle(120, 0, 50);
        ofRotateDeg(rotation5);
        ofDrawCircle(150, 0, 60);
        ofRotateDeg(rotation6);
        ofDrawCircle(180, 0, 70);
        ofRotateDeg(rotation7);
        ofDrawCircle(210, 0, 80);
        ofRotateDeg(rotation8);
        ofDrawCircle(240, 0, 90);
        ofDrawCircle(270, 0, 100);
    };
    
    if(timeDelay > delay3){
        
        // DRAW CIRCLES WITH BLUE FILL
        // SET FILL
        ofFill();
        ofSetColor(65, 75, 102, 100);
        ofDrawCircle(0, 0, 10);
        ofRotateDeg(rotation1);
        ofDrawCircle(30, 0, 10);
        ofRotateDeg(rotation2);
        ofDrawCircle(60, 0, 10);
        ofRotateDeg(rotation3);
        ofDrawCircle(90, 0, 10);
        ofRotateDeg(rotation4);
        ofDrawCircle(120, 0, 10);
        ofRotateDeg(rotation5);
        ofDrawCircle(150, 0, 10);
        ofRotateDeg(rotation6);
        ofDrawCircle(180, 0, 10);
        ofRotateDeg(rotation7);
        ofDrawCircle(210, 0, 10);
        ofRotateDeg(rotation8);
        ofDrawCircle(240, 0, 10);
        ofDrawCircle(270, 0, 10);
    };
    
    
    // RANDOM UNUSED THINGS
    /*
     
     // SET OUTLINE CHANGE
     float circleOutline1 = ofMap(intervalRotation1, 0, 1, 1, 4);
     ofSetLineWidth(circleOutline1);
     
     */
    
    
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
