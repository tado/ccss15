#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	receiver.setup(3333);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
    // 画面をフェード
    ofSetColor(0, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    // バッファーされたOSCメッセージを処理
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if(m.getAddress() == "/message"){
            // メッセージを取得したらランダムな場所に円を描く
            ofSetColor(ofColor::fromHsb(ofRandom(255), 127, 255, 200));
            ofCircle(ofRandom(ofGetWidth()), ofRandom(ofGetWidth()), 100);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
