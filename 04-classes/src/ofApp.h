#pragma once

#include "ofMain.h"

// Read this https://openframeworks.cc/ofBook/chapters/OOPs!.html
// Watch this https://www.youtube.com/watch?v=okpIBrT7A70
class Ball {
public:
    Ball(){};
    ofColor circleColor = ofColor(100,200,10);
    glm::vec2 position = glm::vec2(0, 0);


    void update(glm::vec2 target){
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

    void draw(){
        ofPushStyle();
        ofSetColor(circleColor);
        ofDrawCircle(position, 10);
        ofPopStyle();
    }

    void setup(){

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

    Ball ball;

};
