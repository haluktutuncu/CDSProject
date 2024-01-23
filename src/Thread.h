#pragma once

#include "ofMain.h"

class Thread {
public:
    Thread(ofColor initialColor);
    ~Thread();

    void update();
    void draw() const; // const ekleyin

private:
    ofVec2f pos;
    float speed;
    float threadLength;
    ofColor color;
    ofVec2f greyPos;
    float colorChangeThreshold;
};
