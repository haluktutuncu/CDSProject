#include "Thread.h"

Thread::Thread(ofColor initialColor) {
    pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    speed = ofRandom(1, 5);
    threadLength = ofRandom(20, 50);
    color = initialColor;
    greyPos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    colorChangeThreshold = ofRandom(50, 200);
}

Thread::~Thread() {
    // Destructor implementasyonu (varsa)
}

void Thread::update() {
    pos.x += speed;
    if (pos.x > ofGetWidth()) {
        pos.x = 0;
    }

    if (color != ofColor(127)) {
        float distanceToGrey = pos.distance(greyPos);
        if (distanceToGrey < colorChangeThreshold) {
            float ratio = distanceToGrey / colorChangeThreshold;
            color.lerp(ofColor(127), ratio);
        }
    }
}

void Thread::draw() {
    ofSetColor(color);
    ofDrawLine(pos.x, pos.y, pos.x + threadLength, pos.y);
}
