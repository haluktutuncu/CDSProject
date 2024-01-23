// particle.h

#pragma once
#include "ofMain.h"

class Particle {
public:
    void setup();
    void update(float overallSpeed, float noiseAmount);
    void draw();
    void applyForce(const ofVec2f& force);

    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f prevVel;  // prevVel'i buraya ekle
    float drag;
    float size;
    ofColor color;
    ofVec2f uniqueVal;
};
