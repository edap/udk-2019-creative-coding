/**
 * Porting og the example "CameraRibbonExample" to GLM.
 * OFDevCon Example Code Sprint
 * Camera Ribbon example
 * This example generates ribbons along the mouse trail that descend in space
 * When you click space bar, you can
 *
 * Created by James George for openFrameworks workshop at Waves Festival Vienna sponsored by Lichterloh and Pratersauna
 * Adapted during ofDevCon on 2/23/2012
 */


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    //don't move the points if we are using the camera
    if(!usecamera){
        glm::vec3 sumOfAllPoints(0,0,0);
        for(unsigned int i = 0; i < points.size(); i++){
            points[i].z -= 4;
            sumOfAllPoints += points[i];
        }
        center = sumOfAllPoints / points.size();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //if we're using the camera, start it.
    //everything that you draw between begin()/end() shows up from the view of the camera
    if(usecamera){
        camera.begin();
    }

    ofSetColor(0);
    //do the same thing from the first example...
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(unsigned int i = 1; i < points.size(); i++){

        //find this point and the next point
        glm::vec3 thisPoint = points[i-1];
        glm::vec3 nextPoint = points[i];

        //get the direction from one to the next.
        //the ribbon should fan out from this direction
        glm::vec3 direction = (nextPoint - thisPoint);

        //get the distance from one point to the next
        float distance = direction.length();

        //get the normalized direction. normalized vectors always have a length of one
        //and are really useful for representing directions as opposed to something with length
        glm::vec3 unitDirection = glm::normalize(direction);

        //find both directions to the left and to the right
        glm::quat leftRotation = glm::angleAxis(-90.0f, glm::vec3(0.0f,0.0f,1.0f));
        glm::quat rightRotation = glm::angleAxis(+90.0f, glm::vec3(0.0f,0.0f,1.0f));
        // apply the rotations to the points
        glm::vec3 toTheLeft = leftRotation * unitDirection;
        glm::vec3 toTheRight = rightRotation * unitDirection;

        //use the map function to determine the distance.
        //the longer the distance, the narrower the line.
        //this makes it look a bit like brush strokes
        float thickness = ofMap(distance, 0, 60, 20, 2, true);

        //calculate the points to the left and to the right
        //by extending the current point in the direction of left/right by the length
        glm::vec3 leftPoint = thisPoint+toTheLeft*thickness;
        glm::vec3 rightPoint = thisPoint+toTheRight*thickness;

        //add these points to the triangle strip
        mesh.addVertex(glm::vec3(leftPoint.x, leftPoint.y, leftPoint.z));
        mesh.addVertex(glm::vec3(rightPoint.x, rightPoint.y, rightPoint.z));
    }

    //end the shape
    mesh.draw();


    //if we're using the camera, take it away
    if(usecamera){
        camera.end();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //hitting any key swaps the camera view
    usecamera = !usecamera;
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //if we are using the camera, the mouse moving should rotate it around the whole sculpture
    if(usecamera){
        float rotateAmount = ofMap(ofGetMouseX(), 0, ofGetWidth(), -2, 2);
        glm::vec3 furthestPoint;
        if (points.size() > 0) {
            furthestPoint = points[0];
        } else {
            furthestPoint = glm::vec3(x, y, 0);
        }

        glm::vec3 directionToFurthestPoint = furthestPoint - center;
        glm::quat yRotation = glm::angleAxis(rotateAmount, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::vec3 directionToFurthestPointRotated = yRotation * directionToFurthestPoint;
        camera.setPosition(center + directionToFurthestPointRotated);
        camera.lookAt(center);
    }
    //otherwise add points like before
    else{
        glm::vec3 mousePoint(x,y,0);
        points.push_back(mousePoint);
    }
}

