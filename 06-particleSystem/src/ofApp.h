#pragma once

#include "ofMain.h"
// reference, spiega che questo esercizio viene dagli esempi
// 1 Aggiungi il methodo reset
// muovi fall() into update
// introduci enum, passalo come argomento per update
// salto indietro alla posizione che cambia con la velocity
// aggiungi l'attraction
// aggiungi repel, soffermati sul cambio di direzione rispetto a attract
// spiega signed noise, e perche' unique Val
// Fai vedere cosa succede se usi repel, le particelle escono dallo schermo
// tienile nello schermo
// Aggiungi la trail. Come farebbero loro?

// NEW
enum particleMode{
    PARTICLE_MODE_ATTRACT = 0,
    PARTICLE_MODE_REPEL,
    PARTICLE_MODE_FALL
};

class Snowflake{
public:
    Snowflake(){};

    //Properties
    glm::vec2 position;

    // NEW
    glm::vec2 velocity;
    glm::vec2 force;
    float drag;
    float uniqueVal;
    vector<glm::vec2> trails;

    float radius;
    ofColor color;

    //Methods
    void fall(){
        position.y+= 0.5;
        if(position.y >= ofGetHeight()){
            position.y = 0;
            position.x = ofRandom(ofGetWidth());
        }
    }

    //NEW
    void attract(){
        glm::vec2 attractPt(ofGetMouseX(), ofGetMouseY());
        force = attractPt-position; // we get the attraction force/vector by looking at the mouse pos relative to our pos
        force = glm::normalize(force); //by normalizing we disregard how close the particle is to the attraction point

        velocity *= drag; //apply drag
        velocity += force * 0.6; //apply force
        position += velocity;
    }

    //NEW
    void repel(){
        glm::vec2 repelPt(ofGetMouseX(), ofGetMouseY());
        force = position-repelPt;//notice the force is negative

        //let get the distance and only repel points close to the mouse
        float dist = glm::length(force);
        force = glm::normalize(force);

        velocity *= drag;
        if( dist < 150 ){
            velocity += force * 0.6;
        }else{
            //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
            force.x = ofSignedNoise(uniqueVal, position.y * 0.01, ofGetElapsedTimef()*0.2);
            force.y = ofSignedNoise(uniqueVal, position.x * 0.01, ofGetElapsedTimef()*0.2);
            velocity += force * 0.04;
        }
        position+=velocity;
    }

    //NEW
    void keepOnScreen(){
        if( position.x > ofGetWidth() ){
            position.x = ofGetWidth();
            velocity.x *= -1.0;
        }else if( position.x < 0 ){
            position.x = 0;
            velocity.x *= -1.0;
        }
        if( position.y > ofGetHeight() ){
            position.y = ofGetHeight();
            velocity.y *= -1.0;
        }
        else if( position.y < 0 ){
            position.y = 0;
            velocity.y *= -1.0;
        }
    }

    void changeRadius(){
        radius = ofMap(position.y, 0,ofGetHeight(), 10, 50);
    }

    void draw(bool trail = false){
        ofPushStyle();
        ofSetColor(color);
        ofDrawCircle(position.x, position.y, radius);
        ofPopStyle();

        if (trail) {
            int i = 0;
            for(auto t:trails){
                ofPushStyle();
                //color.a = 255 -i*20; mess around with alpha
                ofSetColor(color);
                ofDrawCircle(t.x, t.y, radius + i*2);
                ofPopStyle();
                i++;
            }
        }
    }

    //NEW
    void update(particleMode mode){
        //1 - APPLY THE FORCES BASED ON WHICH MODE WE ARE IN

        if( mode == PARTICLE_MODE_ATTRACT ){
            attract();
        }else if(mode == PARTICLE_MODE_FALL){
            fall();
        }else if(mode == PARTICLE_MODE_REPEL){
            repel();
            keepOnScreen();
        }
        else{
            //DEFAULT BEHAVIOUR
            fall();
        }

        // update the trail
        trails.push_back(position);
        if(trails.size() > 10){
            trails.erase(trails.begin());
        }

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

    vector<Snowflake> points;

    //NEW
    particleMode mode;
    bool drawTrail = false;
    void setMode(particleMode newMode);
    void reset();
    int nParticles = 200;
		
};

