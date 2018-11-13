#pragma once

#include "ofMain.h"


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

    glm::vec2 position = glm::vec2(0, 0);
    glm::vec2 target = glm::vec2(0, 0);
    ofColor circleColor = ofColor(100,200,10);
    ofColor firstBgColor = ofColor();
    ofColor secondBgColor = ofColor();

};
