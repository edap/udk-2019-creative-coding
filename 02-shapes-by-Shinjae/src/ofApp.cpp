#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    radius = 100;
    //ofSetBackgroundColor(ofFloatColor::aliceBlue);
    yoff = 0;
    
    ofSetBackgroundAuto(false); //disable automatic background redraw
}


//--------------------------------------------------------------
void ofApp::update(){
    
    line.clear();
    xoff = 0;
    
    
// float newRadius = radius + ofRandom(-60, 60);

    for(float angle = 0; angle < TWO_PI; angle +=0.01){
// float newRadius = radius + ofMap(sin(angle * 30), -1, 1, -40, 40 );
// ofLog() << newRadius;
// float  newRadius = radius + ofRandom(-20, 20);
        
//float newRadius = radius +ofMap(sin(angle * 10 + ofGetFrameNum()*0.1),
                                     //   -1, 1, -25, 25);
        float time = ofGetElapsedTimef();
        
//  float newRadius = radius + ofMap(ofNoise(angle * 10), 0, 1, -1225, 1225);
       
        float newRadius = radius + ofMap(ofNoise(xoff+yoff), 0, 0.9, -355, 1225);

        float x = cos(angle) * newRadius + offset.x;
        float y = sin(angle) * newRadius + offset.y;
        line.lineTo(x,y);
        
        xoff += 0.5;
        
    }
    yoff += 0.05;
    
    line.close();
 // line.setFilled(false);
  
    line.setFillColor(ofFloatColor::pink);
    line.setStrokeColor(ofFloatColor::darkSeaGreen);

    
    
    line.setStrokeWidth(200);
    
    tessellation = line.getTessellation();
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
     line.draw();
    line.setStrokeWidth(3);
    
    
    ofPushStyle();
    ofSetColor(ofFloatColor::pink);
    ofPopStyle();
    

    tessellation.drawWireframe();
    
   
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
