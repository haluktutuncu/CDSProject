#include "particle.h"

particle::particle(){
    
}

void particle::setup(){
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    vel.x = ofRandom(-4,4);
    vel.y = ofRandom(-4,4);
    
    frc = ofVec2f(0,0);
    
    uniqueVal.x = ofRandom(-1000,1000);
    uniqueVal.y = ofRandom(-1000,1000);
    
    size = ofRandom(3,5);
    
    drag = ofRandom(0.97,0.99);
    
    
}
void particle::update(float speed,float noise){
    frc.x = ofSignedNoise(uniqueVal.x,ofGetElapsedTimeMillis());
    frc.y = ofSignedNoise(uniqueVal.y,ofGetElapsedTimeMillis());
    
    frc*=noise;
    
    vel *= drag;
    
    vel+= frc;
    
    
    
    //Reset atborder
    
    if(pos.x + vel.x > ofGetWidth()){
        pos.x -=ofGetWidth();
        
    }
    else if(pos.x + vel.x < 0){
        pos.x +=ofGetWidth();
    }
    
    if(pos.y + vel.y > ofGetHeight()){
        pos.y -=ofGetHeight();
        
    }
    else if(pos.y + vel.y < 0){
        pos.y +=ofGetHeight();
    }
    
    pos += vel*speed;

}

void particle::draw(float sizeDot){
    ofDrawCircle(pos.x,pos.y,size*sizeDot);
};
