#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

   
   
    
   
    
    gui.setup();
    gui.add(overallSpeed.setup("speed", 1, 0, 3));
    gui.add(noiseAmount.setup("noise", 1, 0, 3));
    gui.add(trail.setup("trail", 6.0, 0, 20));
    gui.add(bLearnBackground.setup("capture bg", false));


    p.assign(1500, particle());

    for (int i = 0; i < p.size(); i++)
    {
        p[i].setup();
    }

    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetFrameRate(120);

    bool bNewFrame = false;
    
  

    //vidPlayer.update();
    //bNewFrame = vidPlayer.isFrameNew();

    if (bNewFrame == true)
    {
        //colorImg.setFromPixels(vidPlayer.getPixels());
        colorImg.setFromPixels(cam.getPixels());
        grayImg = colorImg;

        if (bLearnBackground == true)
        {
            grayBg = grayImg;
            bLearnBackground = false;
        }

        grayDiff.absDiff(grayBg, grayImg);
        grayDiff.threshold(threshold);

     
    }

    vector<ofVec2f>blobPts;
    for (int i = 0; i < contourFinder.nBlobs; i++)
    {
        for (int j = 0; j < contourFinder.blobs[i].pts.size(); j++)
        {
            blobPts.push_back(contourFinder.blobs[i].pts[j] * ofGetWidth());
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
       
        p[i].update(overallSpeed, noiseAmount);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){


    ofSetColor(0, 0, 0, trail);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    ofSetColor(ofRandom(70, 120),ofRandom(70, 70),ofRandom(70, 120), 255);


    for (int i = 0; i < p.size(); i++)
    {
        p[i].draw(1, p);

    }


    ofFill();
    ofSetHexColor(0x333333);
    //ofDrawRectangle(360, 540, 320, 240);
    ofSetHexColor(0xffffff);

    gui.draw();

}
