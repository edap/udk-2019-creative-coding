#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    reset();
}

//NEW
void ofApp::reset(){
    points.clear();
    for(int i=0; i<nParticles; i++){
        Snowflake s;
        s.position  = glm::vec2(ofRandom(ofGetWidth()),
                                ofRandom(ofGetHeight()));
        ofColor col;
        col.setHsb(ofRandom(0, 150), 255, 255);
        s.color = col;
        s.radius = ofRandom(10, 20);
        s.drag = ofRandom(0.97, 0.99);
        //the unique val allows us to set properties slightly differently for each particle
        s.uniqueVal = ofRandom(-10000, 10000);

        points.push_back(s);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto & s:points){
        s.update(mode);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(80), ofColor(0));
    for(auto s:points){
        s.draw(drawTrail);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == '1'){
        reset();
        mode = PARTICLE_MODE_ATTRACT;
    }else if( key == '2'){
        reset();
        mode = PARTICLE_MODE_FALL;
    }else if( key == '3'){
        reset();
        mode = PARTICLE_MODE_REPEL;
    }else if('t'){
        drawTrail = !drawTrail;
    }

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
