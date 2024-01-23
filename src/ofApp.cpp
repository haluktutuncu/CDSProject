// ofApp.cpp

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    gui.setup();
    gui.add(overallSpeed.setup("Overall Speed", 1, 0, 3));
    gui.add(noiseAmount.setup("Noise Amount", 1, 0, 3));
    gui.add(trail.setup("Trail", 6.0, 0, 20));

    for (int i = 0; i < numParticles; i++) {
        Particle p;
        p.setup();
        particles.push_back(p);
    }

    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update(overallSpeed, noiseAmount);
    }
}
//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(0, 0, 0, trail);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    // Çizgi kalınlığını belirle
    ofSetLineWidth(4.0);

    // Pürüzsüzlük (smoothing) özelliğini etkinleştir
    ofEnableSmoothing();
    

    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }

    // Pürüzsüzlüğü devre dışı bırak


    gui.draw();
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    ofVec2f mousePos(x, y);

    for (int i = 0; i < particles.size(); i++) {
        float distToMouse = ofDist(mousePos.x, mousePos.y, particles[i].pos.x, particles[i].pos.y);

        if (distToMouse < 50) {
            particles[i].color = ofColor(255, 0, 0);
        } else {
            particles[i].color = ofColor(ofRandom(0, 20), ofRandom(40, 100), ofRandom(50, 90), 255);
        }

        ofVec2f dir = mousePos - particles[i].pos;
        dir.normalize();
        particles[i].frc += dir * 0.1;
    }
}
