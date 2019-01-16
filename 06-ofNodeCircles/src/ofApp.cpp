#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Read this https://openframeworks.cc/ofBook/chapters/generativemesh.html
    // And try to change the primitive mode.
    //mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    gui.setup();
    gui.add(maxPoints);
    gui.add(firstNodePan);
    gui.add(secondNodeRoll);
    gui.add(circleRes);
    gui.add(applyResampling);
    gui.add(smoothVal);
    gui.add(scaleRadius);
    gui.add(scaleFactor);
    gui.add(drawMesh);

    light.setup();
    light.setPosition(180, 200, 100);
    light.lookAt(glm::vec3(0,0,0));
    light.enable();

    material.setAmbientColor(ofFloatColor::red);
    material.setSpecularColor(ofFloatColor::blue);
    material.setDiffuseColor(ofFloatColor::yellow);
    material.setShininess(10);

    firstNode.setPosition(0, 0, 0);
    secondNode.setParent(firstNode);
    secondNode.setPosition(0, 0, 300);

    thirdNode.setParent(secondNode);
    thirdNode.setPosition(0, 0, 0);

    fourthNode.setParent(thirdNode);
    fourthNode.setPosition(0,180,0);

    ofSetBackgroundColor(ofFloatColor::coral);
}

//--------------------------------------------------------------
void ofApp::update(){
    //TODO Add a ofParameter<glm::vec3> lightPos to change the
    // position of the light;
    // Use light.draw() to debug where it is.
    firstNode.panDeg(firstNodePan);
    secondNode.rollDeg(secondNodeRoll);

    if (scaleRadius) {
        float val = ofNoise(ofGetElapsedTimef()) * scaleFactor;
        fourthNode.setPosition(0,20+val,0);
    }

    for(int i = 0; i < circleRes; i++){
        thirdNode.tiltDeg(360/circleRes);
        line.addVertex(fourthNode.getGlobalPosition());

        if(drawMesh){
            mesh.addVertex(fourthNode.getGlobalPosition());
            //what if you add a random color?
            // what if the color is based on the rotation
            // degrees?
            //mesh.addColor(ofFloatColor(?,?,?));
            auto surfaceDirection = glm::normalize(
                                                   fourthNode.getGlobalPosition() -
                                                   thirdNode.getGlobalPosition()
                                                   );
            mesh.addNormal(surfaceDirection);
            if (line.size() > maxPoints){
                mesh.getVertices().erase(
                    mesh.getVertices().begin()
                );
            }
        }

        if (line.size() > maxPoints){
            line.getVertices().erase(
                line.getVertices().begin()
            );
        }
    };

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    //uncomment these 3 lines to understand how nodes are moving
//    firstNode.draw();
//    secondNode.draw();
//    thirdNode.draw();
//    fourthNode.draw();

    //light.draw();
    material.begin();

    if (drawMesh) {
        mesh.draw();
    } else {
        if (applyResampling) {
            line.getResampledBySpacing(smoothVal).draw();
        } else {
            line.draw();
        }
    }

    material.end();
    
    cam.end();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='c'){
        line.clear();
        mesh.clear();
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
