// particle.cpp

#include "particle.h"


void Particle::setup() {
    pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
    vel = ofVec2f(ofRandom(-4, 4), ofRandom(-4, 4));
    frc = ofVec2f(0, 0);
    prevVel = vel;  // prevVel'i buraya ekle
    size = ofRandom(1, 2);
    drag = ofRandom(0.97, 0.99);
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 120), 1);
    uniqueVal = ofVec2f(ofRandom(-500, 1000), ofRandom(-500, 1200));
}

void Particle::update(float overallSpeed, float noiseAmount) {
    frc.x = ofSignedNoise(uniqueVal.x, ofGetElapsedTimeMillis()) * overallSpeed;
    frc.y = ofSignedNoise(uniqueVal.y, ofGetElapsedTimeMillis()) * overallSpeed;

    frc /= noiseAmount;

    vel *= drag;
    vel += frc;

    pos += vel;

    if (pos.x > ofGetWidth()) pos.x = 0;
    else if (pos.x < 0) pos.x = ofGetWidth();

    if (pos.y > ofGetHeight()) pos.y = 0;
    else if (pos.y < 0) pos.y = ofGetHeight();
}
void Particle::draw() {
    ofSetColor(color);
    ofDrawCircle(pos, size);

    ofVec2f center(ofGetWidth() / 2, ofGetHeight() / 2);
    float dist = pos.distance(center);

    if (dist < 150) {
        ofSetColor(255, 0, 0);
        ofDrawLine(pos.x, pos.y, center.x, center.y);
    }
}
