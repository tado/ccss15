#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    sound.loadSound("jdee_beat.mp3");
    sound.setLoop(true);
    sound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float nBand = powf(2.0, 12.0);
    float *buffer = ofSoundGetSpectrum(nBand);
    ofNoFill();
    ofSetLineWidth(2.0);
    ofSetColor(255);
    ofBeginShape();
    for (int i = 0; i < nBand; i++) {
        float x = ofMap(i, 0, nBand -  1, 0, ofGetWidth());
        float y = ofMap(buffer[i], 0, 1.0, ofGetHeight(), 0);
        ofVertex(x, y);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
