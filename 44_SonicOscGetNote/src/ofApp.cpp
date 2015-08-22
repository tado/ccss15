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
            // メッセージをパース、ノート番号だけをとりだし
            string needle = "note: ";
            const size_t step = needle.size();
            
            size_t count(0);
            size_t pos(0) ;
            string msg = m.getArgAsString(0);
            string noteStr;
            int noteNum;
            
            if( (pos = msg.find(needle)) != std::string::npos) {
                noteStr = msg.substr(pos + step, 2);
                noteNum = atoi(noteStr.c_str());
            }
            
            // とりだしたノート番号を表示
            cout << noteStr << endl;
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
