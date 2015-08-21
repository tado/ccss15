#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(24);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnableDepthTest();
    float speed = 5;
    for (int i = 0; i < num; i++){
        position[i].x = ofRandom(ofGetWidth());
        position[i].y = ofRandom(ofGetHeight());
        position[i].z = ofRandom(ofGetHeight());
        velocity[i].x = ofRandom(-speed, speed);
        velocity[i].y = ofRandom(-speed, speed);
        velocity[i].z = ofRandom(-speed, speed);
        color[i].r = ofRandom(255);
        color[i].g = ofRandom(255);
        color[i].b = ofRandom(255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < num; i++) {
        position[i] += velocity[i];
        if (position[i].x < 0 || position[i].x > ofGetWidth()) {
            velocity[i].x *= -1;
        }
        if (position[i].y < 0 || position[i].y > ofGetHeight()) {
            velocity[i].y *= -1;
        }
        if (position[i].z < 0 || position[i].z > ofGetHeight()) {
            velocity[i].z *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < num; i++) {
        ofSetColor(color[i]);
        ofCircle(position[i].x, position[i].y, position[i].z, 8);
    }
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
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
