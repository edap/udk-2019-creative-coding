#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y );

    //this holds all of our points
    vector<glm::vec3> points;
    //this keeps track of the center of all the points
    glm::vec3 center;

    //our camera objects for looking at the scene from multiple perspectives
    ofCamera camera;

    //if usecamera is true, we'll turn on the camera view
    bool usecamera = false;
		
};
