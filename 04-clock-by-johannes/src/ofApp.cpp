#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	isSavingPDF = false;
	
	gui.setup();
	gui.add(stunde.set("stunde", 8, 0, 24));
	gui.add(minute.set("minute", 36, 0, 60));
	gui.add(positionX.set("X sec", 12, 0.0, 50.0));
	gui.add(positionY.set("Y sec", 14, 0.0, 20.0));
	gui.add(positionX2.set("X min", 29.25, 0.0, 50.0));
	gui.add(positionY2.set("Y min", 4.1, 0.0, 20.0));
	gui.add(positionX3.set("X h", 43.5, 0.0, 50.0));
	gui.add(positionY3.set("Y h", 4.3, 0.0, 20.0));
	gui.add(speed.set("SPEED sec", 0.085, 0.00, 1.00));
	gui.add(speed2.set("SPEED min", 0.06, 0.00, 1.00));
	gui.add(speed3.set("SPEED h", 0.03, 0.00, 1.00));
	gui.add(vel.set("vel sec", 7.8, 0, 30.00));
	gui.add(vel2.set("vel min", 4.2, 0.00, 30.00));
	gui.add(vel3.set("vel h",2.25, 0.00, 30.00));
	gui.add(act.set("aktualisierung", 20, 1, 30));
	gui.add(var.set("var 1", 1.725, 0, 3));
	gui.add(var2.set("var 2", 420, -1000, 1000));
	gui.add(var3.set("var 3", 1.065, 0, 3));
	gui.add(var4.set("var 4", 190, -1000, 1000));
	gui.add(var5.set("var 5", 1.275, 0, 3));
	gui.add(var6.set("var 6", 340, -1000, 1000));
	gui.add(frame.set("framerate", 60, 1, 60));
	gui.add(seca.set("sec loop", 11, 1, 61));
	gui.add(mina.set("min loop", 2, 1, 61));
	gui.add(ha.set("h loop", 2, 1, 61));

	secfont.load("HelveticaBlkHollow.ttf", 25);
	minfont.load("HelveticaBlkHollow.ttf", 100);
	hfont.load("HelveticaBlkHollow.ttf", 140);
	
	/*
	gui.setup();
	gui.add(stunde.set("stunde", 8, 0, 24));
	gui.add(minute.set("minute", 36, 0, 60));
	gui.add(positionX.set("X sec", 12, 0.0, 50.0));
	gui.add(positionY.set("Y sec", 14, 0.0, 20.0));
	gui.add(positionX2.set("X min",29.25, 0.0, 50.0));
	gui.add(positionY2.set("Y min",4.1, 0.0, 20.0));
	gui.add(positionX3.set("X h", 41.5, 0.0, 50.0));
	gui.add(positionY3.set("Y h", 5.3, 0.0, 20.0));
	gui.add(speed.set("SPEED sec", 0.055, 0.00, 1.00));
	gui.add(speed2.set("SPEED min", 0.075, 0.00, 1.00));
	gui.add(speed3.set("SPEED h", 0.055, 0.00, 1.00));
	gui.add(vel.set("vel sec",15, 7.8, 30.00));
	gui.add(vel2.set("vel min", 4.95, 0.00, 30.00));
	gui.add(vel3.set("vel h", 3.45, 0.00, 30.00));
	gui.add(act.set("aktualisierung", 30, 1, 30));
	gui.add(var.set("var 1", 1.725, 0, 3));
	gui.add(var2.set("var 2", 710, -1000, 1000));
	gui.add(var3.set("var 3", 1.065, 0, 3));
	gui.add(var4.set("var 4", 80, -1000, 1000)); 
	gui.add(var5.set("var 5", 1.005, 0, 3));
	gui.add(var6.set("var 6",430, -1000, 1000));
	gui.add(frame.set("framerate", 60, 1, 60));
	gui.add(seca.set("sec loop", 11, 1, 61));
	gui.add(mina.set("min loop", 2, 1, 61));
	gui.add(ha.set("h loop", 2, 1, 61));

	secfont.load("HelveticaBlkHollow.ttf", 50);
	minfont.load("HelveticaBlkHollow.ttf", 220);
	hfont.load("HelveticaBlkHollow.ttf", 320);
	*/

	ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(frame);
	sec = ofGetSeconds();
	h = ofGetHours();
	min = ofGetMinutes();

	secstring = ofToString(sec);
	hstring = ofToString(h);
	minstring = ofToString(min);

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (isSavingPDF) {
		ofBeginSaveScreenAsPDF("savedScreenshot_" + ofGetTimestampString() + ".pdf");
	}

	ofNoFill();
	float time = ofGetElapsedTimef();

	float angle = 0;
	angle = time*vel;
	float wave = sin(angle);

	//Sec
	ofPushMatrix();
	ofTranslate(-var2, -var2);
	for (int i = 1; i < seca; i++) {
		float width = ofGetWidth();
		float height = ofGetHeight();
		float posX = i * positionX;
		float posY = i * positionY;

		ofSetColor(255, 255, 255, vel);

		float x = width * var*ofNoise(time*speed + posX);
		float y = height *var*ofNoise(time*speed + posY);
		secfont.drawString(secstring, x, y);
	}
	ofPopMatrix();


	//Min
	ofPushMatrix();
	ofTranslate(-var4, -var4);
	ofTranslate(-100, 400);
	for (int j = 1; j < mina; j++) {
		float width = ofGetWidth();
		float height = ofGetHeight();
		float posX2 = j * positionX2;
		float posY2 = j * positionY2;

		ofSetColor(255, 255, 255, vel2);

		float x = width *  var3*ofNoise(time*speed2 + posX2);
		float y = height * var3*ofNoise(time*speed2 + posY2);
		minfont.drawString(minstring, x, y);
	}
	ofPopMatrix();

	//H
	ofPushMatrix();
	ofTranslate(-var6, -var6);
	ofTranslate(0, 100);
	for (int k = 1; k < ha; k++) {
		float width = ofGetWidth();
		float height = ofGetHeight();
		float posX3 = k * positionX3;
		float posY3 = k * positionY3;

		ofSetColor(255, 255, 255, vel3);

		float x = width * var5*ofNoise(time*speed3 + posX3);
		ofLog() << ofNoise(time*speed3 + posX3);
		float y = height * var5*ofNoise(time*speed3+ posY3);
		hfont.drawString(hstring, x, y);
	}
	ofPopMatrix();






	if (sec % act == 0) {
		ofSetBackgroundAuto(true);
	}
	else {
		ofSetBackgroundAuto(false);
	}

	if (isSavingPDF) {
		ofEndSaveScreenAsPDF();
		isSavingPDF = false;
	}

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 's') {
		isSavingPDF = true;
	}

	if (key == 's') {
		glReadBuffer(GL_FRONT);
		ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
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
