#pragma once

#include "ofMain.h"

class Circle {
public:
    Circle(){};
    // what happen if each circle has a different color
    ofColor circleColor = ofColor(100,200,10);
    glm::vec2 position = glm::vec2(0, 0);


    void update(glm::vec2 target){
        // move the circle slowly to the target position
        if (glm::distance(position, target) > ofRandom(0,200)) {
            auto direction = glm::normalize(target - position);
            auto velocity = direction; // for now, let's say that the velocity change like the direction.

            auto rate = glm::distance(target, position) * 0.01; // what if you change the 0.01 value?
            // add a new force. What happens if you change the * 20 to something higher? and what if something lower?
            auto wavyForce = glm::vec2(sin(position.y * 0.2), cos(position.x * 0.2)) * 10;
            auto acceleration = wavyForce + direction * rate;
            velocity += acceleration;
            position += velocity;

        }
    }

    void draw(){
        ofPushStyle();
        ofSetColor(circleColor);
        ofDrawCircle(position, 10);
        ofPopStyle();
    }
};


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    glm::vec2 target = glm::vec2(0, 0);

    ofColor firstBgColor = ofColor();
    ofColor secondBgColor = ofColor();

    vector<Circle> circles;

};
