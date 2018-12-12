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
		ofxPanel gui;

		bool isSavingPDF; //PDF
		bool oneShot; //PDF
		bool pdfRendering; //PDF

		ofParameter<float> var;
		ofParameter<float> var2;
		ofParameter<float> var3;
		ofParameter<float> var4;
		ofParameter<float> var5;
		ofParameter<float> var6;
		ofParameter<int> seca;
		ofParameter<int> mina;
		ofParameter<int>ha;
		ofParameter<int>stunde;
		ofParameter<int>minute;
		ofParameter<int>sekunde;


		ofParameter<float> positionX;
		ofParameter<float> positionY;
		ofParameter<float> positionX2;
		ofParameter<float> positionY2;
		ofParameter<float> positionX3;
		ofParameter<float> positionY3;
		ofParameter<float> speed;
		ofParameter<float> speed2;
		ofParameter<float> speed3;

		ofParameter<float> vel;
		ofParameter<float> vel2;
		ofParameter<float> vel3;

		ofParameter<int> act;
		ofParameter<int> frame;



		ofTrueTypeFont secfont;
		ofTrueTypeFont minfont;
		ofTrueTypeFont hfont;

		int min;
		int sec;
		int h;


		string minstring;
		string secstring;
		string hstring;

		
		
};
