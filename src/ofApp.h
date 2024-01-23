// ofApp.h

#pragma once

#include "ofMain.h"
#include "ofxGui.h"  // ofxGui kütüphanesi eklenmeli
#include "particle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y);

    ofxPanel gui;
    ofxFloatSlider overallSpeed;
    ofxFloatSlider noiseAmount;
    ofxFloatSlider trail;

    const int numParticles = 500;
    vector<Particle> particles;
};
