#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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

    ofEasyCam cam;
    ofLight light;
    ofMaterial material;

    ofNode firstNode;
    ofNode secondNode;
    ofNode thirdNode;
    ofNode fourthNode;

    ofPolyline line;
    ofxPanel gui;
    ofParameter<int> maxPoints = {"max", 7000, 10, 10000};

    ofParameter<float> firstNodePan = {"firstNodePan", 1.0, 0.1, 2.};
    ofParameter<float> secondNodeRoll = {"secondNodeRoll", -1.6, -3., 3.};

    ofParameter<int> circleRes = {"circleRes", 30, 3, 60};

    ofParameter<bool> applyResampling = {"applyResampling", false};
    ofParameter<float> smoothVal = {"smoothResampling", 20, 20, 100};

    ofParameter<bool> scaleRadius = {"scaleRadius", false};
    ofParameter<float> scaleFactor = {"scaleFactor", 50, 10, 160};

    ofParameter<bool> drawMesh = {"drawMesh", false};

    ofVboMesh mesh;


};
